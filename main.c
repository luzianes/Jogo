#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"


//Define a posição inicial (x,y) da bola e seus incrementos (+1)
int x = 34, y = 12;
int incX = 1, incY = 1;

void nome_jogo() {
    void desenhaTexto() {
        // letras de "Pixel Pong"

        // Letra P
        gotoxy(3,3);
        printf("###########");
        gotoxy(3,4);
        printf("###########");
        gotoxy(3,5);
        printf("###     ###");
        gotoxy(3,6);
        printf("###     ###");
        gotoxy(3,7);
        printf("###########");
        gotoxy(3,8);
        printf("###########");
        gotoxy(3,9);
        printf("###");
        gotoxy(3,10);
        printf("###");
        gotoxy(3,11);
        printf("###");

        // Letra i
        gotoxy(16,3);
        printf("###");
        gotoxy(16,4);
        printf("###");
        gotoxy(16,5);
        printf("###");
        gotoxy(16,6);
        printf("###");
        gotoxy(16,7);
        printf("###");
        gotoxy(16,8);
        printf("###");
        gotoxy(16,9);
        printf("###");
        gotoxy(16,10);
        printf("###");
        gotoxy(16,11);
        printf("###");

        // Letra x
        gotoxy(24,3);
        printf("###     ###");
        gotoxy(24,4);
        printf(" ###   ### ");
        gotoxy(24,5);
        printf("  ### ###  ");
        gotoxy(24,6);
        printf("   #####   ");
        gotoxy(24,7);
        printf("    ###    ");
        gotoxy(24,8);
        printf("   #####   ");
        gotoxy(24,9);
        printf("  ### ###  ");
        gotoxy(24,10);
        printf(" ###   ### ");
        gotoxy(24,11);
        printf("###     ###");

        // Letra e
        gotoxy(37,3);
        printf("###########");
        gotoxy(37,4);
        printf("###########");
        gotoxy(37,5);
        printf("###");
        gotoxy(37,6);
        printf("###");
        gotoxy(37,7);
        printf("###########");
        gotoxy(37,8);
        printf("###########");
        gotoxy(37,9);
        printf("###");
        gotoxy(37,10);
        printf("###");
        gotoxy(37,11);
        printf("###########");
        gotoxy(37,12);
        printf("###########");

        // Letra l
        gotoxy(50,3);
        printf("###");
        gotoxy(50,4);
        printf("###");
        gotoxy(50,5);
        printf("###");
        gotoxy(50,6);
        printf("###");
        gotoxy(50,7);
        printf("###");
        gotoxy(50,8);
        printf("###");
        gotoxy(50,9);
        printf("###");
        gotoxy(50,10);
        printf("###");
        gotoxy(50,11);
        printf("###########");
        gotoxy(50,12);
        printf("###########");

        // Letra P
        gotoxy(3,15);
        printf("###########");
        gotoxy(3,16);
        printf("###########");
        gotoxy(3,17);
        printf("###     ###");
        gotoxy(3,18);
        printf("###     ###");
        gotoxy(3,19);
        printf("###########");
        gotoxy(3,20);
        printf("###########");
        gotoxy(3,21);
        printf("###");
        gotoxy(3,22);
        printf("###");
        gotoxy(3,23);
        printf("###");

        // Letra o
        gotoxy(16,15);
        printf("###########");
        gotoxy(16,16);
        printf("###########");
        gotoxy(16,17);
        printf("###     ###");
        gotoxy(16,18);
        printf("###     ###");
        gotoxy(16,19);
        printf("###     ###");
        gotoxy(16,20);
        printf("###     ###");
        gotoxy(16,21);
        printf("###     ###");
        gotoxy(16,22);
        printf("###########");
        gotoxy(16,23);
        printf("###########");

        // Letra n
        gotoxy(29,15);
        printf("###       ###");
        gotoxy(29,16);
        printf("###       ###");
        gotoxy(29,17);
        printf("###       ###");
        gotoxy(29,18);
        printf("###       ###");
        gotoxy(29,19);
        printf("###       ###");
        gotoxy(29,20);
        printf("###       ###");
        gotoxy(29,21);
        printf("###       ###");
        gotoxy(29,22);
        printf("###       ###");
        gotoxy(29,23);
        printf("###       ###");
        gotoxy(30,15);
        printf("###");
        gotoxy(31,16);
        printf("###");
        gotoxy(32,17);
        printf("###");
        gotoxy(33,18);
        printf("###");
        gotoxy(34,19);
        printf("###");
        gotoxy(35,20);
        printf("###");
        gotoxy(36,21);
        printf("###");
        gotoxy(37,22);
        printf("###");
        gotoxy(38,23);
        printf("###");

        // Letra g
        gotoxy(44,15);
        printf("###########");
        gotoxy(44,16);
        printf("###########");
        gotoxy(44,17);
        printf("###        ");
        gotoxy(44,18);
        printf("###   #####");
        gotoxy(44,19);
        printf("###   #####");
        gotoxy(44,20);
        printf("###     ###");
        gotoxy(44,21);
        printf("###     ###");
        gotoxy(44,22);
        printf("###########");
        gotoxy(44,23);
        printf("###########");

        // Texto de comando
        gotoxy(10, 25);
        printf("Digite: 1 - Jogar ou 0 - Sair: ");
    }
}
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


    screenInit(1);
    keyboardInit();
    timerInit(50);


    nome_jogo()
    scanf ("%d", &opcao);

    if (opcao == 0) {
        keyboardDestroy();
        screenDestroy();
        timerDestroy();
        return 0;
    }



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




    }



}