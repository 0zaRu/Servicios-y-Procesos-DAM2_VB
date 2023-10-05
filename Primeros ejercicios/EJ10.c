#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 25
#define MIN 10

int pideEnteroRangValor(int, int);
void mostrarArray(int[]);
void rellenaArrayRand(int*);

int main(void)
{
    int tam1, tam2;
    bool correcto = false;

    printf("Introduce el tamano del primer array que vas a multiplicar: ");
    tam1 = pideEnteroRangValor(MIN, MAX);

    printf("Introduce el tamano del segundo array que vas a multiplicar: ");
    tam2 = pideEnteroRangValor(MIN, MAX);

    int v1[tam1], v2[tam2], vResult[tam1];

    rellenaArrayRand(v1);
    mostrarArray(v1);
    rellenaArrayRand(v2);
    mostrarArray(v2);

    printf("\n\n\n");

    for(int i = 0; i<tam1; i++)
        for(int j = 0; j<tam2; j++)
            vResult[i] += v1[i] * v2[j];

    mostrarArray(vResult);

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