#include <stdio.h>

int main(void){

    int n1, n2, n3, var;

    printf("Introduce 3 numeros: ");
    scanf("%d%d%d", &n1, &n2, &n3);

    if(n1 < n3){
        var = n1;
        n1 = n3;
        n3 = var;
    }

    if(n1 < n2){
        var = n1;
        n1 = n2;
        n2 = var;
    }

    if(n2 < n3){
        var = n2;
        n2 = n3;
        n3 = var;
    }

    printf("Los numeros ordenados son:\nN1: %d\nN2: %d\nN3: %d", n1, n2, n3);
    
    return 0;
}