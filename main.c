#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

//Define a struct Raquete com seus elementos (typedef cria um alias (raquete))
typedef struct Raquete {
    int x, y;     // posição (x, y) da raquete
    int largura;  // largura da raquete
    int altura;   // altura da raquete
    char simbolo; // símbolo que forma a raquete
} raquete;

//Define a posição inicial (x,y) da bola e seus incrementos (+1)
int x = 34, y = 12;
int incX = 1, incY = 1;

//Cria variável com o número de raquetes
int qtde_raquete = 2;

//Função que movimenta a bola no terminal (adaptação do código do prof. Tiago)
void printO(int nextX, int nextY) //Letra "O"
{
    screenSetColor(CYAN, DARKGRAY);
    screenGotoxy(x, y);
    printf(" ");
    x = nextX;
    y = nextY;
    screenGotoxy(x, y);
    printf("O");
}

//Inicializa a raquete com seus parâmetros
void iniciar_raquete(raquete *rptr, int x, int y, int largura, int altura, char simbolo) {
    rptr->x = x;
    rptr->y = y;
    rptr->largura = largura;
    rptr->altura = altura;
    rptr->simbolo = simbolo;
}

//Função para imprimir a raquete na tela
void imprimir_raquete(raquete *rptr) {
    screenSetColor(MAGENTA, DARKGRAY);
    for (int i = 0; i < rptr->altura; i++) {
        screenGotoxy(rptr->x, rptr->y + i);

        printf("%c", rptr->simbolo);

    }
}

//Função para verificar se houve colisão com a raquete
int verificar_colisao(raquete *rptr, int Ox, int Oy) {
    for (int i = 0; i < rptr->altura; i++) {
        for (int j = 0; j < rptr->largura; j++) {
            if (Ox == rptr->x + j && Oy == rptr->y + i) {
                return 1; // Houve colisão com a raquete
            }
        }
    }
    return 0; // Não houve colisão com a raquete
}


int main()
{
    static int ch = 0;

    //Aloca memória para as raquetes
    raquete *rptr = (raquete*)malloc(qtde_raquete * sizeof(raquete));

    screenInit(1);
    keyboardInit();
    timerInit(50);

    printO(x, y);

    //Inicia as raquetes com a posição (x,y), largura, altura e símbolo
    iniciar_raquete(&rptr[0], 4, 10, 1, 5, '|');  // Raquete esquerda
    iniciar_raquete(&rptr[1], 76, 10, 1, 5, '|'); // Raquete direita

    screenUpdate();

    while (ch != 27) //Jogo ativo enquanto não teclar ESC
    {
        // Verifica a entrada do usuário (tecla clicada)
        //ch = variável que detecta a tecla pressionada
        // Desenvolver código para movimentar a raquete
        if (keyhit())
        {
            ch = readch();

            screenUpdate();
        }

        //Update game state (move elements, verify collision, etc)
        if (timerTimeOver() == 1)
        {
            //Verifica se houve colisão com a moldura (adaptação do código do prof. Tiago)

            int newX = x + incX;
            if (newX >= (MAXX -strlen("O") -1) || newX <= MINX+1) incX = -incX;
            int newY = y + incY;
            if (newY >= MAXY-1 || newY <= MINY+1) incY = -incY;

            // Verifica se houve colisão com as raquetes
            for (int i = 0; i < qtde_raquete; i++) {
                if (verificar_colisao(&rptr[i], newX, newY)) {
                    incX = -incX;
                    break;
                }
            }

            printO(newX, newY);

            for (int i = 0; i < qtde_raquete; i++) {
                imprimir_raquete(&rptr[i]);
            }

            screenUpdate();
        }
    }
    free (rptr);

    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}