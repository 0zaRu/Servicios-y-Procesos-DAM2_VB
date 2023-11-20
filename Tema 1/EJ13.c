//Codigo de Alberto Rodríguez
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int creaLos9Procesos(pid_t p[]);
int instanciaProceso(int *nPid);

int main (void){
    system("rm FIFO");

    pid_t p[10];
    int numero = creaLos9Procesos(p);

    if(getpid() == p[1]){
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
        printf("Proceso 1 termina con el valor: %d.\n\n\n", numero);
    }else{

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
    } 

    while(wait(NULL) != -1);
    return 0;
}


int creaLos9Procesos(pid_t p[]){
    p[1] = getpid();

    if(instanciaProceso(&p[2])) {                                       //A PARTIR DE AQUÍ ES SOLO PROCESO 2
        !instanciaProceso(&p[5]) && !instanciaProceso(&p[6]) && !instanciaProceso(&p[7]);

    }else{                                                              //A PARTIR DE AQUÍ ES SOLO PROCESO 1
        if(!instanciaProceso(&p[3]) && instanciaProceso(&p[4]))         //A PARTIR DE AQUÍ ES SOLO PROCESO 4
            if(instanciaProceso(&p[8]))                                 //A PARTIR DE AQUÍ ES SOLO PROCESO 8
                instanciaProceso(&p[9]);                                //A PARTIR DE AQUÍ ES SOLO PROCESO 9
    }

    //######################################################################################################

    if     (getpid() == p[1]) return 5;
    else if(getpid() == p[2]) return 5;
    else if(getpid() == p[3]) return 7;
    else if(getpid() == p[4]) return 3;
    else if(getpid() == p[5]) return 1;
    else if(getpid() == p[6]) return 8;
    else if(getpid() == p[7]) return 2;
    else if(getpid() == p[8]) return 3;
    else if(getpid() == p[9]) return 9;
}

int instanciaProceso(int *nPid){

    switch (fork()) {
        case -1:
            printf("Error durante la creación del proceso hijo\n");
            return -1;

        case 0:  // Proceso hijo
            *nPid = getpid();
            return 1;

        default:  // Proceso padre
            return 0;
    }
}