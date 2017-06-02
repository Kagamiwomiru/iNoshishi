LDLIBS=-lncursesw

iNoshishi: Main.o initSnake.o MainMenu.o Help.o Game.o CreateObject.o CheckCollision.o MoveMine.o DrawUI.o LevelUP.o AddScore.o GameOver.o
	cc Main.o initSnake.o MainMenu.o Help.o Game.o CreateObject.o CheckCollision.o MoveMine.o DrawUI.o LevelUP.o AddScore.o GameOver.o -lncursesw -o iNoshishi

Main.o: Main.c SnakeKit.h
	cc -c Main.c -o Main.o

initsnake.o: initSnake.c SnakeKit.h
	cc -c initSnake.c -o initSnake.o

MainMenu.o: MainMenu.c SnakeKit.h
	cc -c MainMenu.c -o MainMenu.o

Help.o: Help.c SnakeKit.h
	cc -c Help.c -o Help.o

Game.o: Game.c SnakeKit.h
	cc -c Game.c -o Game.o

CreateObject.o: CreateObject.c SnakeKit.h
	cc -c CreateObject.c -o CreateObject.o


CheckCollision.o: CheckCollision.c SnakeKit.h
	cc -c CheckCollision.c -o CheckCollision.o

MoveMine.o: MoveMine.c SnakeKit.h
	cc -c MoveMine.c -o MoveMine.o

DrawUI.o: DrawUI.c SnakeKit.h
	cc -c DrawUI.c -o DrawUI.o
LevelUP.o: LevelUP.c SnakeKit.h
	cc -c LevelUP.c -o LevelUP.o
AddScore.o: AddScore.c SnakeKit.h
	cc -c AddScore.c -o AddScore.o
GameOver.o: GameOver.c SnakeKit.h
	cc -c GameOver.c -o GameOver.o
