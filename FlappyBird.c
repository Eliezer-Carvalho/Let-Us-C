#include "raylib.h"
#include <stdio.h>


#define WIDTH 640
#define HEIGHT 360
#define FPS 60


float gravity = 0.5;

float ball_speed_x = 1.5;
float ball_speed_y = 1;

float x = 10.0; // > + mais para a direita
float y = 100.0; // > + para baixo 


struct colunas {
	float rectx;
	int h;
	int h2;
};

float rot = 0;





void  main() {

	InitWindow(WIDTH, HEIGHT, "Flappy Bird"); //Começar uma janela!
	SetTargetFPS(FPS); //FPS estabelecidos para não sobrecarregar CPU	

//	Rectangle flappyrec = {ball_speed_x, ball_speed_y, flappy_width, flappy_height};
		

	Texture2D fundo = LoadTexture("Background/teste/Tropical mountains - Layer 1.png"); // A imagem é sempre carregada com duas vezes a escala original
	Texture2D fundo_chão = LoadTexture("Background/teste/Tropical mountains - Layer 3.png"); // Imagem de baixo
	Texture2D flappy = LoadTexture("Background/flappybird.png");


	float scroll = 0.0f;
	float scroll2 = 0.0f; 

	Camera2D cam = { 0 };
        cam.target = (Vector2){x, HEIGHT};
        cam.offset = (Vector2){WIDTH / 3.0f, HEIGHT / 3.0f};
        cam.rotation = 0.0f;
        cam.zoom = 0.5f;

	struct colunas cols [20];
	int rectx = 640;
	for (int i = 0; i < 20; i++) {

		int h = GetRandomValue(75,150);
		int h2 = GetRandomValue(75, 150);


		cols[i].rectx = rectx;
	        cols[i].h = h;
	        cols[i].h2 = h2;

		rectx += 200;
	}
	
	bool colisao1 = false;
	bool colisao2 = false;


	int hitboxflappy_x = flappy.width * 0.2 * 0.5;
	int hitboxflappy_y = flappy.height * 0.2 * 0.5;

	while (!WindowShouldClose()) { //Loop que define: 'Enquanto janela aberta..'
		
		//Condição para o jogo não começar logo
		





	
	       	ball_speed_y += gravity;	// ball_speed_y = ball_speed_y + gravity && A gravidade aumenta a velocidade ao longo do tempo.
		y += ball_speed_y; 		// y = y + ball_speed_y && A velocidade muda o movimento.


		if (y >= 760 || y <= 100) { //Estabelece o limite da bola que neste caso é o chão

			ball_speed_y *= 0;	//A velocidade passa a 0 porque queremos terminar o movimento.
			gravity *= 0;		//A gravidade passa também a 0.
			ball_speed_x *= 0;
			scroll *= 0;
			scroll2 *= 0;		
		}


	       	else if (y < 760 && y > 100) {
			scroll -= 1.5f;
			if (scroll <= -fundo_chão.width) {
				scroll = 0;
			}

			scroll2 -= 0.5f;
                        if (scroll2 <= -fundo.width) {
                                scroll2 = 0;
                        }

		} 
	
		
	
	
	



		x += ball_speed_x; //Incrementação do deslocamento
		
	
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { //Deteta se a tecla espaço está a ser clicada
			if (ball_speed_y > 0) { //Só permite saltar a bola quando a mesma está em queda livre
			ball_speed_y = -10; //Define o salto, - porque queremos o inverso da descida e se a descida é a somar, a subida é o inverso.
			}
		}
	
		cam.target = (Vector2) {x, HEIGHT}; 	
	
	
		//colisão1 = CheckCollisionRecs(flappy, pipecima);
		//	if (colisão1 == True) {
		//		DrawText(TextFormat("OKK"), 30, 30, 20,  ORANGE);
		//	}
			


		BeginDrawing();
		ClearBackground(WHITE);
		

		//Necessário 2 FUNDOS porque um é o inicial e o outro é o consequente
		
		DrawTextureV(fundo, (Vector2) {scroll2, 0}, WHITE); //Fundo inicial, no Vector (0,0)
		DrawTextureV(fundo, (Vector2) {scroll2 + fundo.width, 0}, WHITE);			 

		DrawTextureV(fundo_chão, (Vector2) {scroll, HEIGHT / 4}, LIME);
		DrawTextureV(fundo_chão, (Vector2) {scroll + fundo_chão.width, HEIGHT / 4}, LIME); //Fundo à medida que o scroll vai andando, é simplesmente uma sobreposição do fundo



		BeginMode2D(cam);

                DrawTextureEx(flappy, (Vector2) {x, y}, rot, 0.2, WHITE);

                //DrawCircle(x, y , 50, ORANGE); //Desenho do circulo com y += para simular queda
		
		Rectangle flappyrec = {
                        x + (flappy.width * 0.2 - hitboxflappy_x) / 2,
                        y + (flappy.height * 0.2 - hitboxflappy_y) / 2,
                        hitboxflappy_x,
                        hitboxflappy_y};
                DrawRectangleLinesEx(flappyrec, 3.0, RED);
		
		for (int i = 0; i < 20; i++) {

		
			DrawRectangle(cols[i].rectx, 0, 70, cols[i].h, DARKBLUE);
			DrawRectangle(cols[i].rectx, HEIGHT - cols[i].h2, 70, cols[i].h2, DARKBLUE);
			

			if (y > 100 && y < 760) {
			cols[i].rectx -= 2;
			}
		

			Rectangle pipecima = {cols[i].rectx, 0, 70, cols[i].h};
	       		Rectangle pipebaixo = {cols[i].rectx + 2, (HEIGHT - cols[i].h2) - 5, 70, cols[i].h2};

			DrawRectangleLinesEx(pipecima, 2.0, RED);
                        DrawRectangleLinesEx(pipebaixo, 2.0,  RED);
        	
			colisao1 = CheckCollisionRecs(flappyrec, pipecima);
                	colisao2 = CheckCollisionRecs(flappyrec, pipebaixo);

			if (colisao1) {
				
				DrawText(TextFormat("COLISÃO CIMA = %d", colisao1), 10, 130, 30, RED);


			}
		}


		EndMode2D();
		
		//Calcular tudo de novo

		DrawText(TextFormat("X = %f", x), 10, 10, 10,  ORANGE);
		DrawText(TextFormat("Y = %f", y), 10, 30, 10, ORANGE);
		DrawText(TextFormat("Gravidade = %f", gravity), 10, 50, 10, ORANGE);
		DrawText(TextFormat("VELOCIDADE = %f", ball_speed_y), 10, 70, 10, ORANGE);
		DrawText(TextFormat("SCROLL = %f", scroll2), 10, 90, 10, ORANGE);
		DrawText(TextFormat("Altura = %i || Largura = %i", GetScreenHeight(), GetScreenWidth()), 10, 110, 10, ORANGE);

		EndDrawing();
	//	printf("rectx = %f", cols[10].rectx);
	
	}
		UnloadTexture(fundo);
		UnloadTexture(fundo_chão);
		UnloadTexture(flappy);
		CloseWindow();
		
}

/* Problemas com o movimento da bola.
 * Sem conseguir detetar height
 * Gravidade ? */


