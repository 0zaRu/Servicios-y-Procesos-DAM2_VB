//Codigo de Alberto Rodríguez

//Se utuliza true si es el proceso hijo y false si es el proceso padre

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int instanciaProceso(int *nPid, int fd[]);
void escribePipe(int fd[], int numero);
int leePipe(int fd[]);

int main (void){

    pid_t p1 = getpid(), p2, p3, p4, p5, p6, p7, p8, p9;

    int fd12[2], fd13[2], fd14[2], fd25[2], fd26[2], fd27[2], fd48[2], fd89[2], numero=0;

    if(instanciaProceso(&p2, fd12)){                                    //A PARTIR DE AQUÍ ES SOLO PROCESO 2
        !instanciaProceso(&p5, fd25) && !instanciaProceso(&p6, fd26) && !instanciaProceso(&p7, fd27);
        
        if(getpid() != p2)
            close(fd12[1]);
    
    }else{                                                              //A PARTIR DE AQUÍ ES SOLO PROCESO 1
        if(!instanciaProceso(&p3, fd13) && instanciaProceso(&p4, fd14)) //A PARTIR DE AQUÍ ES SOLO PROCESO 4
            if(instanciaProceso(&p8, fd48)){                            //A PARTIR DE AQUÍ ES SOLO PROCESO 8
                close(fd14[1]);

                if(instanciaProceso(&p9, fd89))                         //A PARTIR DE AQUÍ ES SOLO PROCESO 9
                    close(fd48[1]);
            }
    }

    if(getpid() == p1){
        numero = 5;

        numero += leePipe(fd12) + leePipe(fd13) + leePipe(fd14);

        printf("El proceso 1 termina con el valor %d\n", numero);
    }else if(getpid() == p2){
        numero = 5;
     
        numero += leePipe(fd25) + leePipe(fd26) + leePipe(fd27);
        escribePipe(fd12, numero);
    
        printf("El proceso 2 termina con el valor %d\n", numero);
    }else if(getpid() == p3){
        close(fd12[0]);
        numero = 7;

        escribePipe(fd13, numero);

        printf("El proceso 3 termina con el valor %d\n", numero);
    }else if(getpid() == p4){
        close(fd12[0]);
        close(fd13[0]);
        numero = 3;

        numero += leePipe(fd48);
        escribePipe(fd14, numero);

        printf("El proceso 4 termina con el valor %d\n", numero);
    }else if(getpid() == p5){
        numero = 1;
        
        escribePipe(fd25, numero);

        printf("El proceso 5 termina con el valor %d\n", numero);
    }else if(getpid() == p6){
        close(fd25[0]);
        numero = 8;

        escribePipe(fd26, numero);

        printf("El proceso 6 termina con el valor %d\n", numero);
    }else if(getpid() == p7){
        close(fd25[0]);
        close(fd26[0]);
        numero = 2;

        escribePipe(fd27, numero);

        printf("El proceso 7 termina con el valor %d\n", numero);
    }else if(getpid() == p8){
        numero = 3;

        numero += leePipe(fd89);
        escribePipe(fd48, numero);

        printf("El proceso 8 termina con el valor %d\n", numero);
    }else if(getpid() == p9){
        numero = 9;
    
        escribePipe(fd89, numero);

        printf("El proceso 9 termina con el valor %d\n", numero);
    }


    while(wait(NULL) != -1);
    
    return 0;
}

void escribePipe(int fd[], int numero){
    char numACad[10];
    sprintf(numACad, "%d", numero);
    
    write(fd[1], numACad, strlen(numACad));
    close(fd[1]);
}

int leePipe(int fd[]){
    char buffer[10];
    memset(buffer, 0, sizeof(buffer));

    read(fd[0], buffer, sizeof(buffer));
    close(fd[0]);

    return atoi(buffer);
}

int instanciaProceso(int *nPid, int fd[]){
    pipe(fd);

    switch (fork()) {
        case -1:
            printf("Error durante la creación del proceso hijo\n");
            return -1;

        case 0:  // Proceso hijo
            close(fd[0]);
            *nPid = getpid();
            return 1;

        default:  // Proceso padre
            close(fd[1]);
            return 0;
    }
}