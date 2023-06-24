#include "Editor.hpp"
class App{
    private:
        std::vector<Editor>   editors;
        std::vector<Editor>   RenderedEditors;

        Editor                focusedEditor;
    public:
        void run();
};