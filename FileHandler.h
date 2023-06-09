#include <iostream>
#include <fstream>
#include <vector>

#ifndef FileHandler_H
#define FileHandler_H

class FileHandler{
	private:
		std::vector<char> buffer;
		std::fstream file;
	public:
		//when we open a file, we want the contents
		//of the file, so we return a vec
		virtual std::vector<char> openFile();
		virtual std::fstream * createFile();

		virtual void writeBufToFile();
		virtual void closeFile();

};

#endif
