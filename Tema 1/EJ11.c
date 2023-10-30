//Codigo de Alberto Rodríguez

//Se utuliza true si es el proceso hijo y false si es el proceso padre

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int instanciaProceso(pid_t proceso, int nHijo, int *nPid);
void escribePipe(int fd[], char cadena[], int cierraFdUso);
int leePipe(int fd[], int cierraFdUso);

int main (void){

    pid_t p1, p2, p3, p4, p5, p6, p7, p8, p9;
    char numACad[10];

    int fd1[2], fd2[2], fd3[2], fd4[2], numero=0;
    pipe (fd1);
    
    //printf("Soy el proceso 1, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
    p1 = getpid();

    if(instanciaProceso((fork()), 2, &p2)){
        pipe(fd2);

        !instanciaProceso(fork(), 5, &p5) && !instanciaProceso(fork(), 6, &p6) && !instanciaProceso(fork(), 7, &p7);

    }else{
        if(!instanciaProceso(fork(), 3, &p3) && instanciaProceso(fork(), 4, &p4)){
            pipe(fd3);
            if(instanciaProceso(fork(), 8, &p8)){
                pipe(fd4);
                instanciaProceso(fork(), 9, &p9);
            }
        }
    }

    if(getpid() == p1){
    /*    numero = 5;
        int leido = leePipe(fd1, 0);
        printf("Soy el 1, he leido un %d\n", leido);
        numero += leido;

        leido = leePipe(fd1, 0);
        printf("Soy el 1, he leido un %d\n", leido);
        numero += leido;
        
        leido = leePipe(fd1, 0);
        printf("Soy el 1, he leido un %d\n", leido);
        numero += leido;

        printf("\E[31mEl proceso 1 termina con el valor %d (43)\E[m \n", numero);
    */
    }else if(getpid() == p2){
        numero = 5;

        waitpid(p5, NULL, 0);
        numero += leePipe(fd2, 0);
        
        waitpid(p6, NULL, 0);
        numero += leePipe(fd2, 0);
        
        waitpid(p7, NULL, 0);
        numero += leePipe(fd2, 0);

        sprintf(numACad, "%d", numero);
        escribePipe(fd1, numACad, 0);
    
        printf("\E[31mEl proceso 2 termina con el valor %d (16)\E[m \n", numero);

    }else if(getpid() == p3){
        numero = 7;
        /*
        sprintf(numACad, "%d", numero);
        escribePipe(fd1, numACad, 0);

        printf("El proceso 3 termina con el valor %d\n", numero);
    */
    }else if(getpid() == p4){
        numero = 3;
    /*
        numero += leePipe(fd3, 1);

        sprintf(numACad, "%d", numero);
        escribePipe(fd1, numACad, 1);

        printf("El proceso 4 termina con el valor %d\n", numero);
    */
    }else if(getpid() == p5){
        numero = 1;
    
        sprintf(numACad, "%d", numero);
        escribePipe(fd2, numACad, 1);

        printf("El proceso 5 termina con el valor %d\n", numero);
    
    }else if(getpid() == p6){
        numero = 8;

        sprintf(numACad, "%d", numero);
        escribePipe(fd2, numACad, 1);

        printf("El proceso 6 termina con el valor %d\n", numero);
    
    }else if(getpid() == p7){
        numero = 2;

        sprintf(numACad, "%d", numero);
        escribePipe(fd2, numACad, 1);

        printf("El proceso 7 termina con el valor %d\n", numero);

    }else if(getpid() == p8){
        numero = 3;
    /*
        wait(NULL);
        numero += leePipe(fd4, 0);

        sprintf(numACad, "%d", numero);
        escribePipe(fd3, numACad, 0);

        printf("El proceso 8 termina con el valor %d\n", numero);
    */
    }else if(getpid() == p9){
        numero = 9;
    /*
        sprintf(numACad, "%d", numero);
        escribePipe(fd4, numACad, 0);

        printf("El proceso 9 termina con el valor %d\n", numero);
    */
    }


    while(wait(NULL) != -1);
    return 0;
}

void escribePipe(int fd[], char cadena[], int cierraFdUso){
    close(fd[0]);
    write(fd[1], cadena, strlen(cadena));
    
    if(cierraFdUso)
        close(fd[1]);
}

int leePipe(int fd[], int cierraFdUso){
    close(fd[1]);
    char buffer[10];

    read(fd[0], buffer, sizeof(buffer));
    if(cierraFdUso)
        close(fd[0]);
    
    return atoi(buffer);
}

int instanciaProceso(pid_t proc, int nH, int *nPid){
    
    switch(proc){
        case -1:
            printf("Error durante la creacion\n");
            break;

        case 0:     //Proceso hijo
            *nPid = getpid();
            //printf("Soy el proceso %d, mi PID es %d y el PID de mi padre es %d\n", nH, getpid(), getppid());
            return 1;

        default:    //Proceso padre
            return 0;
    }
}