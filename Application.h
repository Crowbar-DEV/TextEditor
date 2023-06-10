#include "State.h"
#include "FileHandler.h"
#include "UI.h"

#ifndef Application_H
#define FileHandler_H

class Application {
	private:
		State state;
		FileHandler fileHandler;
		UI ui;
	public:
		Application(State state, FileHandler fileHandler, UI ui);
};

#endif
