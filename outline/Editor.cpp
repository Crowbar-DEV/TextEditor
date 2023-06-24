#include "Editor.hpp"

void Editor::moveCursorUp() {
	int currentLine = Editor::cursor.getLine();
	if(currentLine > 0) {
		int aboveLineLength = Editor::documents[Editor::currentDocIndex].getLineLength(currentLine-1);

		// If the line that is being moved to is shorter that the current column position,
		// then move the cursor to the end of that line 
		if(aboveLineLength < Editor::cursor.getCol()) {
			Editor::cursor.setCursorPos(currentLine-1, aboveLineLength);
		}	
		// Otherwise just move the cursor up
		else {
			Editor::cursor.setCursorPos(currentLine-1,Editor::cursor.getCol());
		}
	}
}

void Editor::moveCursorDown() {
}

void Editor::moveCursorLeft() {
}

void Editor::moveCursorRight() {
}
