#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <curses.h>

using namespace std;

typedef enum EDITOR_MODE{
    INSERT,
    VIEW
}EDITOR_MODE;

class Editor
{
    private:

    public:

        EDITOR_MODE         mode;

        string              content = "";
        vector<string>      lines;

        WINDOW *            window;

        bool                shouldExit = false;

        int                 curRow, curCol;

        //constructor: store lines, and full file string
        Editor(ifstream & file){
            string s;
            while(getline(file, s)){
                this->lines.emplace_back(s);
                this->content += s + '\n';
            }
            this->curRow = 0;
            this->curCol = 0;
            //curses setup
            initscr();
            cbreak();
            noecho();
            keypad(stdscr,true);

            //print file content and move cursor to start
            printw(this->content.c_str());
            move(0,0);

        }

        void cursorMoveUp(){
            if(this->curRow != 0) this->curRow--;
            move(this->curRow, this->curCol);
        }
        void cursorMoveDown(){
            if(this->curRow < this->lines.size()) this->curRow++;
            move(this->curRow, this->curCol);
        }
        void cursorMoveRight(){
            this->curCol++;
            move(this->curRow, this->curCol);
        }
        void cursorMoveLeft(){
            this->curCol--;
            move(this->curRow, this->curCol);
        }


};

void loop(char c, Editor * e){
    c = getch();
    switch(c){
        case 'j':
            e->cursorMoveDown();
            break;
        case 'k':
            e->cursorMoveUp();
            break;
        case 'l':
            e->cursorMoveRight();
            break;
        case 'h':
            e->cursorMoveLeft();
            break;
        case 'q':
            e->shouldExit = true;
            break;
    }
    refresh();
}

int main()
{
    //setup editor object
    ifstream f("test.txt");
    Editor * e = new Editor(f);
    f.close();

    char c;
    //main event loop
    while(!e->shouldExit){
        loop(c, e);
    }

    endwin();
}