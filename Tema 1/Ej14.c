#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int instanciaProceso(int *nPid);

int main(void){

    pid_t p[4];
    p[1] = getpid();
    !instanciaProceso(&p[2]) && !instanciaProceso(&p[3]);

    if(getpid() == p[2]){
        
    
    }else if(getpid() == p[3]){

    }

    while(wait(NULL) != -1);
    return 0;
}

int instanciaProceso(int *nPid){

    switch (fork()) {
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