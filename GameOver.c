#include "SnakeKit.h"
void GameOver(int *point,int *debug_flag) {
  int x, y;
  char p[10];
  int ch=0;
  int tmp_p,check;
	char name[5];
  int i;
	tmp_p = *point;
  setlocale(LC_ALL, "");
  initscr();
  getmaxyx(stdscr, y, x);
check=CheckRank(tmp_p,debug_flag);
  
if(check==1){//ランクインしたとき
 
  mvaddstr(y / 2 - 10, x / 2-5, "ランクイン！");
	
  sprintf(p, "%d", *point);
  mvaddstr(y / 2 - 8, x / 2-10, "名前を入力してください(5文字)\n");

for(i=0;i<9;i++){
	mvaddch(y/2-7,x/2-6+i,'-');
	mvaddch(y/2-5,x/2-6+i,'-');
}
	mvaddch(y/2-6,x/2-6,'|');
	mvaddch(y/2-6,x/2+2,'|');
	move(y/2-6,x/2-5);

	nocbreak();
	echo();
	refresh();
	scanw("%s",name);
	while(strlen(name)>5){					
  mvprintw(y / 2 - 4, x / 2-10, "%s", "文字数超過：5文字以内で入力してください");
	mvprintw(y/2-6,x/2-5,"%s","       |                   ");
	refresh();
	move(y/2-6,x/2-5);				
	scanw("%s",name);
	}//文字数超過処理

	if(!UpdateRank(name,point,debug_flag)) mvaddstr(y / 2 - 5, x / 2, "保存に失敗しました。");
//ランキングをアップデート

	return;

}else if(check==0){//ランクインしなかったとき
  mvaddstr(y / 2 - 10, x / 2, "GameOver!!");
  sprintf(p, "%d", *point);
  mvaddstr(y / 2 - 8, x / 2, p);
  mvprintw(y / 2 - 6, x / 2, "%s", "q:最初に戻る");
  // mvprintw(y/2-6,x/2,"%s","r:ランキング画面" );

  refresh();
  crmode();
  noecho();
  while (ch != 'q') ch = getch();


}
	return;
}

int CheckRank(int point,int *debug_flag) {
  FILE *fp;
  char *fname = "Ranking.txt";
  char s[400] = {0};
  RANK rank[10];
	char *tmpi;
	char *tmpc;
  int i = 0, j;
  int x, y;
  char msg[] = "ランキングファイル(Ranking.txt)が見つかりませんでした。\n";
	if(*debug_flag==1){//debug
  getmaxyx(stdscr, y, x);
  mvprintw(12, 1, "%d\n", point);
	}

	//ランキングをダウンロード	
system("scp Earth:kadai/se17/iNoshishiServer/Ranking.txt .");	

	fp = fopen(fname, "r");
 
	
	if (fp == NULL) {
    mvaddstr(y / 2, x / 2, msg);
    refresh();
		sleep(3);
    return 0;
  }
  /*
    fgets(s, 400, fp);
    Rank[0] = strtok(s, ",");
    Rank[1] = strtok(NULL, ",");
    mvaddstr(13, 1, Rank[0]);
    mvaddstr(14, 1, Rank[1]);
    refresh();
  */
  //点数部分と名前部分に分割
  while (fgets(s, 400, fp) != NULL) {

    tmpi = strtok(s, ",");
    tmpc = strtok(NULL, ",");
   	//構造体に代入
		rank[i].point=atoi(tmpi);
		strcpy(rank[i].name,tmpc);
		i++;

  }

// if(i<9) return 1;//ランキングが10項目以下のときは無条件でランクイン 

//ランキングと現在ポイント比較
i = 0;
while (i < 10) {
	if (point > rank[i].point) 	return 1; //ランクインが確認出来次第１を返す
	
	i++;
}
  fclose(fp);

  return 0;
}


int cmp( const void *p, const void *q ) {
   return ((RANK*)q)->point - ((RANK*)p)->point;
}

int UpdateRank(char *name , int *point,int *debug_flag){
	FILE *fp;
  char *fname = "Ranking.txt";
	RANK retu[12];//ランキング用の構造体
	int i=0;
	char c[400];
	char *tmpc;
	char *tmpi;//作業用
	int n;	
	fp = fopen(fname, "a");//ファイルの末尾に追記
	if (fp == NULL) return 0;//保存に失敗

	
	//ファイルの末尾に記述
	fprintf(fp,"%d,%s\n",*point,name);
  
	fclose(fp);


	fp= fopen(fname,"r");

	while(fgets(c,400,fp)!=NULL){			
		//文字列をポイントと名前に分解
		tmpi=strtok(c,",");
		tmpc=strtok(NULL,",");
		//構造体に代入
		retu[i].point=atoi(tmpi);
		strcpy(retu[i].name,tmpc);
		i++;
	}
if(*debug_flag) debug_showArray(retu);
fclose(fp);	
	n=sizeof retu/sizeof(RANK);
	qsort(retu,n,sizeof(RANK),cmp);

if(*debug_flag) debug_showArray(retu);
	fp=fopen(fname,"w");
	for(i=0;i<10;i++)	fprintf(fp,"%d,%s",retu[i].point,retu[i].name);//ファイルに書き込み
	fclose(fp);

//ランキングをアップロード
system("scp Ranking.txt Earth:kadai/se17/iNoshishiServer/");
return 0;


}
