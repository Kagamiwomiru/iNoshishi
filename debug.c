#include "SnakeKit.h"
// デバッグ用関数
void debug_PointShop(int *point, int *Sokudo) {
  int x,y,level=0,cnt=0,input=0;
	char title[]="====PointShop====";
  char msg[] = "設定するポイントを入力...";
  initscr();
	nocbreak();
	echo();
  getmaxyx(stdscr, y, x);

  mvaddstr(y / 2-5, x / 2 - (strlen(msg)/2), title);
  mvaddstr(y / 2, x / 2 - (strlen(msg) / 2), msg);
	refresh();
	scanw("%d",&input);
	*point=input;
	cnt=input/1000;
	level=cnt;
	while(cnt-->0)*Sokudo-=5000;
  return;
}