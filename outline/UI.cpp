#include "UI.hpp"
#include <ncurses.h>

UI::UI()
{
    this->borderWin = newwin();
}