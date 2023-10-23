//Codigo de Alberto Rodríguez

//Se utuliza true si es el proceso hijo y false si es el proceso padre

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int instanciaProceso(pid_t proceso, int nHijo, int tab);

int main (void){
    
    printf("\tSoy el proceso 1, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
    
    if(instanciaProceso(fork(), 2, 2)){
        !instanciaProceso(fork(), 5, 3) && !instanciaProceso(fork(), 6, 3) && !instanciaProceso(fork(), 7, 3);

    }else{
        if(!instanciaProceso(fork(), 3, 2) && instanciaProceso(fork(), 4, 2))
            if(instanciaProceso(fork(), 8, 3))
                instanciaProceso(fork(), 9, 4);
    }

    while(wait(NULL) != -1);
    printf("\E[31mEl proceso %d termina \E[m \n", getpid());

    return 0;
}


int instanciaProceso(pid_t proc, int nH, int tab){

    switch(proc){
        case -1:
            printf("Error durante la creacion\n");
            break;
        case 0:     //Proceso hijo

            for(int i = 0; i < tab; i++)
                printf("\t");

            printf("Soy el proceso %d, mi PID es %d y el PID de mi padre es %d\n", nH, getpid(), getppid());
            return 1;
        default:    //Proceso padre
            return 0;
    }
}