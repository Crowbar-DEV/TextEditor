#include "FileHandlerInterface.h"

class FileHandler : public FileHandlerInterface {
	private:
		std::fstream currentFile;
	public:
		void storeFileInfo(std::string name) {
			// TODO complete this
		}

};

//void FileHandler::storeFileInfo(std::string name){
	//currentFile = std::fstream("test.txt");
	//buffer = currentFile.rdbuf();
//}



