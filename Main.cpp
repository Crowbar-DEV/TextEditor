#include "FileHandler.h"
#include "State.h"
#include "Application.h"
#include <format>

int main(){
	std::fstream file ("test.txt");

	char arr[end];

	file.seekg(0);

	std::fstream buf;

	file>>arr;

	buf<<arr;
	
	file.close();
	char c;
	for(int i = 0; i< 50; i++){
		buf.get(c);
		std::cout<< c;
	}

	//std::cout<< file.tellg()<< "\n" ;
	//file.close();
	//std::fstream file ("test.txt");
	//std::filebuf * fileBuf = file.rdbuf();
	//std::filebuf * restoreBuf;
	//std::system("clear");
	//std::cout <<fileBuf;	
	//std::vector<char> mem;
	//char c = fileBuf->sbumpc();

	//while(c != EOF){
	//	mem.push_back(c);
	//	c = fileBuf->sbumpc();
	//}
	//file.close();
	//
	//for(char c : mem){
	//	std::cout<<c<<"\n";
	//}
	return 0;
}
