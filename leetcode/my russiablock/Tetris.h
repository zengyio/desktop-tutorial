#pragma once
class Tetris{
	public:
		Tetris::Tetris(int rows,int cols,int left,int top,int blockSize);
		void init();//初始化 
		void play;//开始游戏 
	private:
		void keyEvent();
		void updateWindow();
		void clearLine(); 
		int getDelay();//第一次到调用用了多少时间 
	private
	int delay;
	bool update;
};
