//Codigo de Alberto Rodríguez

//Se utuliza true si es el proceso hijo y false si es el proceso padre

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int instanciaProceso(pid_t proceso, int nHijo, int *nPid);

int main (void){

    pid_t p1, p2, p3, p4, p5, p6, p7, p8, p9;
    
    printf("Soy el proceso 1, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
    p1 = getpid();

    if(instanciaProceso((fork()), 2, &p2)){
        !instanciaProceso(fork(), 5, &p5) && !instanciaProceso(fork(), 6, &p6) && !instanciaProceso(fork(), 7, &p7);

    }else{
        if(!instanciaProceso(fork(), 3, &p3) && instanciaProceso(fork(), 4, &p4))
            if(instanciaProceso(fork(), 8, &p8))
                instanciaProceso(fork(), 9, &p9);
    }

    while(wait(NULL) != -1);
    printf("\E[31mEl proceso %d termina \E[m \n", getpid());
    return 0;
}


int instanciaProceso(pid_t proc, int nH, int *nPid){
    switch(proc){
        case -1:
            printf("Error durante la creacion\n");
            break;

        case 0:     //Proceso hijo
            *nPid = getpid();
            printf("Soy el proceso %d, mi PID es %d y el PID de mi padre es %d\n", nH, getpid(), getppid());
            return 1;

        default:    //Proceso padre
            return 0;
    }
}