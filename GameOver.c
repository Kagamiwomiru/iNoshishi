#include"SnakeKit.h"

void GameOver(int *point){
	int x,y;
	char p[10];
	int ch;
	setlocale(LC_ALL, "");
	initscr();
	getmaxyx(stdscr,y,x);
	mvaddstr(y/2-10,x/2,"GameOver!!");
	sprintf(p,"%d",*point);
	mvaddstr(y/2-8,x/2,p);
	mvprintw(y/2-6,x/2,"%s","qキーで最初に戻る" );
	refresh();
	crmode();
	noecho();
	while(ch!='q')
			ch=getch();



return ;
}
