#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

void manejadorPING(int segnal){
    printf("PING\t");
}

void manejadorPONG(int segnal){
    printf("PONG\n");
}

int main(void){

    pid_t pHijo, pPadre = getpid();
    signal(SIGUSR1, manejadorPONG);
    signal(SIGUSR2, manejadorPING);

    switch ((pHijo = fork())) {
        case -1:
            printf("Error durante la creación del proceso hijo\n");
            return -1;

        case 0:  // Proceso hijo
            
            for(int i = 0; i < 10; i++){
                pause();
                kill(pPadre, SIGUSR2);
            }
            break;
        default:  // Proceso padre
            
            for(int i = 0; i < 10; i++){
                kill(pHijo, SIGUSR1);
                pause();
            }
        break;
    }

    while(wait(NULL) != -1);
    return 0;
}
