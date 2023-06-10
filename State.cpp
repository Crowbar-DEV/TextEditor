#include "StateInterface.h"

class State : StateInterface {

	private:
		Mode currentMode;

	protected:
		bool upToDate;

	public:
		State() {
			currentMode = Mode.VIEW;
			upToDate = true; // TODO not sure if this is correct
		}
		void setMode(Mode newMode) {
			this->currentMode = newMode;
		}
		Mode getMode() {
			return currentMode;
		}

};
