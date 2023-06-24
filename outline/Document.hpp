#include <string>
#include <vector>
class Document{
    private:
        std::string                     name;
        std::vector<std::string>        buffer;
    public:
        Document(std::string fileName);
        ~Document();
        //read file into buffer
        void readFile(std::string fileName);
        //write buffer to file
        void writeFile(std::string fileName);

        void insertChar(char c, int line, int column);
        void deleteChar(int line, int column);
        
        int getLineLength(int line);
        int getLines();

        void insertString(std::string s, int line, int column);
        void deleteString(int line, int column);
};