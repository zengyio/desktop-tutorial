#include<Block.h>
#include<> 

Block::Block{
	int blocks[7][4]={
	1,3,5,7,
	2,4,5,7,
	3,5,4,6,
	3,5,4,7
	2,3,5,7,
	3,5,7,6,
	2,3,4,5,	}
	blockType=1+ rand()%7;
}
Block::drop(){
}
Block::moveLeftRight(int offset){
}
Block::retate(){
}
Block::draw(int LeftMargin, int topMargin){
}
