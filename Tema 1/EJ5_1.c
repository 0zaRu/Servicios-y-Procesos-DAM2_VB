//Ejercicio 5.1 de Alberto Rodríguez

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int valor = 10;
    pid_t pid_hijo, pid_nieto;

    pid_hijo = fork();
    valor -= 2;

    if (pid_hijo == 0) {
        // Este es el proceso hijo
        printf("Hijo: El valor es %d\n", valor);
        
        pid_nieto = fork();
        valor -= 2;

        if (pid_nieto == 0) {
            // Este es el proceso nieto
            printf("Nieto: El valor es %d\n", valor);
        }
    } else {
        // Este es el proceso padre
        printf("Padre: El valor es %d\n", valor);
    }

    return 0;
}
