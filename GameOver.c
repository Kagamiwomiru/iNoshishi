#include "SnakeKit.h"
void GameOver(int *point) {
  int x, y;
  char p[10];
  int ch;
  int tmp_p;
  tmp_p = *point;
  setlocale(LC_ALL, "");
  initscr();
  getmaxyx(stdscr, y, x);

  if (CheckRank(tmp_p)) { //ランクインチェック
    mvprintw(11, 1, "DEBUG:RANK_IN\n");
  } else if (!CheckRank(tmp_p)) {
    mvprintw(11, 1, "DEBUG:NOT_RANK_IN\n");
  } else {
    mvprintw(11, 1, "DEBUG:!ERROR!\n");
  }

  mvaddstr(y / 2 - 10, x / 2, "GameOver!!");
  sprintf(p, "%d", *point);
  mvaddstr(y / 2 - 8, x / 2, p);
  mvprintw(y / 2 - 6, x / 2, "%s", "q:最初に戻る");
  // mvprintw(y/2-6,x/2,"%s","r:ランキング画面" );

  refresh();
  crmode();
  noecho();
  while (ch != 'q')
    ch = getch();

  return;
}

int CheckRank(int point) {
  FILE *fp;
  char *fname = "Ranking.txt";
  char s[400] = {0};
  char *Rank[20];
  int Rank_point[10]; //ランキングに記録されている点数をint化したもの
  int i = 0, j = 0;
  int x, y;
  char msg[] = "ランキングファイル(Ranking.txt)が見つかりませんでした。\n";
  getmaxyx(stdscr, y, x);
  mvprintw(12, 1, "%d\n", point);

  fp = fopen(fname, "r");
  if (fp == NULL) {
    mvaddstr(y / 2, x / 2, msg);
    refresh();
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

    Rank[i] = strtok(s, ",");
    Rank[i + 1] = strtok(NULL, ",");

    mvaddstr(13 + i, 1, Rank[i]);
    mvaddstr(14 + i, 1, Rank[i + 1]);
    refresh();
    i += 2;
  }
  /*
    i = 0;
    // int化
    while (i < 21) {
      Rank_point[j] = atoi(Rank[i]);
      i += 2;
      j++;
    }*/

  /*

//ランキングと現在ポイント比較
i = 0;
while (i < 11) {
if (point >= Rank_point[i]) {
return 1; //ランクインが確認出来次第１を返す
}
i++;
}
*/
  fclose(fp);

  return 0;
}
