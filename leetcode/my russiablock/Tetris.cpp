#include<Tetris.h>
#include<time.h>
#include<stdio.h>
	Tetris::Tetris(int rows,int cols,int left,int top,int blockSize){
	}
	Tetris::init(){
		delay=30;
		srand(time(NULL));
	}//��ʼ�� 
	Tetris::play(){
		init();
		int timer =0;
		while(1){
			keyEvent();
			timer+=getDelay();
			if(time>delay){
				timer=0;
				drop();
				//��Ⱦ���� 
				update=true;
			} 
			if(update==true)
				{
				update=false;�������»��� 
				updateWindow(); 
				}

		}
	}//��ʼ��Ϸ 

	Tetris::keyEvent(){
				
			}
	Tetris::updateWindow(){
	}
	Tetris::updateWindow(){
	}
	Tetris::clearLine(){
	}
	Tetris::getDelay(){
	}
