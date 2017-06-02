#include"SnakeKit.h"
//GameMain
void Game(){
	ICHI Feed,Block[BLOCK],Mine;
	ICHI ykabe[5000];//"-"の座標
	 ICHI tkabe[5000];//"|"の座標
	int Sokudo=70000;//自機の速度	
	int flag=0;//CreateObjectの初回実行フラグ（0がtrue)
	int point=0;//スコアポイント
	char check='0';	
	static int syoki;
	setlocale(LC_ALL,"");
	initscr();
	syoki=0;
	CreateObject(&Feed,Block,&flag);
	while(true){
		MoveMine(&Mine,&Sokudo,&syoki);
		DrawUI(Feed,Block,Mine,tkabe,ykabe,&point);
		check=CheckCollision(&Feed,Block,&Mine,tkabe,ykabe);
		if(check=='1') {
			CreateObject(&Feed,Block,&flag);
			LevelUP(&Sokudo);
			AddScore(&point);
		}
		if(check=='2') {
			clear();
			
		GameOver(&point);		
			break;//ぶつかったらプログラム終了
	}
	}
	
	endwin();

	return ;
}
