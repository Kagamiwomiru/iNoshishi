#ifndef SNAKE_KIT_H
#define SNAKE_KIT_H
#define MAXH 50
#define MAXW 150
#define KOSU 500
#define BLOCK 50
typedef struct ichi{
	int x;
	int y;
	int up;
	int dw;
	int ri;
	int le;
}ICHI;

typedef struct rank{
	int point;
	char name[5];
}RANK;

#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include <locale.h>/*マルチバイト文字に必要*/
#include<time.h>
void CreateObject(ICHI *Feed,ICHI Block[],int *flag);
char CheckCollision(ICHI *Feed,ICHI Block[],ICHI *Mine,ICHI tkabe[],ICHI ykabe[]);
void MoveMine(ICHI *Mine,int *Sokudo,int *syoki);
void LevelUP(int *Sokudo);
void DrawUI(ICHI Feed,ICHI *Block,ICHI Mine,ICHI *tkabe,ICHI *ykabe,int *point);
void AddScore(int *point);
void GameOver(int *point,int *debug_flag);
void Help();
int UpdateRank(char *name,int *point,int *debug_flag);
int CheckRank(int point,int *debug_flag);
void showRank();
int cmp( const void *p, const void *q );
void debug_PointShop(int *point,int *Sokudo);
void debug_showArray(RANK *retu);

#endif
