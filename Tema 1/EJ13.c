//Codigo de Alberto Rodríguez

//Se utuliza true si es el proceso hijo y false si es el proceso padre

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int instanciaProceso(int *nPid, int fd[]);
void escribePipe(int fd[], int numero);
int leePipe(int fd[]);

int main (void){

    pid_t p1 = getpid(), p2, p3, p4, p5, p6, p7, p8, p9;
    int numero=0;

    if(mknod("./FIFO", __S_IFIFO | 0666, 0) == -1){
        
    }

    if(instanciaProceso(&p2)){                                   //A PARTIR DE AQUÍ ES SOLO PROCESO 2
        !instanciaProceso(&p5) && !instanciaProceso(&p6) && !instanciaProceso(&p7);

    
    }else{                                                              //A PARTIR DE AQUÍ ES SOLO PROCESO 1
        if(!instanciaProceso(&p3) && instanciaProceso(&p4))             //A PARTIR DE AQUÍ ES SOLO PROCESO 4
            if(instanciaProceso(&p8))                                   //A PARTIR DE AQUÍ ES SOLO PROCESO 8
                instanciaProceso(&p9)                                   //A PARTIR DE AQUÍ ES SOLO PROCESO 9
    }

    if(getpid() == p1){
        numero = 5;

        printf("El proceso 1 termina con el valor %d\n", numero);
    }else if(getpid() == p2){
        numero = 5;
         
        printf("El proceso 2 termina con el valor %d\n", numero);
    }else if(getpid() == p3){
        numero = 7;
    
        printf("El proceso 3 termina con el valor %d\n", numero);
    }else if(getpid() == p4){
        numero = 3;

        printf("El proceso 4 termina con el valor %d\n", numero);
    }else if(getpid() == p5){
        numero = 1;
        
        printf("El proceso 5 termina con el valor %d\n", numero);
    }else if(getpid() == p6){
        numero = 8;

        printf("El proceso 6 termina con el valor %d\n", numero);
    }else if(getpid() == p7){
        numero = 2;

        printf("El proceso 7 termina con el valor %d\n", numero);
    }else if(getpid() == p8){
        numero = 3;

        printf("El proceso 8 termina con el valor %d\n", numero);
    }else if(getpid() == p9){
        numero = 9;

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