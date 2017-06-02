#include"SnakeKit.h"

int main(){
	int mc,s;
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
				Game();
				clear();
			}else if(mc==49){
				Help();
				clear();
			}else if(mc==50){
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
