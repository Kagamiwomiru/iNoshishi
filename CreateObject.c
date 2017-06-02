#include"SnakeKit.h"

/*void DrawUI(ICHI Feed,ICHI *Block,ICHI Mine);
void DrawMine(ICHI Mine);
void DrawBlock(ICHI *Block,int n);
void DrawFeed(ICHI Feed);
void DrawSikaku();*/
void CreateFeed(ICHI *Feed){
	Feed->x=rand()%MAXW+1;
	Feed->y=rand()%MAXH+1;


	return;
}

void CreateBlock(ICHI Block[]){
	int i;
	for(i=0;i<50;i++){
		Block[i].x=(rand()%MAXW)+1;
		Block[i].y=(rand()%MAXH)+1;
	}
	return;
}

void CreateObject(ICHI *Feed,ICHI Block[],int *flag){
	int i;
	srand((unsigned)time(NULL));/*ランダム整数を生成するのに必要time.hをインクルード*/
	if(*flag==0){//初回実行だけブロックを生成
	CreateBlock(Block);
	*flag=1;
	}
	CreateFeed(Feed);
	for(i=0;i<50;i++){//餌とブロックがダブったとき
	if(Feed->x==Block[i].x && Feed->y==Block[i].y){
			CreateFeed(Feed);

		}	
	}
	
	return;
}
//////////////////////////////////////////////////////////////////////
/*int main(){
	ICHI Feed,Block[50],Mine;
	
	setlocale(LC_ALL, "");
	initscr();
  Mine.x=50;
  Mine.y=25;
	CreateObject(&Feed,Block);
	DrawUI(Feed,Block,Mine);
	refresh();
	sleep(3);
	endwin();
return 0;

}


void DrawSikaku(){
		int i;
		for(i=0;i<MAXW+1;i++){
			mvaddch(0,i,'-');
			mvaddch(MAXH+1,i,'-');
		}
		for(i=1;i<MAXH+1;i++){
			mvaddch(i,0,'|');
			mvaddch(i,MAXW+1,'|');
		}
	}
	void DrawFeed(ICHI Feed){

		  attrset(COLOR_PAIR(1));
			  mvaddstr(Feed.y,Feed.x,"■");

				  return;
	}

	void DrawBlock(ICHI *Block,int n){
		  int i;
			  for(i=0;i<n;i++){
					    attrset(COLOR_PAIR(2));
							    mvaddstr(Block[i].y,Block[i].x,"■");
									  }
										  return;
	}

	void DrawMine(ICHI Mine){
		 
		   attrset(COLOR_PAIR(3));
			   mvaddstr(Mine.y,Mine.x,"■");
				   refresh();
					    return;
	}


	void  DrawUI(ICHI Feed,ICHI *Block,ICHI Mine){
		  start_color();
			  init_pair(1,COLOR_BLUE,COLOR_BLACK);
				  init_pair(2,COLOR_RED,COLOR_BLACK);
					  init_pair(3,COLOR_WHITE,COLOR_BLACK);
						DrawSikaku();
						  DrawFeed(Feed);
							  DrawBlock(Block,50);
								  DrawMine(Mine);

	}


*/


