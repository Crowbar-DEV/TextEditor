#include <string>
#include <vector>
class Document{
    private:
        std::vector<std::string>        buffer;
    public:
        //read file into buffer
        void readFile(std::string fileName);
        //write buffer to file
        void writeFile(std::string fileName);

        void insertChar(char c, int line, int column);
        void deleteChar(int line, int column);

        void insertString(std::string s, int line, int column);
        void deleteString(int line, int column);
};