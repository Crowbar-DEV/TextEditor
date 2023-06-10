#include <fstream>
#include <iostream>

#ifndef StateInterface_H
#define StateInterface_H

enum Mode {INSERT,VIEW};

class StateInterface {
	private:
		Mode currentMode;
	
	protected:
		std::string timeStamp;
		bool upToDate;
		std::string file;
		std::fstream fileStream;
	
	public:
		State();
		virtual void setMode(Mode newMode);
		virtual Mode getMode();

};

#endif
