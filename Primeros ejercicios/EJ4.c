#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char menu(void);
int suma(int, int);
int resta(int, int);
int multiplicar(int, int);
int dividir(int, int);
void limpiar(void);

const char SUMAR = 'a';
const char RESTAR = 'b';
const char MULTI = 'c';
const char DIVI = 'd';
const char SALIR = 'e';

int main(void){

    bool salir = false;
    char respuesta;

    do{
        switch (menu()){
        case SUMAR:
            sumar(3, 4);
            break;

        case RESTAR:
            sumar(3, 4);
            break;
        
        case MULTI:
            sumar(3, 4);
            break;

        case DIVI:
            sumar(3, 4);
            break;
        
        case SALIR:

            printf("\nPulse enter para salir del programa ...");
            scanf("%c");
            salir = true;
            break;

        default:
            printf("\nSe ha introducido una respuesta erronea, vuelva a introducir otra valida ...\nEnter para continuar ...");
            scanf("%c");
            break;
        }

        limpiar();

    }while(!salir);

    return 0;
}

char menu(void){

    char respuesta;

    printf("===== Elige una operación =====");
    printf("\n||    %c. SUMAR               ||", SUMAR);
    printf("\n||    %c. RESTAR              ||", RESTAR);
    printf("\n||    %c. MULTIPLICAR         ||", MULTI);
    printf("\n||    %c. DIVIDIR             ||", DIVI);
    printf("\n||    %c. SALIR               ||", SALIR);
    printf("\n================================\n");
    printf("Introduce una opcion: ");
    scanf("%c", &respuesta);
    getchar();
    
    return respuesta;
}

int suma(int, int)
{
    return 0;
}

int resta(int, int)
{
    return 0;
}

int multiplicar(int, int)
{
    return 0;
}

int dividir(int, int)
{
    return 0;
}

void limpiar(void){
    if(_WIN32 || _WIN64)
        system("cls");
    
    else
        system("clear");
    
}