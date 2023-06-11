build: Main.cpp
	g++ -g -Wall Main.cpp -o main

ncurses: noclasses.cpp
	g++ -g -Wall -lncurses noclasses.cpp -o main
