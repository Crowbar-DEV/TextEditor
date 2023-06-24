
#pragma once

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <curses.h>
#include <istream>
#include <iterator>
#include <sstream>
#include <string>
#include <ostream>
#include <unordered_map>

typedef enum EDITOR_MODE{
    INSERT,
    VIEW
}EDITOR_MODE;

class Editor{
    public:
        std::string                         fileName;
        EDITOR_MODE                         mode;
        std::string                         content = "";
        std::vector<std::string>            lines;
        int                                 totalLines = 0;
        WINDOW *                            borderWindow;
        WINDOW *                            textWindow;
        bool                                shouldExit = false;
        std::pair<int,int>                  cursorPos;

        Editor(std::string &name);
        ~Editor();

        std::unordered_map<int, std::string> modes;

        void moveCursorUp(); //
        void moveCursorDown(); //
        void moveCursorLeft();
        void moveCursorRight();

        const std::pair<int,int> getCursorPos(); //
        void setCursorPos(int line, int col); //

        void setMode(EDITOR_MODE mode);

        const int getLine(); //
        const int getCol(); //

        const int getLineChars();

        void syncBuffers(); //

        void insert(char c); //
        void deleteChar(); //
        void backspace(); //

        void updateUI();

        void writeFile(std::string &name); //
        void setupFile(std::string &name); //

        void cursesInit(); //

};