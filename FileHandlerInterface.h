#include <iostream>
#include <fstream>
#include <vector>

class FileHandlerInterface{
	private:
		std::fstream currentFile;
	public:
		//store the fileBuf for the file into private
		//member buffer
		virtual void storeFileInfo(std::string name);


		//virtual std::fstream * createFile();

		//virtual void writeBufToFile();
		
		//virtual void closeFile();

};

