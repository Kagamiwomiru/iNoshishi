#include"SnakeKit.h"
//描写処理
void DrawSikaku(ICHI tkabe[],ICHI ykabe[]){
int i;
int s=0;//壁用の配列
for(i=0;i<MAXW+1;i++){
mvaddch(0,i,'-');
ykabe[s].x=i;
ykabe[s].y=0;
s++;
mvaddch(MAXH+1,i,'-');
ykabe[s].x=i;
ykabe[s].y=MAXH+1;
s++;
	}
	s=0;
for(i=0;i<MAXH+1;i++){
mvaddch(i,0,'|');
tkabe[s].x=0;
tkabe[s].y=i;
s++;
mvaddch(i,MAXW+1,'|');
tkabe[s].x=	MAXW+1;
tkabe[s].y=i;
s++;
	}
}
void DrawFeed(ICHI Feed){

  attrset(COLOR_PAIR(1));
  mvaddch(Feed.y,Feed.x,'O');
	refresh();
  return;
}

void DrawBlock(ICHI *Block,int n){
  int i;
  for(i=0;i<n;i++){
    attrset(COLOR_PAIR(2));
    mvaddch(Block[i].y,Block[i].x,'O');
  }
  return;
}

void DrawMine(ICHI Mine){
  attrset(COLOR_PAIR(3));

   mvaddch(Mine.y,Mine.x,'O');
if(Mine.up==1) mvaddch(Mine.y+1,Mine.x,' ');//上行ってるとき一個前の俺を消す
 if(Mine.dw==1) mvaddch(Mine.y-1,Mine.x,' ');//下 
 if(Mine.ri==1) mvaddch(Mine.y,Mine.x-1,' ');//右
 if(Mine.le==1) mvaddch(Mine.y,Mine.x+1,' ');//左
refresh();
   return;
}
void DrawPoint(int point){
	char x[10];
	int i;
	attrset(COLOR_PAIR(3));
	sprintf(x,"%d",point);
	mvaddstr(9,MAXW+20,"SCORE");
	mvaddstr(10,MAXW+20,x);//スコアの表示位置（y.x)
	for(i=MAXW+18;i<=MAXW+25;i++){//スコアの囲い（横）
		mvaddch(8,i,'-');
		mvaddch(12,i,'-');
	}
	for(i=8;i<=12;i++){//スコアの囲い（縦）
		mvaddch(i,MAXW+18,'|');
		mvaddch(i,MAXW+25,'|');
		}
	refresh();
	return;
}

void  DrawUI(ICHI Feed,ICHI *Block,ICHI Mine,ICHI *tkabe,ICHI *ykabe,int *point){
  start_color();
	curs_set(0);
  init_pair(1,COLOR_BLUE,COLOR_BLACK);
  init_pair(2,COLOR_RED,COLOR_BLACK);
  init_pair(3,COLOR_WHITE,COLOR_BLACK);	
	DrawSikaku(tkabe,ykabe);
  DrawFeed(Feed);
  DrawBlock(Block,50);
  DrawMine(Mine);
	DrawPoint(*point);
}


/*
int main(){
  ICHI Feed,Block[50],Mine;
  int i;
  srand((unsigned)time(NULL));

  setlocale(LC_ALL, "");
  initscr();
  Feed.x=51;
  Feed.y=24;
  for(i=0;i<50;i++){
    Block[i].x=rand()%MAXW+1;
    Block[i].y=rand()%MAXH+1;
  }
  Mine.x=50;
  Mine.y=25;
  DrawUI(Feed,Block,Mine);
  refresh();
  sleep(3);
  endwin();
  return 0;


}*/
