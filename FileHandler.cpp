#include "FileHandlerInterface.h"

class FileHandler : public FileHandlerInterface {
	private:
		std::fstream * currentFile;
	public:
		std::filebuf * createBuffer(std::string name) {
			//objective is to open a file, and return a pointer
			//to its buffer
			currentFile->open(name);
			std::filebuf * buffer = currentFile->rdbuf();
			return buffer;	

		}

};

//void FileHandler::storeFileInfo(std::string name){
	//currentFile = std::fstream("test.txt");
	//buffer = currentFile.rdbuf();
//}



