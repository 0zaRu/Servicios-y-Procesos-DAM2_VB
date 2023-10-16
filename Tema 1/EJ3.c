#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){

    pid_t pid;

    pid = fork();
    switch(pid){
        case -1:
            printf("Error a la hora de hacer la division");
            exit(-1);

        case 0:     //HIJO
            printf("\nSoy el proceso hijo ...\n\n");
            system("ls /home/adrian/Escritorio > salidaEjercicioTres.txt");
            break;

        default:    //PADRE
            wait(NULL);
            printf("\nSoy el proceso padre ...\n\n");
            system("ls /run >> salidaEjercicioTres.txt");
    }

    return 0;
}