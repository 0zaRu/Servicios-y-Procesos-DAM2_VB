#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 10
#define MIN 2

int pideEnteroRangValor(int, int);

int main(void)
{
    int tam1, tam2, tam3;
    bool correcto = false;

    printf("Introduce el largo de la primera matriz: ");
    tam1 = pideEnteroRangValor(MIN, MAX);

    printf("Introduce el ancho de la primera matriz: ");
    tam2 = pideEnteroRangValor(MIN, MAX);

    printf("Introduce el ancho de la segunda matriz: ");
    tam3 = pideEnteroRangValor(MIN, MAX);

    int v1[tam1][tam2], v2[tam2][tam3], vResult[tam1][tam3];

    for(int i = 0; i < tam1; i++)
        for(int j = 0; j < tam2; j++){
            v1[i][j] = rand()%10;

            for(int k = 0; k < tam3; k++)
                v2[j][k] = rand()%10;
        }

    printf("\n\nLa primera matriz: \n================================\n");
    for(int i=0; i<tam1; i++){
        for(int j=0; j < tam2; j++)
            printf("  %d", v1[i][j]);
        printf("\n");
    }

    printf("\n\nLa segunda matriz: \n================================\n");
    for(int i=0; i<tam2; i++){
        for(int j=0; j < tam3; j++)
            printf("  %d", v2[i][j]);
        printf("\n");
    }


    for(int i = 0; i < tam1; i++)
        for(int j = 0; j < tam3; j++){
            vResult[i][j] = 0;
        
            for(int k = 0; k < tam2; k++)
                vResult[i][j] += v1[i][k] * v2[k][j];
        }
    printf("\n\n\nLa matriz resultante: \n================================\n");
    for(int i=0; i<tam1; i++){
        for(int j=0; j < tam3; j++)
            printf("  %d", vResult[i][j]);
        printf("\n");
    }

    return 0;
}

int pideEnteroRangValor(int min, int max){

    int n;
    scanf("%d", &n);

    while(n<min || n>max){
        printf("Valor introducido fuera del rango de valores, debe estar entre %d y %d.\nIntroduce un nuevo numero: ", min, max);
        scanf("%d", &n);
    }

    return n;
}