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
void leeYMuestraPipe(int fd[], int cierraFdUso);

int main (void){

    int fd1[2], fd2[2], fd3[2];
    pipe(fd1), pipe(fd2), pipe(fd3);
    pid_t p1 = getpid(), p2, p3;
    char buffer[50];
    
    !instanciaProceso(fork(), 2, &p2) && !instanciaProceso(fork(), 3, &p3);
    
    if(getpid() == p1){
        escribePipe(fd1, "Hola hijo(2) soy papa(1)", 0);
        leeYMuestraPipe(fd2, 0);
        
        escribePipe(fd3, "Hola hijo(3) soy papa(1)", 1);
        leeYMuestraPipe(fd2, 1);
    
    }else if(getpid() == p2){
        close(fd3[0]);
        close(fd3[1]);     //No hay forma de evitarlo?
        leeYMuestraPipe(fd1, 1);
        escribePipe(fd2, "Hola papa(1) soy tu hijo(2)", 1);
    
    }else if(getpid() == p3){
        leeYMuestraPipe(fd3, 1);
        escribePipe(fd2, "Hola papa(1) soy tu hijo(3)", 1);
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

void leeYMuestraPipe(int fd[], int cierraFdUso){
    close(fd[1]);
    char buffer[50];

    int charLeidos = read(fd[0], buffer, sizeof(buffer));
    if(cierraFdUso)
        close(fd[0]);

    buffer[charLeidos] = '\0';
    printf("%s\n", buffer);
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