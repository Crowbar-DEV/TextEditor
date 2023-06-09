#ifndef FileHandler_H
#define FileHandler_H

class FileHandler{
	private:
		char * buffer;
		fstream file;
	public:
		openFile();
		closeFile();
		createFile();
		writeBufToFile();

}
