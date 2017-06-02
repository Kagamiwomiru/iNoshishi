#include"SnakeKit.h"
int initSnake(){
char msg[]="端末の大きさを全画面にしてください";
int x,y;
initscr();

	getmaxyx(stdscr,y,x);
	if(x<180 || y<50){
		mvaddstr(y/2,x/2-(strlen(msg)/2),msg);
		refresh();
		sleep(3);
		return 1;
	}
return 0;
}
