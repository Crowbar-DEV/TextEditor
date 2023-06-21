#include "Application.cpp"
#include "FileHandler.cpp"
#include "State.cpp"
#include "UI.cpp"

int main(){

	
	Application* application = new Application(new FileHandler());


	////////// TEST AREA //////////
	std::fstream file;

	char buf[1024];

	file.rdbuf()->pubsetbuf(buf, sizeof(buf));
	file.open("test.txt");

	char c;
	file.get(c);

	std::cout << c;
	////////// TEST AREA //////////
	return 0;
}
