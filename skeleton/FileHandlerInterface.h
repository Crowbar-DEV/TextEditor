#include <iostream>
#include <fstream>
#include <vector>

#ifndef FILEHANDLERINTERFACE_H
#define FILEHANDLERINTERFACE_H

class FileHandlerInterface{
	private:
		std::fstream * currentFile;
	public:
		//store the fileBuf for the file into private
		//member buffer
		std::filebuf * createBuffer(std::string name);


		//virtual std::fstream * createFile();

		//virtual void writeBufToFile();
		
		//virtual void closeFile();

};

#endif

