#include"SnakeKit.h"
char CheckCollision(ICHI *Feed,ICHI Block[],ICHI *Mine,ICHI tkabe[],ICHI ykabe[]){
	int i;
	char c='0';
	if((*Feed).x==(*Mine).x && (*Feed).y==(*Mine).y){//餌とぶつかった
		c='1';
	return c;
	}
	for(i=0;i<BLOCK;i++){//当たり判定を50回繰り返す
		if(Block[i].x==(*Mine).x && Block[i].y==(*Mine).y){//障害物と当たった
		c='2';	
			return c;	
		}
	}
	for(i=0;i<MAXW*2+1;i++){
		if(ykabe[i].x==(*Mine).x && ykabe[i].y==(*Mine).y){
	c='2';
	return c;
		}
	}//"-"と当たった
	for(i=0;i<MAXH*2+1+1;i++){
		if(tkabe[i].x==(*Mine).x && tkabe[i].y==(*Mine).y){
	c='2';
	return c;
		}
	}//"|"と当たった


	return c;

}

////////////////////////////////////////
/*int main(){
	
	char c;
	ICHI Feed,Block[BLOCK],Mine;

  setlocale(LC_ALL, "");
	initscr();
	Mine.x=25;
	Mine.y=25;
	CreateObject(&Feed,Block);
	Feed.x=25;
	Feed.y=25;
	DrawUI(&Feed,Block,&Mine);
	c=CheckCollision(&Feed,Block,&Mine);
	sleep(2);

	mvaddch(25,25,c);
	refresh();
	sleep(2);
	endwin();
	return 0;

}*/
