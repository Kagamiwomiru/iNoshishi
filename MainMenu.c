#include"SnakeKit.h"
struct menu{
	char title[20];
	char menu0[10];
	char menu1[50];
	char menu2[10];
	char menu3[10];
	char menu4[10];
};




int MainMenu(){
static struct menu msg={"iNoshishi","0:START","1:いんちき","2:Help","3:Ranking","4:EXIT"};
int x,y;
int ch=0;

getmaxyx(stdscr,y,x);

mvaddstr(y/2+9,x/2-(strlen(msg.title)/2),msg.menu4);
mvaddstr(y/2+6,x/2-(strlen(msg.title)/2),msg.menu3);
mvaddstr(y/2+3,x/2-(strlen(msg.title)/2),msg.menu2);
mvaddstr(y/2+0,x/2-(strlen(msg.title)/2),msg.menu1);
mvaddstr(y/2-3,x/2-(strlen(msg.title)/2),msg.menu0);
mvaddstr(y/2-10,x/2-(strlen(msg.title)/2),msg.title);

crmode();
//noecho();
while(true){
ch=getch();
if(ch<'5' && ch>='0'){
endwin();
return ch;
}
}



}

