#include "raylib.h"


#define WIDTH 1000
#define HEIGHT 500
#define FPS 60


float  y = 100; //pos inicial do boneco para simular caída (começa de baixo para cima)


void  main()
{
	InitWindow(WIDTH, HEIGHT, "Flappy Bird"); //Começar uma janela!
	SetTargetFPS(FPS);	

	while (!WindowShouldClose()) //Loop que define: 'Enquanto janela aberta..'
	{
		BeginDrawing();

		DrawCircle(WIDTH / 2, y += 4, 30, ORANGE);
		if (y == HEIGHT) {
			y = HEIGHT;
			DrawCircle(WIDTH / 2, HEIGHT, 30, ORANGE);
			DrawText("END GAME", WIDTH / 2, HEIGHT /  2, 20, ORANGE);
		}	

		ClearBackground(DARKGRAY);
		EndDrawing();
	}

		CloseWindow();

}



