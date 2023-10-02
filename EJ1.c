#include <stdio.h>

int main(void){
    int num;

    printf("Introduce un numero para comparar respecto al 5: ");
    scanf("%d", &num);

    if(num > 5)
        printf("El numero introducido es mayor que 5");
    
    else if(num < 5)
        printf("El numero introducido es menor que 5");
    
    else
        printf("El numero introducido es 5");
        
    printf("\n\n\n");
    return 0;
}
