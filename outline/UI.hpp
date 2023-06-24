#include <ncurses.h>
//what does the UI need to 
//redraw?

//needs current cursor pos
//needs editor mode
//needs filename
//needs document

class UI {
    private:

        typedef struct element{
            std::string content;
            bool        top;        
            int         position;
        }borderElement;


        WINDOW *                borderWin;
        WINDOW *                textWin;
        borderElement           position;
        borderElement           mode;
        borderElement           file;

    public:
        UI();
        ~UI();

        void updateUI();
};
