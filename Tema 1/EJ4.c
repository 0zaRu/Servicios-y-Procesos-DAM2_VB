#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){

    pid_t pid;
    int valor=10;

    pid = fork();
    switch(pid){
        case -1:
            printf("Error");
            exit(-1);

        case 0:     //HIJO
            valor-=2;        
            break;
        
        default:    //PADRE
            valor+=2;
    }
    printf("\nEl valor ha quedado en %d\n\n\n", valor);

    return 0;
}