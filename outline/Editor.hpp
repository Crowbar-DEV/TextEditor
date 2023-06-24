#include <cstdint>
#include <vector>

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