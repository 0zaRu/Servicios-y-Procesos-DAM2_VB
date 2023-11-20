#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

int instanciaProceso(int *nPid, int *fork);

void manejadorPING(int segnal){
    system("echo PING >> fichero15.txt");
}

void manejadorPONG(int segnal){
    system("echo PONG >> fichero15.txt");
}

int main(void){
    pid_t p[4], forkP2, forkP3;
    int fd12[2];
    pipe(fd12);

    p[1] = getpid();
    !instanciaProceso(&p[2], &forkP2) && instanciaProceso(&p[3], &forkP3);

    if(getpid() == p[1]){
        close(fd12[0]);
        char numACad[10];

        sprintf(numACad, "%d", forkP3);
        write(fd12[1], numACad, strlen(numACad));
        close(fd12[1]);
    }
    else if(getpid() == p[2]){
        close(fd12[1]);
        char buffer[10];
        read(fd12[0], buffer, sizeof(buffer));
        close(fd12[0]);

        forkP3 = atoi(buffer);

        signal(SIGUSR1, manejadorPONG);
        for(int i = 0; i < 10; i++){
            kill(forkP3, SIGUSR1);
            pause();
        }
        kill(forkP3, SIGTERM);
        pause();

    }
    else if(getpid() == p[3]){
        close(fd12[0]);
        close(fd12[1]);

        signal(SIGUSR1, manejadorPING);
        for(int i = 0; i < 10; i++){
            pause();
            kill(forkP2, SIGUSR1);
        }
    }

    return 0;
}

int instanciaProceso(int *nPid, int *forkeado){

    switch (*forkeado = fork()) {
        case -1:
            printf("Error durante la creación del proceso hijo\n");
            return -1;

        case 0:  // Proceso hijo
            *nPid = getpid();
            return 1;

        default:  // Proceso padre
            return 0;
    }
}