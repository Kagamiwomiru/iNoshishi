#include "SnakeKit.h"

void showRank(){
	FILE *fp;
  char *fname = "Ranking.txt";
  char s[400];
  int i = 0;
  char ch = '0';
  int x, y;
	char clm[]="Point,Name";
	char ttl[]="ランキング";
	char push_q[]="q:メニューに戻る";
	char msg[] = "ランキング(Ranking.txt)が見つかりませんでした。\n";
	RANK hope[12];//ランキング
	getmaxyx(stdscr, y, x);

system("scp Earth:kadai/se17/iNoshishiServer/Ranking.txt .");	
	
	fp = fopen(fname, "r");
  crmode();
  noecho();
  
	for(i=0;i<20;i++){
		mvaddch(20,(x/2-15)+i,'-');	
		mvaddch(35,(x/2-15)+i,'-');
	}

	for(i=0;i<15;i++){
		mvaddch(20+i,x/2-15,'|');
		mvaddch(20+i,x/2+5,'|');
		if(i==0){	
    mvprintw(21, x / 2 -10, "%s", ttl);
		while(i<20){
						mvaddch(22,(x/2-15)+i,'-');
		i++;
		}
		i=0;

    mvprintw(23, x / 2 -10, "%s", clm);
		}
		
		if(i<10){
		fgets(s,400,fp);	
    mvprintw(24 + i, x / 2 - 10, "%s", s);
		}
	}

    mvprintw(36, x / 2 -13, "%s", push_q);
	refresh();
	
 if (fp == NULL) {
    mvprintw(24, x / 2 - 10, "%s", msg);
    refresh();
    return;
  }
  
  fclose(fp);

  while (ch != 'q') {
    ch = getch();
  }
  clear();
 
	


	
	return;
}
 
