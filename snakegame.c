#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>





int main() {

const int altura = 11;
const int largura = 21;
int posicao_cobra_altura = altura / 2;
int posicao_cobra_largura = largura / 2;
int pontos = 0;
char tecla;
srand(time(NULL));
int food_x = 1 + rand() % (altura - 2);
int food_y = 1 + rand() % (largura - 2);


while (1) {


    system("cls"); /* clear, limpa para receber um novo input todas as vezes*/
    printf("Use W, A, S, D para mover a cobra! \n");
    printf("\n");
    printf("ALTURA: %d | LARGURA: %d \n", food_x, food_y);

    for (int i = 0; i < altura; i++) 
    {
        for (int j = 0; j < largura; j ++) 
        {

            if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) 
                printf(" # "); /* TABELA DE JOGO no eixo dos X e Y */

            else if (i == posicao_cobra_altura && j == posicao_cobra_largura) 
                printf(" o "); /* POSIÇÃO INICIAL DA COBRA QUE É O CENTRO DO TABULEIRO */
            
            else if (i == food_x && j == food_y)
                printf(" . "); /* posição aleatória da comida */
            
            else 
                printf("   "); /* VAZIO DENTRO DA TABELA  */
        
        }
        printf ("\n");
    }

    printf("SCORE: %d\n", pontos);

    tecla = getch();

    if (tecla == 'w') posicao_cobra_altura--;
    if (tecla == 's') posicao_cobra_altura++;
    if (tecla == 'a') posicao_cobra_largura--;
    if (tecla == 'd') posicao_cobra_largura++;
    if (tecla == 'b') break;


    if (posicao_cobra_altura == food_x && posicao_cobra_largura == food_y) 
    {
        food_x = 1 + rand() % (altura - 2);
        food_y = 1 + rand() % (largura - 2);
        pontos += 10;
    }
    
    
    if (posicao_cobra_altura == 0 || posicao_cobra_altura == altura - 1 || posicao_cobra_largura == 0 || posicao_cobra_largura == largura - 1) 
    {
        printf("Terminou o jogo! :)");
        break; 
    }


}

return 0;

}
