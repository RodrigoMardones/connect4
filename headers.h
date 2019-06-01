#define COLS 7
#define ROWS 6

//archivos de cabecera del proyecto
#define ROWS 6
#define COLS 7
//======================================================================================
//                               definicion de ficha
//======================================================================================
struct Ficha{
    char nombre[10];
    char tipo;
};

typedef struct Ficha FichaJuego;

//======================================================================================
//======================================================================================

char **iniciarTablero(){
    char **matriz;    
    matriz = (char **) malloc(sizeof(char*)*ROWS);
    for(int i=0;i<7;i++){
        matriz[i] = (char *) malloc(sizeof(char)*COLS);
    }
    for(int j=0;j<ROWS;j++){
        for(int k=0;k<COLS;k++){
           matriz[j][k] = 'O';
        }
    }
    return matriz;
}
//======================================================================================
//======================================================================================

void mostrarTablero(char **matriz){
    printf("----------------------\n");
    for(int i = 0;i<ROWS;i++){
        for(int j = 0;j<COLS;j++){
            if(j == 6){
                printf("|%c|\n",matriz[i][j]);
            }else{
                printf("|%c|",matriz[i][j]);
            }
        }
    }
    printf("----------------------\n");
}

int checkizquierda(char **board,int row,int col,char ficha){
    if(col<0){
        return 0;
    }
    if(board[row][col] != ficha){
        return 0;
    }
    return 1 + checkizquierda(board,row,col-1,ficha);
}
int checkderecha(char **board,int row,int col,char ficha){
    if(col>7){
        return 0;
    }
    if(board[row][col] != ficha){
        return 0;
    }
    return 1 + checkderecha(board,row,col+1,ficha);
}
int checkhorizontal(char **board,int row,int col,char ficha){
    int IZQ  = checkizquierda(board,row,col,ficha);
    int DER  = checkderecha(board,row,col,ficha);
    int val = IZQ + DER -1;
    return val >= 4;
}


//=============================================================================
//                      check vertical
//=============================================================================
int checkvertical(char **board,int row,int col,char ficha){
    if(row<0){
        return 0;
    }
    if(board[row][col] != ficha){
        return 0;
    }
    return 1 + checkvertical(board,row+1,col,ficha);
}
//=============================================================================
//                      check diagonales
//=============================================================================

int checkdiagonal1(char **board,int row,int col,char ficha){
    if(row<0 || col>7){
        return 0;
    }
    if(board[row][col] != ficha){
        return 0;
    }
    return 1 + checkdiagonal1(board,row+1,col+1,ficha);
}
int checkdiagonal2(char **board,int row,int col,char ficha){
    if(row<0 || col>7){
        return 0;
    }
    if(board[row][col] != ficha){
        return 0;
    }
    return 1 + checkdiagonal2(board,row-1,col-1,ficha);
}
int checkdiagonal3(char **board,int row,int col,char ficha){
    if(row<0 || col>7){
        return 0;
    }
    if(board[row][col] != ficha){
        return 0;
    }
    return 1 + checkdiagonal3(board,row+1,col-1,ficha);
}
int checkdiagonal4(char **board,int row,int col,char ficha){
    if(row<0 || col>7){
        return 0;
    }
    if(board[row][col] != ficha){
        return 0;
    }
    return 1 + checkdiagonal4(board,row-1,col+1,ficha);
}

int checkdiagonales(char **board,int row,int col, char ficha){
    int d1,d2,d3,d4;
    d1 = checkdiagonal1(board,row,col,ficha);
    d2 = checkdiagonal2(board,row,col,ficha);
    d3 = checkdiagonal3(board,row,col,ficha);
    d4 = checkdiagonal4(board,row,col,ficha);
    int dp = d1 + d2 -1;
    int di = d3 + d4 -1;
    return dp>=4 || di>=4;
}

//======================================================================================
//                            REVISA GANADOR
//======================================================================================
int revisarGanador(char **matriz,int row,int col,char jugador){
    int h = 0;
    int v = 0;
    int d = 0;
    h = checkhorizontal(matriz,row,col,jugador);
    v = checkvertical(matriz,row,col,jugador);
    d = checkdiagonales(matriz,row,col,jugador);
    if(v == 4 || h == 1 || d == 1){
        return 4;
    }
}



//======================================================================================
//                                      JUGAR TURNO
//======================================================================================

int jugarturno(char**matriz,char jugador){
    int choice = 0;
    int h = 0;
    int v = 0;
    int d = 0;
    printf("escoja un numero del 1 al 7: ");
    while(1){
        scanf("%d",&choice);
        if(choice>7 || choice<1){
            printf("Te saliste del tablero,escoje otra vez: ");
        }
        else{
            break;
        }
    }
    choice-=1;  
    for(int i=ROWS-1;i>=0;i--){

        if(matriz[i][choice] == 'O'){
            matriz[i][choice] = jugador;
            if(revisarGanador(matriz,i,choice,jugador) == 4 ){
                return 4;
            }
            fflush(stdin);
            return 1;
        }
    }
    fflush(stdin);
    return 0;
}

//======================================================================================
//                                     JUGAR
//======================================================================================

int jugar(char **matriz, FichaJuego *J1, FichaJuego *J2){
    int fichas = 42;
    J1->tipo = J1->nombre[0];
    J2->tipo = J2->nombre[0];
    while(fichas>0){
        mostrarTablero(matriz);
        while(1){
            int turnocompleto;
            turnocompleto = jugarturno(matriz,J1->tipo);
            if(turnocompleto == 1 ){
                fichas--;
                mostrarTablero(matriz);
                //system("clear");
                break;
            }
            if(turnocompleto == 0){
                printf("columna llena,intenta con otra !\n");
            }
            if(turnocompleto == 4){
                mostrarTablero(matriz);
                printf("jugador %s ha ganado la partida !!\n",J1->nombre);
                return 0;
            }
        }
        while(1){
            int turnocompleto;
            turnocompleto = jugarturno(matriz,J2->tipo);
            if(turnocompleto == 1 ){
                fichas--;
                mostrarTablero(matriz);
                //system("clear");
                break;
            }
            if(turnocompleto == 0){
                printf("columna llena,intenta con otra !\n");
            }
            if(turnocompleto == 4){
                mostrarTablero(matriz);
                printf("jugador %s ha ganado la partida !!",J1->nombre);
                return 0;
            }
        }
    }
    if(fichas == 0){
        printf("EMPATE:JUEGO TERMINADO\n");
    }
}
//=====================================================================================
//                                  fin programa
//=====================================================================================