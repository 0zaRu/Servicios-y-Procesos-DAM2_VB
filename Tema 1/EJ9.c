#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (void){

    pid_t pr1, pr2, pr3, pr4, pr5, pr6, pr7, pr8, pr9;

    //Ahora mismo estoy en el proceso 1
    pr2 = fork();               //Creamos proceso 2
    

    
    while(wait(NULL) != -1);

    return 0;
}