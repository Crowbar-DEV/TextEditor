#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include "Document.hpp"

//Constructor:
//sets file name and reads file into buffer
Document::Document(std::string fileName)
{
    this->name = fileName;
    readFile(fileName);
}

//Deconstructor:
//deletes the object
Document::~Document()
{
    delete this;
}

//readFile:
//params-> string fileName
//mutates-> this->buffer
//reads file fileName into buffer
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

//writeFile:
//params-> string fileName
//writes buffer to file fileName
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

//insertChar:
//params-> char c, int line, int column
//mutates-> this->buffer
//inserts a character at position column within the line
void Document::insertChar(char c, int line, int column)
{
    std::string temp(1,c);
    this->buffer[line].insert(column,temp);
}

//deleteChar:
//params-> int line, int column
//mutates-> this->buffer
//deletes a character at position column within the line
void Document::deleteChar(int line, int column)
{
    this->buffer[line].erase(column,1);
}

//getLineLength:
//params-> int line
//returns-> number of characters within a certain line
int Document::getLineLength(int line)
{
    return this->buffer[line].length();
}

//getLines:
//return-> number of lines within the document
int Document::getLines()
{
    return this->buffer.size();
}

