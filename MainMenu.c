#include"SnakeKit.h"
struct menu{
	char title[20];
	char menu0[10];
	char menu1[10];
	char menu2[10];
};




int MainMenu(){
static struct menu msg={"iNoshishi","0:START","1:HELP","2:EXIT"};
int x,y;
int ch=0;

getmaxyx(stdscr,y,x);
mvaddstr(y/2+3,x/2-(strlen(msg.menu2)/2),msg.menu2);
mvaddstr(y/2+0,x/2-(strlen(msg.menu1)/2),msg.menu1);
mvaddstr(y/2-3,x/2-(strlen(msg.menu0)/2),msg.menu0);
mvaddstr(y/2-10,x/2-(strlen(msg.title)/2),msg.title);

crmode();
//noecho();
while(true){
ch=getch();
if(ch<'3' && ch>='0'){
endwin();
return ch;
}
}



}

