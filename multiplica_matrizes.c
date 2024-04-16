#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Matriz{
    int n; //variavel com a ordem da matriz
    int** matrix;
}TMATRIZ;

int** alocarMatriz(int);
void desalocarMatriz(TMATRIZ);
void lerMatriz(TMATRIZ*);
void imprimeMatriz(TMATRIZ*);
void multiplicaMatriz(TMATRIZ*, TMATRIZ*, TMATRIZ*);

int main(){
    TMATRIZ A;
    TMATRIZ B;
    int ordem = 0;

    scanf("%d", &ordem);
    A.n = ordem;
    B.n = ordem;
    A.matrix = alocarMatriz(ordem);
    B.matrix = alocarMatriz(ordem);
    lerMatriz(&A);
    lerMatriz(&B);

    TMATRIZ C;
    C.n = ordem;
    C.matrix = alocarMatriz(ordem);
    
    multiplicaMatriz(&A, &B, &C);

    printf("\n");
    printf("A matriz resultante e:");
    printf("\n");
    imprimeMatriz(&C);

 
    desalocarMatriz(A);
    desalocarMatriz(B);
    desalocarMatriz(C);
    return 0;
}

int** alocarMatriz(int ordem){
    int** matriz;
    matriz = (int**) malloc(ordem * sizeof(int*));

    for(int i = 0; i < ordem; i++)
        matriz[i] = (int*) malloc(ordem*sizeof(int));

    for(int i = 0; i < ordem; i++){
        for(int j = 0; j < ordem; j++){
            matriz[i][j] = 0;            
        }
    }
    return matriz;
}

void desalocarMatriz(TMATRIZ m){
    for(int i = 0; i < m.n; i++){
        free(m.matrix[i]);
    }
    free(m.matrix);
    m.matrix = NULL;
}

void lerMatriz(TMATRIZ* m){
    for(int i = 0; i < m->n; i++){
        for(int j = 0; j < m->n; j++){
            scanf("%d", &m->matrix[i][j]);
        }
    }
}

void imprimeMatriz(TMATRIZ* m){
    for(int i = 0; i < m->n; i++){
        for(int j = 0; j < m->n; j++){
            printf(" %d", m->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplicaMatriz(TMATRIZ* A, TMATRIZ* B, TMATRIZ* C){
    int ordem = A->n;
    for(int i = 0; i < ordem; i++){
        for(int j = 0; j < ordem; j++){
            int aux_soma = 0;
            for(int z = 0; z < ordem; z++){
                aux_soma += A->matrix[i][z] * B->matrix[z][j];
            }
            C->matrix[i][j] = aux_soma;
            aux_soma = 0;
        }
    }
}

