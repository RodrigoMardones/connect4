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
    if(argc > 4){
        printf("demasiados argumentos para el juego");
        return 0;
    }
    for(int i = 0;i < argc; i++){
        if(argv[i] == 'u' ){
            printf("---------------------------------------------------\n");
            printf("Ingrese nombre Jugador 1: \n");
            scanf("%s",J1.nombre);
            fflush(stdin);
        }
        if(argv[i] == 't'){
            printf("----------------------------------------------------\n");
            printf("Ingrese nombre Jugador 2: \n");
            scanf("%s",J2.nombre);
            fflush(stdin);
        }
        if(argv[i] == 'k'){
            printf("----------------------------------------------------\n");
            printf("Ingrese nombre Jugador 2: \n");
            scanf("%c",J1.tipo);
            fflush(stdin);
        }
        if(argv[i] == 'j'){
            printf("----------------------------------------------------\n");
            printf("Ingrese nombre Jugador 2: \n");
            scanf("%c",J2.tipo);
            fflush(stdin);
        }
    }
    m = iniciarTablero();
    jugar(m,&J1,&J2);
    free(m);   
}

//======================================================================================
//                                  fin juego !!
//======================================================================================