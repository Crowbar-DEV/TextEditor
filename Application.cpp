#include "FileHandlerInterface.h"
#include "StateInterface.h"
#include "UIInterface.h"

class Application {
	private:
		StateInterface* state;
		FileHandlerInterface* fileHandler;
		UIInterface* ui;
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

		}

		// Runs the main loop of the program
		void runLoop() {
		}

};
