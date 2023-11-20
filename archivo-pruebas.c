#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

int instanciaProceso(pid_t *procesoHijo, pid_t *infoFork);
void manejadorPING(int segnal);
void manejadorPONG(int segnal);

int main(void){
    int numero, fd[2];

    //EJEMPLO DE CREACIÓN DE PROCESO    ===========================================     NUEVO PROCESO
    pid_t p[3], fork2, fork3;
    p[1] = getpid();

    !instanciaProceso(&p[2], fork2) && instanciaProceso(&p[3], &fork3);


    //EJEMPLO DE SELECCIÓN DE PROCESO   ===========================================     USO PROCESO
    if(getpid() == p[1]){

    }else if(getpid() == p[2]){

    }


    //EJEMPLO DE ESCRITURA CON PIPE     ===========================================     PIPE ESCRIBE
    char numACad[10];
    sprintf(numACad, "%d", numero);
    
    write(fd[1], numACad, strlen(numACad));
    close(fd[1]);


    //EJEMPLO DELECTURA CON PIPE        ===========================================     PIPE LEE
    char buffer[10];
    memset(buffer, 0, sizeof(buffer));

    read(fd[0], buffer, sizeof(buffer));
    close(fd[0]);

    int resultado = atoi(buffer);


    //EJEMPLO LECTURA FIFO              ===========================================     FIFO LEE
    system("rm FIFO");

    int fp, bytesLeidos;
    char buffer[1] = "";

    if(mknod("FIFO", __S_IFIFO | 0666, 0) == -1){
        printf("HA OCURRIDO UN ERROR ...\n");
        exit(-1);
    }

    fp = open("FIFO", 0);

    for(int i = 2; i <=9;){    
        if(read(fp, buffer, sizeof(buffer)) != 0){
            numero += atoi(buffer);
            i++;
        }
    }

    close(fp);

    
    //EJEMPLO ESCRITURA FIFO            ===========================================     FIFO ESCRIBE
    char numACad[3];
    sprintf(numACad, "%d", numero);

    sleep(1);
    int fp = open("FIFO", 1);

    if(fp == -1){
        printf("ERROR AL ABRIR EL FICHERO ...\n");
        exit(-1);
    }
    //printf("Envio el %d\n", numero);
    write(fp, numACad, strlen(numACad));
    close(fp);

    

    //ENVIO DE INFO DE PONG de 3 desde 1 hasta 2    =========================================
    close(fd[0]);
    char numACad[10];

    sprintf(numACad, "%d", fork3);
    write(fd[1], numACad, strlen(numACad));
    close(fd[1]);

    //EJEMPLO PING                      ===========================================     PING
    close(fd[1]);
    char buffer[10];
    read(fd[0], buffer, sizeof(buffer));
    close(fd[0]);

    fork3 = atoi(buffer);

    signal(SIGUSR1, manejadorPONG);
    for(int i = 0; i < 10; i++){
        kill(fork3, SIGUSR1);
        pause();
    }
    kill(fork3, SIGTERM);
    pause();

    //EJEMPLO PONG                      ===========================================     PONG
    signal(SIGUSR1, manejadorPING);
    for(int i = 0; i < 10; i++){
        pause();
        kill(fork2, SIGUSR1);
    }




    while(wait(NULL != -1));
    return 0;
}

void manejadorPING(int segnal){
    system("echo PING >> fichero15.txt");
}

void manejadorPONG(int segnal){
    system("echo PONG >> fichero15.txt");
}

int instanciaProceso(pid_t *procesoHijo, pid_t *infoFork){
    
    switch (*infoFork = fork())
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