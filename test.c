#include <ncurses.h>
int main(){
	int a=0;
	initscr();
	mvprintw(5,5,"input...\n");
	refresh();
	scanw("%d",&a);
	mvprintw(5,5,"output...%d\n",a);
	refresh();
	return 0;
}
