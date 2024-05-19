#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

typedef struct Raquete {
    int x, y;     // posição (x, y) da raquete
    int altura;   // altura da raquete
    char simbolo;  // símbolo
} raquete;

int x = 34, y = 12;
int incX = 1, incY = 1;
int qtde_raquete = 2;

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

void iniciar_raquete(raquete *rptr, int x, int y, int altura, char simbolo) {
    rptr->x = x;
    rptr->y = y;
    rptr->altura = altura;
    rptr->simbolo = simbolo;
}

void imprimir_raquete(raquete *rptr) {
    screenSetColor(CYAN, DARKGRAY);
    for (int i = 0; i < raquete->altura; i++) {
        screenGotoxy(raquete->x, raquete->y + i);
        printf("%c", raquete->simbolo);
    }
}

int main()
{
    static int ch = 0;

    raquete *rptr = (raquete*)malloc(qtde_raquete * sizeof(raquete));

    screenInit(1);
    keyboardInit();
    timerInit(50);

    printO(x, y);

    iniciar_raquete(&rptr[0], 2, 10, 4, '|');  // Raquete esquerda
    iniciar_raquete(&rptr[1], 77, 10, 4, '|'); // Raquete direita

    screenUpdate();

    while (ch != 27) //Jogo ativo enquanto não teclar ESC
    {
        // Handle user input
        if (keyhit())
        {
            ch = readch();

            screenUpdate();
        }

        // Update game state (move elements, verify collision, etc)
        if (timerTimeOver() == 1)
        {
            int newX = x + incX;
            if (newX >= (MAXX -strlen("O") -1) || newX <= MINX+1) incX = -incX;
            int newY = y + incY;
            if (newY >= MAXY-1 || newY <= MINY+1) incY = -incY;

            for (int i = 0; i < qtde_raquete; i++) {
                imprimir_raquete(&rptr[i]);
            }

            printO(newX, newY);

            screenUpdate();
        }
    }
    free (rptr);

    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}