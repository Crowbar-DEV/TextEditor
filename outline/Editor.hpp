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
<<<<<<< HEAD

        int                     currentTermColumns=COLS;
        int                     currentTermHeight=LINES;
=======
				int currentDocIndex;
>>>>>>> 2906583f2c42307dfaad5eb420b869fefb75c542
    public:
        void setCurrentDoc();

        void loop();
        
				void moveCursorUp();
				void moveCursorDown();
				void moveCursorLeft();
				void moveCursorRight();
};
