#include "raylib.h"


#define WIDTH 1000
#define HEIGHT 500
#define FPS 60


float gravity = 0.1;

float ball_speed_x = 1.0;
float ball_speed_y = 0.1;

float x = 10.0; // > + mais para a direita
float y = 1.0; // > + para baixo 



void  main()
{
	InitWindow(WIDTH, HEIGHT, "Flappy Bird"); //Começar uma janela!
	SetTargetFPS(FPS); //FPS estabelecidos para não sobrecarregar CPU	

	
	while (!WindowShouldClose()) //Loop que define: 'Enquanto janela aberta..'
	{;

	
	       	ball_speed_y += gravity;	// ball_speed_y = ball_speed_y + gravity && A gravidade aumenta a velocidade ao longo do tempo.
		y += ball_speed_y; 		// y = y + ball_speed_y && A velocidade muda o movimento.


		if ((y += ball_speed_y) >= HEIGHT) { //Estabelece o limite da bola que neste caso é o chão
			ball_speed_y *= 0;	//A velocidade passa a 0 porque queremos terminar o movimento.
			gravity *= 0;		//A gravidade passa também a 0.
		}


		x += ball_speed_x; //Incrementação do deslocamento



		if (IsKeyPressed(KEY_SPACE)) { //Deteta se a tecla espaço está a ser clicada
			if (ball_speed_y > 0) { //Só permite saltar a bola quando a mesma está em queda livre
			ball_speed_y = -4; //Define o salto, - porque queremos o inverso da descida e se a descida é a somar, a subida é o inverso.
			}
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

