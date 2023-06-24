#include "Editor.cpp"
#include "Editor.hpp"
#include <curses.h>
#include <string>

std::string line = "";
std::string col = "";



void loop(int &c, Editor * e){
    e->updateUI();
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
                case 27:
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
                case KEY_BACKSPACE:
                    e->backspace();
                    break;
                case 27:
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
    //setup editor object
    std::string fileName = argv[1];
    Editor * e = new Editor(fileName);

    e->modes[EDITOR_MODE::INSERT] = "INSERT";
    e->modes[EDITOR_MODE::VIEW] = "VIEW";

    int c;
    //main event loop
    while(!e->shouldExit){
        loop(c, e);
    }

    endwin();

    e->writeFile(fileName);
    std::cout << e->content << std::endl;
}