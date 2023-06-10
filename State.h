#include <fstream>
#include <iostream>

#ifndef State_H
#define State_H

enum Mode {INSERT,VIEW};

class State {
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
