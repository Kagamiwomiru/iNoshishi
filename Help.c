#include "SnakeKit.h"

void Help() {
  FILE *fp;
  char *fname = "Help.txt";
  char s[400];
  int i = 0;
  char ch = '0';
  int x, y;
  char msg[] = "ヘルプファイル(Help.txt)が見つかりませんでした。\n";
  fp = fopen(fname, "r");
  getmaxyx(stdscr, y, x);
  crmode();
  noecho();
  if (fp == NULL) {
    mvprintw(10, x / 2 - (strlen(msg) / 2), "%s", msg);
    refresh();
    return;
  }
  while (fgets(s, 400, fp) != NULL) {
    mvprintw(10 + i, x / 2 - (strlen(msg) / 2), "%s", s);
    i++;
    refresh();
  }
  while (ch != 'q') {
    ch = getch();
  }
  clear();
  fclose(fp);
  return;
}

/*int main(){
        setlocale(LC_ALL,"");
        initscr();
        help();
        endwin();
        return 0;
}*/
