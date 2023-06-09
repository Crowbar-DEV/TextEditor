#include <fstream>
#include <iostream>
#include "Mode.cpp"

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
