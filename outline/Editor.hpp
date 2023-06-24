#include <cstdint>
#include <vector>
#include "Cursor.cpp"
#include "UI.cpp"
#include "Selection.cpp"
#include "Document.cpp"

class Editor{
    private:
        std::vector<Document>   documents;
        Cursor                  cursor;
        UI                      ui;
        Selection               selection;
    public:
        void setCurrentDoc();

        void update();
        
};
