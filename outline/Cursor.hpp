class Cursor {
	public:
		const std::pair<int,int> getCursorPos();
		void setCursorPos(int line, int col);
		const int getLine();
		const int getCol();
	private:
		std::pair<int,int> cursorPos;
};
