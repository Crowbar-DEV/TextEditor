#include "Editor.hpp"
#include <curses.h>
#include <string>
#include <utility>

    //constructor: store lines, and full file string
    //set up curses as well
Editor::Editor(std::string &name)
{
    //load file into buffer, set initial values
    setupFile(name);
    this->mode = VIEW;

    this->cursesInit();
}

//EDITOR/APP//
void Editor::cursesInit()
{
    //curses setup
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,true);
    refresh();
    
    this->borderWindow = newwin(LINES, COLS, 0, 0);
    this->textWindow = subwin(this->borderWindow, LINES-2, COLS-2, 1, 1);
    //print file content and move cursor to start
    wrefresh(this->borderWindow);
    this->setCursorPos(0, 0);
    wprintw(this->textWindow,this->content.c_str());
    this->setCursorPos(0, 0);
    wrefresh(this->textWindow);
}

//CURSOR//
void Editor::moveCursorUp()
{
		if(this->getLine() > 0) {
			if(this->lines[this->getLine()-1].length() < this->getCol() && this->getLine() != 0){
        this->setCursorPos(this->getLine()-1,this->lines[this->getLine()-1].length());
    	}
    	else {
			 	this->setCursorPos(this->getLine() - 1, this->getCol());
			}
		}
}

//CURSOR//
void Editor::moveCursorDown()
{
		if(this->getLine() < this->totalLines-1) {
			if(this->lines[this->getLine()+1].length() < this->getCol()){
        this->setCursorPos(this->getLine()+1,this->lines[this->getLine()+1].length());
    	}
    	else {
				this->setCursorPos(this->getLine() + 1, this->getCol());
			}
		}
}

//CURSOR//
void Editor::moveCursorLeft()
{
    if(this->getCol() > 0) this->setCursorPos(this->getLine(), this->getCol() - 1);
}

//CURSOR//
void Editor::moveCursorRight()
{
    if(this->getCol() < this->getLineChars()) this->setCursorPos(this->getLine(), this->getCol() + 1);
}

//CURSOR//
const std::pair<int, int> Editor::getCursorPos()
{
    return this->cursorPos;
}

//CURSOR//
void Editor::setCursorPos(int line, int col)
{
    this->cursorPos.first = line;
    this->cursorPos.second = col;
    wmove(this->textWindow,line,col);
}

//EDITOR//
void Editor::setMode(EDITOR_MODE mode)
{
    this->mode = mode;
}

//CURSOR//
const int Editor::getLine()
{
    return this->cursorPos.first;
}

//CURSOR//
const int Editor::getCol()
{
    return this->cursorPos.second;
}

//DOCUMENT//
const int Editor::getLineChars()
{
    return this->lines[getLine()].length();
}

//EDITOR//
void Editor::syncBuffers()
{
    std::string content = "";
    for(std::string s : this->lines)
    {
        content += s.append("\n");
    }
    this->content = content;
}

//EDITOR//
void Editor::insert(char c)
{
    std::string s = "";
    s.push_back(c);
    this->lines[this->getLine()].insert(this->getCol(),s);
    winsch(this->textWindow,c);
    this->setCursorPos(this->getLine(), this->getCol()+1);
}

//EDITOR//
void Editor::deleteChar()
{
    if(this->lines[this->getLine()].length() > 0){
        this->lines[this->getLine()].erase(this->getCol(),1);
        wdelch(this->textWindow);
    }
}

//EDITOR//
void Editor::backspace()
{
    if(this->getCol() != 0 || this->lines[this->getLine()].length() > 0){
        this->setCursorPos(this->getLine(), this->getCol()-1);
        this->lines[this->getLine()].erase(this->getCol(),1);
        wdelch(this->textWindow);
    }
}

//DOCUMENT//
void Editor::setupFile(std::string &name)
{
    this->fileName = name;
    std::fstream file(name);

    //read full content
    this->content = std::string(
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    );

    //read lines
    file.seekg(0);
    std::string s;
    while(std::getline(file,s)){
        this->lines.emplace_back(s);
        this->totalLines++;
    }

    file.close();
}

//DOCUMENT//
void Editor::writeFile(std::string &name)
{
    this->syncBuffers();

    std::ofstream file;
    file.open(name,std::ios::trunc);
    std::istringstream content(this->content);

    file << content.rdbuf();
    file.close();
}

//UI//
void Editor::updateUI()
{
    box(this->borderWindow,0,0);
    mvwaddstr(this->borderWindow, LINES-1, COLS-10, std::string("|").append(this->modes[this->mode]).append("|").c_str());
    wmove(this->borderWindow,0,1);
    std::string top = "";
    top.push_back('|');
    top.append(this->fileName);
    top.push_back('|');
    wprintw(this->borderWindow, top.c_str());
    mvwaddstr(this->borderWindow, LINES-1, 2, std::string("|").append(std::to_string(this->getLine())).append(",").append(std::to_string(this->getCol())).append("|").c_str());
    wrefresh(this->borderWindow);
    wrefresh(this->textWindow);
}
