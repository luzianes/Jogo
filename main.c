#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"


//Define a posição inicial (x,y) da bola e seus incrementos (+1)
int x = 34, y = 12;
int incX = 1, incY = 1;


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


int main()
{
    static int ch = 0;
    int opcao;

    while (1){
        screenInit(1);
        keyboardInit();
        timerInit(50);

        screenGotoxy(30, 5);
        printf("######");

        printf ("Digite: 1 - Jogar ou 0 - Sair: ");
        scanf ("%d", &opcao);

        switch (opcao){
            case 1:
                /*while (ch!= 0){

                    printO (x, y);
                    screenUpdate();
                    //Verifica a entrada do usuário (tecla clicada)
                    //ch = variável que detecta a tecla pressionada
                    //---------------------------------------------> FALTA DESENVOLVER CÓDIGO P/ MOVIMENTAR RAQUETE.
                    //---------------------------------------------> AS RAQUETES VÃO SE MOVIMENTAR DE FORMA INDEPENDENTE?
                    if (keyhit())
                    {
                        ch = readch();

                        screenUpdate();
                    }

                    if (timerTimeOver() == 1)
                    {
                        //Verifica se houve colisão com a moldura (adaptação do código do prof. Tiago)

                        int newX = x + incX;
                        if (newX >= (MAXX - strlen("O") -1) || newX <= MINX+1) incX = -incX;
                        int newY = y + incY;
                        if (newY >= MAXY-1 || newY <= MINY+1) incY = -incY;



                        printO(newX, newY);



                        screenUpdate();
                    }

                }*/

            case 0:
                keyboardDestroy();
                screenDestroy();
                timerDestroy();

                return 0;

        }
    }



}