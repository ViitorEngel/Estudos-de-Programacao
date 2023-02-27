#include <stdio.h>
#include <stdlib.h>

/*
Gerar uma matriz aleatória com o numero de colunas e linhas determinadas pelo usuário. 
O numero de colunas e linhas deve ser maior que 1 e menor ou igual a 10.
Os elementos da matriz devem ser aleatórios, entre 0 e um limite determinado pelo usuário (no máximo 1000)
A matrix deve ser printada de maneira direta a transposta.
*/

void matriz(int row, int col, int lim){
    int matrix [row][col];

    for (int i=0;i<row;i++){ //gerando numeros aleatórios
        for (int j=0;j<col;j++){
            matrix[i][j]=rand()%lim;
        }
    }

    //printando a matriz direta e transposta
    printf("\nMatriz:\n");
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz transposta:\n");
    for (int i=0;i<col;i++){
        for (int j=0;j<row;j++){
            printf("%d ",matrix[j][i]);
        }
        printf("\n");
    }
}

void main(){

int row=0, col=0, lim=0;

printf("Bem vindo ao gerador de matrizes!\n");

while (!(row>1 && row<=10)){ //pegando as linhas
    printf("\nDiga quantas linhas deve ter a matriz: "); scanf("%d",&row);
    if (row<=1 || row>10){
        printf("Insira um valor maior que 1 e menor ou igual a 10");
    }
}
while (!(col>1 && col<=10)){ //pegando as colunas
    printf("\nDiga quantas colunas deve ter a matriz: "); scanf("%d",&col);
    if (col<=1 || col>10){
        printf("Insira um valor maior que 1 e menor ou igual a 10");
    }
}
while (!(lim>1 && lim<=1000)){ //pegando os limites de geração
    printf("\nDiga os limites de geração dos valores: "); scanf("%d",&lim);
    if (lim<=1 || lim>1000){
        printf("Insira um valor maior que 1 e menor ou igual a 1000");
    }
}

matriz(row,col,lim);

}
