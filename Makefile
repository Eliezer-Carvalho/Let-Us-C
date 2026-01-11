all:
	gcc snakegame.c -o snakegame.exe  -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

