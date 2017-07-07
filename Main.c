#include"SnakeKit.h"

int main(){
	int mc,s,debug_flag;
	setlocale(LC_ALL,"");
	initscr();
	curs_set(0);
	noecho();
	s=initSnake();//画面サイズ確認
	if(s==0){
		while(true){//実行処理
			mc=MainMenu();
			clear();
			if(mc==48){
							debug_flag=0;
				Game(&debug_flag);
				clear();
			}else if(mc==49){
							debug_flag=1;
				Game(&debug_flag);
				clear();
			}else if(mc==50){
			Help();	
			}else if(mc==51){
			showRank();
			clear();
			}else if(mc==52){
				return 0;
			}else{
				fprintf(stderr,"Main:条件の値が間違っているか、不正です。");
			}
		}
	}else{
		endwin();
		return 0;

	}	
}
