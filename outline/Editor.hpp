#include <cstdint>
#include <vector>
#include "Document.hpp"
#include "Cursor.hpp"
#include "Selection.hpp"
#include "UI.hpp"

class Editor{
    private:
        std::vector<Document>   documents;
        Cursor                  cursor;
        UI                      ui;
        Selection               selection;
				int currentDocIndex;
    public:
        void setCurrentDoc();

        void loop();
        
				void moveCursorUp();
				void moveCursorDown();
				void moveCursorLeft();
				void moveCursorRight();
};
