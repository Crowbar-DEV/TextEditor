#include "Editor.cpp"
#include "Editor.hpp"
#include <curses.h>
#include <string>
#include <unordered_map>

std::string line = "";
std::string col = "";

std::unordered_map<int, std::string> modes;


void loop(char &c, Editor * e){
    box(e->borderWindow,0,0);
    mvwaddstr(e->borderWindow, LINES-1, COLS-10, modes[e->mode].c_str());
    int center = COLS /2;
    wmove(e->borderWindow,0,1);
    std::string top = "";
    top.push_back('|');
    top.append(e->fileName);
    top.push_back('|');
    wprintw(e->borderWindow, top.c_str());
    line = std::to_string(e->getLine());
    col = std::to_string(e->getCol());
    mvwaddstr(e->borderWindow, LINES-1, 2, line.append(",").append(col).c_str());
    wrefresh(e->borderWindow);
    wrefresh(e->textWindow);
    c = getch();
    switch(e->mode){
        case VIEW:
            switch(c){
                case 'j':
                    e->moveCursorDown();
                    break;
                case 'k':
                    e->moveCursorUp();
                    break;
                case 'l':
                    e->moveCursorRight();
                    break;
                case 'h':
                    e->moveCursorLeft();
                    break;
                case 'q':
                    e->shouldExit = true;
                    break;
                case 'd':
                    e->deleteChar();
                    break;
                case 'i':
                    e->setMode(INSERT);
                    break;
                default:
                    break;
            }
            break;
        case INSERT:
            switch(c){
                case 'q':
                    e->setMode(VIEW);
                    break;
                default:
                    e->insert(c);
                    break;
            }
    }
}

int main(int argc, char** argv)
{
    modes[EDITOR_MODE::INSERT] = "INSERT";
    modes[EDITOR_MODE::VIEW] = "VIEW";
    //setup editor object
    std::string fileName = argv[1];
    Editor * e = new Editor(fileName);

    char c;
    //main event loop
    while(!e->shouldExit){
        loop(c, e);
    }

    endwin();

    e->writeFile(fileName);
    std::cout << e->content << std::endl;
}