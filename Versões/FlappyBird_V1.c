#include "raylib.h"
#include <stdio.h>


#define WIDTH 640
#define HEIGHT 360
#define FPS 60


float gravity = 0.5;

float ball_speed_x = 0;
float ball_speed_y = 0.5;

float x = 150.0; // > + mais para a direita
float y = 0.01; // > + para baixo 


struct colunas {
	float rectx;
	int h;
	int h2;
};


bool game_Over = false;




void  main() {

	InitWindow(WIDTH, HEIGHT, "Flappy Bird"); //Começar uma janela!
	SetTargetFPS(FPS); //FPS estabelecidos para não sobrecarregar CPU	

		

	Texture2D fundo = LoadTexture("Background/teste/Tropical mountains - Layer 1.png"); // A imagem é sempre carregada com duas vezes a escala original
	Texture2D fundo_chão = LoadTexture("Background/teste/Tropical mountains - Layer 3.png"); // Imagem de baixo
	Texture2D flappy = LoadTexture("Background/flappybird2.png");


	float scroll = 0.0f;
	float scroll2 = 0.0f; 


	struct colunas cols [50];
	int rectx = 640;
	for (int i = 0; i < 50; i++) {

		int h = GetRandomValue(75,125);
		int h2 = GetRandomValue(75, 125);


		cols[i].rectx = rectx;
	        cols[i].h = h;
	        cols[i].h2 = h2;

		rectx += 200;
	}
	
	bool colisao1 = false;
	bool colisao2 = false;


	int hitboxflappy_x = flappy.width * 0.3 * 0.5;
	int hitboxflappy_y = flappy.height * 0.5 * 0.5;

	while (!WindowShouldClose()) { //Loop que define: 'Enquanto janela aberta..'
		
		//Condição para o jogo não começar logo
		

		if (game_Over == false) {

			ball_speed_y += gravity;	// ball_speed_y = ball_speed_y + gravity && A gravidade aumenta a velocidade ao longo do tempo
			y += ball_speed_y; 		// y = y + ball_speed_y && A velocidade muda o movimento.
			
			scroll -= 1.5f;
                        if (scroll <= -fundo_chão.width) {
                                scroll = 0;
                        }

                        scroll2 -= 0.5f;
                        if (scroll2 <= -fundo.width) {
                                scroll2 = 0;
                        }

			
			x += ball_speed_x; //Incrementação do deslocamento


	                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { //Deteta se a tecla espaço está a ser clicada
        	                if (ball_speed_y > 0) { //Só permite saltar a bola quando a mesma está em queda livre
                	        ball_speed_y = -10; //Define o salto, - porque queremos o inverso da descida e se a descida é a somar, a subida é o inverso.
                       		}
                	}

		}
			

		if (y >= 300 || y <= 0 || colisao1 == true || colisao2 == true) { //Estabelece o limite da bola que neste caso é o chão
			
			game_Over = true;
			ball_speed_y *= 0;	//A velocidade passa a 0 porque queremos terminar o movimento.
			gravity *= 0;		//A gravidade passa também a 0.
			ball_speed_x *= 0;
			scroll *= 0; 			
			scroll2 *= 0;		
		}


		BeginDrawing();
		ClearBackground(WHITE);
		

		
		DrawTextureV(fundo, (Vector2) {scroll2, 0}, WHITE); //Fundo inicial, no Vector (0,0)
		DrawTextureV(fundo, (Vector2) {scroll2 + fundo.width, 0}, WHITE);			 

		DrawTextureV(fundo_chão, (Vector2) {scroll, HEIGHT / 4}, LIME);
		DrawTextureV(fundo_chão, (Vector2) {scroll + fundo_chão.width, HEIGHT / 4}, LIME); //Fundo à medida que o scroll vai andando, é simplesmente uma sobreposição do fundo




                DrawTextureEx(flappy, (Vector2) {x, y}, 0, 0.3, WHITE);

		
		Rectangle flappyrec = {
                        x + (flappy.width * 0.5 - hitboxflappy_x) / 2,
                        y + (flappy.height * 0.5 - hitboxflappy_y) / 2,
                        hitboxflappy_x,
                        hitboxflappy_y};
                DrawRectangleLinesEx(flappyrec, 3.0, RED);


			for (int i = 0; i < 50; i++) {

				Rectangle pipecima = {cols[i].rectx, 0, 70, cols[i].h};
                        	Rectangle pipebaixo = {cols[i].rectx + 2, (HEIGHT - cols[i].h2) - 5, 70, cols[i].h2};

                        	DrawRectangleLinesEx(pipecima, 2.0, RED);
                        	DrawRectangleLinesEx(pipebaixo, 2.0,  RED);
                
                        	colisao1 = CheckCollisionRecs(flappyrec, pipecima);
                 	     	colisao2 = CheckCollisionRecs(flappyrec, pipebaixo);


				if (colisao1 == true || colisao2 == true) {

					game_Over = true;
				}


				DrawRectangle(cols[i].rectx, 0, 70, cols[i].h, DARKBLUE);
				DrawRectangle(cols[i].rectx, HEIGHT - cols[i].h2, 70, cols[i].h2, DARKBLUE);	
				cols[i].rectx -= 2.5;
			}
	
/*
		DrawText(TextFormat("Gravidade = %f", gravity), 10, 50, 10, ORANGE);
		DrawText(TextFormat("VELOCIDADE = %f", ball_speed_y), 10, 70, 10, ORANGE);
		DrawText(TextFormat("SCROLL = %f", scroll2), 10, 90, 10, ORANGE);
		DrawText(TextFormat("Altura = %i || Largura = %i", GetScreenHeight(), GetScreenWidth()), 10, 110, 10, ORANGE);
*/
		EndDrawing();
	
	}
		UnloadTexture(fundo);
		UnloadTexture(fundo_chão);
		UnloadTexture(flappy);
		CloseWindow();
		
}


