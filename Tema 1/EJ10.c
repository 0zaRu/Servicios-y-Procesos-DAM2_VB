//Codigo de Alberto Rodríguez

//Se utuliza true si es el proceso hijo y false si es el proceso padre

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int instanciaProceso(pid_t proceso, int nHijo, int *nPid);

int main (void){

    int fd1[2], fd2[2];
    pipe(fd1), pipe(fd2);

    pid_t p1, p2, p3;
    char buffer[50];
    
    //printf("Soy el proceso 1, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
    p1 = getpid();
    !instanciaProceso(fork(), 2, &p2) && !instanciaProceso(fork(), 3, &p3);

    if(getpid() == p1){
        
        close(fd1[0]);
        close(fd2[1]);

        //ENVIAMOS MENSAJE A P2
        char cadena1[] = "Hola hijo(2) soy papa(1)\0";
        write(fd1[1], cadena1, strlen(cadena1));

        //RECIBIMOS MENSAJE DE P2
        //waitpid(p2, NULL, 0);
        read(fd2[0], buffer, sizeof(buffer));
        printf("\n%s\n", buffer);

        //ENVIAMOS MENSAJE A P3
        char cadena2[] = "Hola hijo(3) soy papa(1)\0";
        write(fd1[1], cadena2, strlen(cadena2));
        close(fd1[1]);

        //RECIBIMOS MENSAJE DE P3
        //waitpid(p2, NULL, 3);
        read(fd2[0], buffer, sizeof(buffer));
        close(fd2[0]);

        printf("\n%s\n", buffer);
    
    }
    
    if(getpid() == p2){
    
        close(fd1[1]);
        close(fd2[0]);

        //RECIBIMOS MENSAJE DE P1
        read(fd1[0], buffer, sizeof(buffer));
        printf("\n%s\n", buffer);

        //ENVIAMOS MENSAJE A P1
        char cadena[] = "Hola papa(1) soy tu hijo(2)\0";
        write(fd2[1], cadena, strlen(cadena));
    
    }
    
    if(getpid() == p3){
        sleep(1);
        close(fd1[1]);
        close(fd2[0]);

        //RECIBIMOS MENSAJE DE P1
        read(fd1[0], buffer, sizeof(buffer));
        printf("\n%s\n", buffer);

        //ENVIAMOS MENSAJE A P1
        char cadena[] = "Hola papa(1) soy tu hijo(3)\0";
        write(fd2[1], cadena, strlen(cadena));
    }

    while(wait(NULL) != -1);

    //printf("\E[31mEl proceso %d termina \E[m \n", getpid());
    return 0;
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