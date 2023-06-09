#include <iostream>
#include <fstream>
#include <vector>

#ifndef FileHandler_H
#define FileHandler_H
#endif

class FileHandler{
	private:
		std::vector<char> buffer;
		std::fstream file;
	public:
		//when we open a file, we want the contents
		//of the file, so we return a vec
		std::vector<char> openFile();
		std::fstream * createFile();

		void writeBufToFile();
		void closeFile();

};

