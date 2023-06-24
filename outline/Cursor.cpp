#include "Cursor.hpp"

const std::pair<int,int> Cursor::getCursorPos() {
	return this->cursorPos;
}

void Cursor::setCursorPos(int line, int col) {
	this->cursorPos.first = line;
	this->cursorPos.second = col;
}

const int Cursor::getLine() {
	return this->cursorPos.first;
}

const int Cursor::getCol() {
	return this->cursorPos.second;
}
