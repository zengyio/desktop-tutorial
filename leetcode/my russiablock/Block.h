#pragma once
struct Point{
	int row;
	int col;
};
class Block{
	public:
		void drop();
		void moveLeftRight(int offset);
		void retate();
		void draw(int LeftMargin, int topMargin);
	private;
	int blockType;
	Point smallBlock[4];	
};
