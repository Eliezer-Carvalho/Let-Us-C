#include "raylib.h"


int main(void)
{
	InitWindow(800, 450, "raylib [core] example - basic window"); //Começar uma janela!
	
	Camera3D pao  = { 0 }; //Camera3D é o nome da struct, obrigatoriamente tem que ser usado. Nem int, nem float, nem nada neste caso.
	Vector3 posicao = { 0, 0, 0};
	

	while (!WindowShouldClose()) //Loop que define 'Enquanto janela aberta..'
	{
		BeginMode3D(pao);
		ClearBackground(RAYWHITE);
           	DrawCube(posicao, 5, 5, 5, DARKGREEN);
	

		

		EndMode3D();
		EndDrawing();
	}

		CloseWindow();

		return 0;
}



