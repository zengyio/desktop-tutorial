#pragma once
class Tetris{
	public:
		Tetris::Tetris(int rows,int cols,int left,int top,int blockSize);
		void init();//��ʼ�� 
		void play;//��ʼ��Ϸ 
	private:
		void keyEvent();
		void updateWindow();
		void clearLine(); 
		int getDelay();//��һ�ε��������˶���ʱ�� 
	private
	int delay;
	bool update;
};
