#include "raylib.h"


#define WIDTH 1000
#define HEIGHT 500
#define FPS 60


void  main()
{
	InitWindow(WIDTH, HEIGHT, "Flappy Bird"); //Começar uma janela!
	SetTargetFPS(FPS);	

	while (!WindowShouldClose()) //Loop que define: 'Enquanto janela aberta..'
	{


		ClearBackground(DARKGRAY);
		EndDrawing();
	}

		CloseWindow();

}



