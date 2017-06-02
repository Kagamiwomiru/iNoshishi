#include "SnakeKit.h"


void MoveMine(ICHI *Mine,int *Sokudo,int *syoki){
int ch;//カーソル
keypad(stdscr,TRUE);

crmode();

noecho();

if(*syoki==0){//syokiが０（最初）のとき初期値を設定。
Mine->x=25;
Mine->y=25;
Mine->up=0;//各方向フラグ
Mine->dw=0;
Mine->ri=0;
Mine->le=0;
*syoki=1;
}else{//自機の操作
	
	timeout(0);//入力なしでもプログラムを進ませる
	ch=getch();
	usleep(*Sokudo);//自機の速さ（下げると早くなる）
//入力処理//
if(ch==KEY_UP){//上に押した時上フラグをオンにして他はオフにする。
	Mine->up=1;
	Mine->dw=0;
	Mine->ri=0;
	Mine->le=0;
}
if(ch==KEY_DOWN){
	Mine->up=0;
	Mine->dw=1;
	Mine->ri=0;
	Mine->le=0;
}
if(ch==KEY_RIGHT) {
	Mine->up=0;
	Mine->dw=0;
	Mine->ri=1;
	Mine->le=0;

}
	
if(ch==KEY_LEFT){
	Mine->up=0;
	Mine->dw=0;
	Mine->ri=0;
	Mine->le=1;
}
//ここまで入力処理//
//ここから進む処理//
if(Mine->up==1) Mine->y--;
if(Mine->dw==1) Mine->y++;
if(Mine->ri==1) Mine->x++;
if(Mine->le==1) Mine->x--;
//ここまで進む処理//
timeout(-1);//これなかったら死ぬ（これ以降の処理で入力待ちができなくなる）

}
}

/*int main(){
	int ch;
	ICHI Mine;
	initscr();
	while(true){
		MoveMine(&Mine);
		mvaddch(Mine.y,Mine.x,'o');
		refresh();
		
	}
	endwin();

	return 0;
}*/


