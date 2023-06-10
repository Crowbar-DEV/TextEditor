#include "FileHandlerInterface.h"
#include "StateInterface.h"
#include "UIInterface.h"

class Application {
	private:
		StateInterface* state;
		FileHandlerInterface* fileHandler;
		UIInterface* ui;
		std::filebuf * buffer;
	public:
		Application(FileHandlerInterface* fileHandler){
			this->fileHandler = fileHandler;
		}
		Application(StateInterface* state, FileHandlerInterface* fileHandler, UIInterface* ui) {
			this->state = state;
			this->fileHandler = fileHandler;
			this->ui = ui;
		}
		
		// Sets up the application
		void setup() {
			std::string fileName = "test.txt";
			std::filebuf * buffer;
			buffer = fileHandler->createBuffer(fileName);
			
			char c;
			c = buffer->sbumpc();
			while(c != EOF){
				
				c = buffer->sbumpc();
				std::cout<< c;
			} 
		}

		// Runs the main loop of the program
		void runLoop() {
		}

};
