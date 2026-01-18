#include "raylib.h"



#define WIDTH 640
#define HEIGHT 360
#define FPS 60


float gravity = 0.2;

float ball_speed_x = 1.5;
float ball_speed_y = 0.1;

float x = 10.0; // > + mais para a direita
float y = 1.0; // > + para baixo 



void  main()
{
	InitWindow(WIDTH, HEIGHT, "Flappy Bird"); //Começar uma janela!
	SetTargetFPS(FPS); //FPS estabelecidos para não sobrecarregar CPU	
	

	Texture2D fundo = LoadTexture("Background/teste/Tropical mountains - Layer 1.png");
	float scroll = 0.0f;

	Camera2D cam = { 0 };
        cam.target = (Vector2){x, HEIGHT};
        cam.offset = (Vector2){WIDTH / 3.0f, HEIGHT / 3.0f};
        cam.rotation = 0.0f;
        cam.zoom = 0.6f;




	while (!WindowShouldClose()) //Loop que define: 'Enquanto janela aberta..'
	{;
		
	
	       	ball_speed_y += gravity;	// ball_speed_y = ball_speed_y + gravity && A gravidade aumenta a velocidade ao longo do tempo.
		y += ball_speed_y; 		// y = y + ball_speed_y && A velocidade muda o movimento.


		if ((y += ball_speed_y) >= HEIGHT+300) { //Estabelece o limite da bola que neste caso é o chão
			ball_speed_y *= 0;	//A velocidade passa a 0 porque queremos terminar o movimento.
			gravity *= 0;		//A gravidade passa também a 0.
			ball_speed_x *= 0;
	
		}



		x += ball_speed_x; //Incrementação do deslocamento
		


		if (IsKeyPressed(KEY_SPACE)) { //Deteta se a tecla espaço está a ser clicada
			if (ball_speed_y > 0) { //Só permite saltar a bola quando a mesma está em queda livre
			ball_speed_y = -4; //Define o salto, - porque queremos o inverso da descida e se a descida é a somar, a subida é o inverso.
			}
		}
	
		cam.target = (Vector2) {x, HEIGHT}; 	
	
		scroll -= 0.8f;
		if (scroll <= -fundo.width) {
		       	scroll = 0;
		}

		BeginDrawing();
		ClearBackground(DARKGRAY);
	
		
		DrawTextureEx(fundo, (Vector2) {scroll, 0}, 0.0f, 1.0f, DARKPURPLE);
		DrawTextureEx(fundo, (Vector2) {scroll + fundo.width, 0}, 0.0f, 1.0f, DARKPURPLE);
		BeginMode2D(cam);


		
		DrawCircle(x, y , 30, ORANGE); //Desenho do circulo com y += para simular queda
	//	DrawRectangle(WIDTH / 2, HEIGHT / 2, 30, 30, RED);

		EndMode2D();
		

		DrawText(TextFormat("X = %f", x), 10, 10, 10,  ORANGE);
		DrawText(TextFormat("Y = %f", y), 10, 40, 10, ORANGE);
		DrawText(TextFormat("Gravidade = %f", gravity), 10, 80, 10, ORANGE);
		DrawText(TextFormat("VELOCIDADE = %f", ball_speed_y), 10, 120, 20, ORANGE);

		
		EndDrawing();
	}
		UnloadTexture(fundo);
		CloseWindow();

}

/* Problemas com o movimento da bola.
 * Sem conseguir detetar height
 * Gravidade ? */

