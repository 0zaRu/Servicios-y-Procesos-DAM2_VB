#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int instanciaProceso(pid_t *procesoHijo, pid_t *forkeo);

void signal

int main(void){

    pid_t p[6], fork3, fork4;
    p[1] = getpid();
    
    int fd23[2], fd56[2];
    
    if(instanciaProceso(&p[2], NULL)){ //Entra solo el 2 y crea al 3 y al 4
        pipe(fd23);

        !instanciaProceso(&p[3], &fork3) && instanciaProceso(&p[4], &fork4);
    
    }else{
        if(instanciaProceso(&p[5], NULL)){
            pipe(fd56);
            instanciaProceso(&p[6], NULL);
        }
    }

    if(getpid() == p[1]){

    } else if(getpid() == p[2]){
        close(fd23[0]);

        char envio[5];
        sprintf(envio, "%d", fork4);
        
        write(fd23[1], envio, sizeof(envio));
        close(fd23[1]);

    } else if(getpid() == p[3]){        //PING PONG ENTRE 3 Y 4
        close(fd23[1]);
        char buffer[5];

        read(fd23[0], buffer, sizeof(buffer));
        close(fd23[0]);
        
        fork4 = atoi(buffer);

    } else if(getpid() == p[4]){
        close(fd23[0]);
        close(fd23[1]);

    } else if(getpid() == p[5]){        //PIPES TANTO 5 COMO 6
        close(fd56[0]);

        char envio[] = "Hola hijo, de nombre 6";
        write(fd56[1], envio, strlen(envio));
        close(fd56[1]);

    } else if(getpid() == p[6]){
        close(fd56[1]);
        char buffer[30];

        read(fd56[0], buffer, sizeof(buffer));
        close(fd56[0]);

        printf("\nSoy el proceso 6, y he leido: %s\n", buffer);
    } 

    while(wait(NULL) != -1);

    return 0;
}

int instanciaProceso(pid_t *procesoHijo, pid_t *infoFork){
    int proceso;

    if(infoFork != NULL){
        *infoFork = fork();
        proceso = *infoFork;
    } else {
        proceso = fork();
    }
    
    switch (proceso)
    {
    case -1:
        printf("Error creando el proceso");
        return -1;
    
    case 0: //Proceso hijo
        *procesoHijo = getpid();
        return 1;

    default: //Proceso padre
        return 0;
    }
}