#include <stdio.h>
#include <unistd.h>

int main() {
    int valor = 10;
    pid_t pid_hijo, pid_nieto;

    valor -= 2;
    
    pid_hijo = fork();
    if (pid_hijo == 0) {
        // Este es el proceso hijo
        printf("Hijo: El valor es %d\n", valor);
        valor -= 2;
        
        pid_nieto = fork();
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
