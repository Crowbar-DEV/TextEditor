#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include "Document.hpp"

void Document::readFile(std::string fileName)
{
    std::ifstream file(fileName.c_str());

    std::vector<std::string> buf;
    std::string s;

    while(std::getline(file,s))
    {
        buf.emplace_back(s.append("\n"));
    }

    file.close();
    this->buffer = buf;
}

void Document::writeFile(std::string fileName)
{
    std::string s = "";

    for(std::string line : this->buffer){
        s.append(line);
    }

    std::istringstream content(s);
    std::ofstream file(fileName.c_str());

    file << content.rdbuf();
    file.close();
}

void Document::insertChar(char c, int line, int column)
{
    std::string temp(1,c);
    this->buffer[line].insert(column,temp);
}

void Document::deleteChar(int line, int column)
{
    this->buffer[line].erase(column,1);
}