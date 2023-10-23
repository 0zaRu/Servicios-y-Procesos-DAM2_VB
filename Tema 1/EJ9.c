#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int instanciaProceso(pid_t proceso, int nHijo);

int main (void){
    
    printf("Soy el proceso 1, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
    
    if(instanciaProceso(fork(), 2)){
        !instanciaProceso(fork(), 5) && !instanciaProceso(fork(), 6) && !instanciaProceso(fork(), 7);

    }else{
        if(!instanciaProceso(fork(), 3) && instanciaProceso(fork(), 4))
            if(instanciaProceso(fork(), 8))
                instanciaProceso(fork(), 9);
    }

    while(wait(NULL) != -1);
    printf("\E[31mEl proceso %d termina \E[m \n", getpid());

    return 0;
}


int instanciaProceso(pid_t proc, int nH){

    switch(proc){
        case -1:
            printf("Error durante la creacion\n");
            break;
        case 0:     //Proceso hijo
            printf("Soy el proceso %d, mi PID es %d y el PID de mi padre es %d\n", nH, getpid(), getppid());
            return 1;
        default:
            return 0;
    }
}