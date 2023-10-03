#include <stdio.h>

int main(void){

    int num1;
    int num2;

    printf("Introduce el primero de los numeros: ");
    scanf("%d", &num1);

    printf("\nIntroduce el segundo de los  numeros: ");
    scanf("%d", &num2);

    printf("\n\nPosicion de memoria del numero 1: %p", &num1);
    printf(  "\nPosicion de memoria del numero 2: %p", &num2);

    printf("\n\nEl tamano en memoria del num 1 es %d y del num 2 es %d", sizeof(num1), sizeof(num2));
    printf("\n\nPodemos observar que la distancia en memoria entre las variables es igual al tamano de estas, por lo que están seguidas\n\n");
    
    return 0;
}