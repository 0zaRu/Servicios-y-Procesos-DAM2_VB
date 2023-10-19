#include <stdio.h>
#include <unistd.h>

int main() {
    int valor = 10;
    pid_t pid_hijo, pid_nieto;

    pid_hijo = fork();
    if (pid_hijo == 0) {
        // Este es el proceso hijo
        valor -= 2;
        printf("Hijo: El valor es %d\n", valor);
        
        pid_nieto = fork();
        if (pid_nieto == 0) {
            // Este es el proceso nieto
            valor -= 2;
            printf("Nieto: El valor es %d\n", valor);
        }
    } else {
        // Este es el proceso padre
        valor -= 2;
        printf("Padre: El valor es %d\n", valor);
    }

    return 0;
}
