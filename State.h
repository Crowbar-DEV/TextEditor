#include <fstream>
#include <iostream>
#include "Mode.cpp"

class State {
	private:
		Modes currentMode;
	
	protected:
		std::string timeStamp;
		bool upToDate;
		std::string file;
		std::fstream fileStream;
	
	public:
		State();
		virtual void setMode(Modes newMode);
		virtual Modes getMode();

};
