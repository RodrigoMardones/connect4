#include "stdlib.h"
#include "stdio.h"
#include "headers.h"

//======================================================================================
//                              inicio juego !! 
//======================================================================================

int main(int argc,char *argv[]){
    char **m;
    FichaJuego J1;
    FichaJuego J2;
    printf("---------------------------------------------------\n");
    printf("Ingrese nombre Jugador 1: \n");
    scanf("%s",J1.nombre);
    fflush(stdin);
    printf("----------------------------------------------------\n");
    printf("Ingrese nombre Jugador 2: \n");
    scanf("%s",J2.nombre);
    fflush(stdin);
    m = iniciarTablero();
    jugar(m,&J1,&J2);
    free(m);   
}

//======================================================================================
//                                  fin juego !!
//======================================================================================