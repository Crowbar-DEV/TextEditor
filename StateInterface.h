#include <fstream>
#include <iostream>

#ifndef StateInterface_H
#define StateInterface_H

enum Mode {INSERT,VIEW};

class StateInterface {
	private:
		Mode currentMode;
	
	protected:
		bool upToDate;
	
	public:
		StateInterface();
		virtual void setMode(Mode newMode);
		virtual Mode getMode();

};

#endif
