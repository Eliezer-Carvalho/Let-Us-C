#include "raylib.h"


#define WIDTH 1000
#define HEIGHT 500
#define FPS 60


float ball_speed_x = 1.0;
float ball_speed_y = 3.0;


void  main()
{
	InitWindow(WIDTH, HEIGHT, "Flappy Bird"); //Começar uma janela!
	SetTargetFPS(FPS); //FPS estabelecidos para não sobrecarregar CPU	

	
	
	while (!WindowShouldClose()) //Loop que define: 'Enquanto janela aberta..'
	{
		
		float y = 100;
		float x = 300;

		if (y == HEIGHT) {
			DrawText("end game", WIDTH / 2, HEIGHT / 2, 20, ORANGE);

		}


		BeginDrawing();

		ClearBackground(DARKGRAY);

		DrawCircle(x += ball_speed_x, y += ball_speed_y, 30, ORANGE); //Desenho do circulo com y += para simular queda
		DrawText(TextFormat("X = %f", x), 10, 10, 20,  ORANGE);
		DrawText(TextFormat("Y = %f", y), 10, 40, 20, ORANGE);

		
		EndDrawing();
	}

		CloseWindow();

}

/* Problemas com o movimento da bola.
 * Sem conseguir detetar height
 * Gravidade ? */

