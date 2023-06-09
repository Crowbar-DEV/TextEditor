#include <stdlib.h>

#ifndef FileHandler_H
#define FileHandler_H

class FileHandler{
	private:
		std::vector<char> buffer;
		fstream file;
	public:
		openFile();
		closeFile();
		createFile();
		writeBufToFile();

}
