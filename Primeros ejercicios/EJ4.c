#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char menu(void);
float suma(float, float);
float resta(float, float);
float multiplicar(float, float);
float dividir(float, float);
void limpiar(void);

const char SUMAR = 'a';
const char RESTAR = 'b';
const char MULTI = 'c';
const char DIVI = 'd';
const char SALIR = 'e';
const int LINEAS = 25;

int main(void){

    bool salir = false;
    char respuesta;
    float num1, num2;

    do{
        respuesta = menu();
        limpiar();

        switch (respuesta){
        case 'a':
            printf("Introduce el primer numero a sumar: ");
            scanf("%f", &num1);

            printf("\nIntroduce el segundo numero a sumar: ");
            scanf("%f", &num2);

            printf("\n\nEl resultado de '%g + %g' es igual a %g", num1, num2, suma(num1, num2));

            break;

        case 'b':
            printf("Introduce el primer numero a restar: ");
            scanf("%f", &num1);

            printf("\nIntroduce el segundo numero a restar: ");
            scanf("%f", &num2);

            printf("\n\nEl resultado de '%g - %g' es igual a %g", num1, num2, resta(num1, num2));
            break;
        
        case 'c':
            printf("Introduce el primer numero a multiplicar: ");
            scanf("%f", &num1);

            printf("\nIntroduce el segundo numero a multiplicar: ");
            scanf("%f", &num2);

            printf("\n\nEl resultado de '%g x %g' es igual a %g", num1, num2, multiplicar(num1, num2));
            break;

        case 'd':
            printf("Introduce el dividendo: ");
            scanf("%f", &num1);

            printf("\nIntroduce el sdivisor: ");
            scanf("%f", &num2);

            printf("\n\nEl resultado de '%g / %g' es igual a %g", num1, num2, dividir(num1, num2));
            break;
        
        case 'e':

            printf("\nVa salir del programa ...");
            salir = true;
            break;

        default:
            printf("\nSe ha introducido una respuesta erronea, vuelva a introducir otra valida ...");
            
            break;
        }

        printf("\n\nEnter para continuar ...");
        getchar();
        getchar();

        limpiar();

    }while(!salir);

    return 0;
}

char menu(void){

    char respuesta;

    printf("===== Elige una operación =====");
    printf("\n||                           ||");
    printf("\n||    %c. SUMAR               ||", SUMAR);
    printf("\n||    %c. RESTAR              ||", RESTAR);
    printf("\n||    %c. MULTIPLICAR         ||", MULTI);
    printf("\n||    %c. DIVIDIR             ||", DIVI);
    printf("\n||    %c. SALIR               ||", SALIR);
    printf("\n||                           ||");
    printf("\n===============================\n");
    printf("Introduce una opcion: ");
    scanf("%c", &respuesta);
    
    return respuesta;
}

float suma(float n1, float n2)
{
    return n1+n2;
}

float resta(float n1, float n2)
{
    return n1-n2;
}

float multiplicar(float n1, float n2)
{
    return n1*n2;
}

float dividir(float n1, float n2)
{
    return n1/n2;
}

void limpiar(void){
    system("clear");

    //for(int i = 0; i < LINEAS; i++)
    //    printf("\n");
}