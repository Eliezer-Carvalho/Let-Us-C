#include "raylib.h"


#define WIDTH 1000
#define HEIGHT 500
#define FPS 60


float gravity = 0.1;



float ball_speed_x = 1.0;
float ball_speed_y = 0.5;

float x = 300.0; // > + mais para a direita
float y = 250.0; // > + para baixo 



void  main()
{
	InitWindow(WIDTH, HEIGHT, "Flappy Bird"); //Começar uma janela!
	SetTargetFPS(FPS); //FPS estabelecidos para não sobrecarregar CPU	

	
	while (!WindowShouldClose()) //Loop que define: 'Enquanto janela aberta..'
	{;

	
	       	ball_speed_y += gravity;	//acelaração = velocidade + gravidade
		y += ball_speed_y; 


		if ((y += ball_speed_y) >= HEIGHT) {
			ball_speed_y *= 0;	//THE BEST EVER! * 0 reduz a velocidade para 0 == a bola para!
			gravity *= 0;
		
		
		}




		BeginDrawing();



		DrawCircle(x, y , 30, ORANGE); //Desenho do circulo com y += para simular queda
		DrawText(TextFormat("X = %f", x), 10, 10, 20,  ORANGE);
		DrawText(TextFormat("Y = %f", y), 10, 40, 20, ORANGE);
		DrawText(TextFormat("Gravidade = %f", gravity), 10, 80, 20, ORANGE);



		ClearBackground(DARKGRAY);
		
		EndDrawing();
	}

		CloseWindow();

}

/* Problemas com o movimento da bola.
 * Sem conseguir detetar height
 * Gravidade ? */

