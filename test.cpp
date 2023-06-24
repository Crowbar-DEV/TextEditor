#include <curses.h>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> content {"asdflkasjdf","asdlfkajsd"};

    initscr();
    cbreak();
    noecho();
    keypad(stdscr,true);
    refresh();

    int h = 0;

    while(1){
        printw(content[0].c_str());       
        move(0,h);
        refresh();
        int c = getch();
        switch(c){
            case 'h':
                h++;
        }
        erase();
    }
}