#include "FileHandlerInterface.h"
#include "StateInterface.h"
#include "Application.cpp"
#include "FileHandler.cpp"

int main(){
	std::fstream file;

	char buf[1024];

	file.rdbuf()->pubsetbuf(buf, sizeof(buf));
	file.open("test.txt");

	char c;
	file.get(c);

	std::cout << c;
	return 0;
}
