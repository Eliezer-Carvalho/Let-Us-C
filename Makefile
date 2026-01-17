all:
	gcc flappybird.c -o flappybird.exe  -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

