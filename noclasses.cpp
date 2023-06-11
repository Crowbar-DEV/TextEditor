#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <ncurses.h>

struct editorData{
	std::ostringstream	fileContent;
};

std::ostringstream getFileContent(std::string fileName){
	std::ostringstream buf;
	std::ifstream input(fileName.c_str());
	buf << input.rdbuf();
	input.close();
	return buf;
}

int main(){
	struct editorData eContext;
	eContext.fileContent = getFileContent("test.txt");
	
	//ncurses shit
	initscr();
	raw();
	keypad(stdscr, TRUE);
	printw(eContext.fileContent.str().c_str());
	move(0,0);
	refresh();
	getch();
	endwin();
}

