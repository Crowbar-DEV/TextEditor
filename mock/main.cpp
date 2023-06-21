#include "Editor.cpp"
#include <curses.h>

void loop(char &c, Editor * e){
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
    wrefresh(e->textWindow);
}

int main()
{
    //setup editor object
    std::string fileName = "test1.txt";
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