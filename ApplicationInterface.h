#include "StateInterface.h"
#include "FileHandlerInterface.h"
#include "UIInterface.h"

#ifndef ApplicationInterface_H
#define ApplicationInterface_H

class ApplicationInterface {
	private:
		StateInterface state;
		FileHandlerInterface fileHandler;
		UIInterface ui;
	public:
		ApplicationInterface(StateInterface state, FileHandlerInterface fileHandler, UIInterface ui);
};

#endif
