#include "StateInterface.h"
#include "FileHandlerInterface.h"
#include "UIInterface.h"

#ifndef ApplicationInterface_H
#define ApplicationInterface_H

class ApplicationInterface {
	private:
		State state;
		FileHandler fileHandler;
		UI ui;
	public:
		Application(State state, FileHandler fileHandler, UI ui);
};

#endif
