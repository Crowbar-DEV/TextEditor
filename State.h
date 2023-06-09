#include <fstream>

class State {
	private:
		Mode::Mode currentMode;
	
	protected:
		std::string timeStamp;
		bool upToDate;
		std::string file;
		fstream fileStream;
	
	public:
		State();
		virtual void setMode(Mode::Mode newMode);
		virtual Mode::Mode getMode();

}
