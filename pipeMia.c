#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void){
    pid_t pid1, pid2;

    int fd1_2[2];
    int fd2_1[2]; 
    int fd3_1[2];
    int fd1_3[2];

    char buffer [80] = "";
    char saludoToUno[] = "Hola 1 soy 2";
    char saludoToUnoBis[] = "Hola 1 soy 3";
    char saludoToDos[] = "Hola 2, soy 1";

    pipe(fd1_2);
    pipe(fd2_1);
    pipe(fd3_1);
    pipe(fd1_3);

    pid1=fork();

    switch(pid1){
        case -1:
            printf("Error"); 
            break;
        case 0: // hijo (2)
            
            printf("Proceso 2, PID %d\n", getpid());
            
            memset(buffer, 0, sizeof(buffer));
            
            read(fd1_2[0], buffer, sizeof(buffer)); // leemos el mensaje recibido de 1
            printf("Mensaje desde 1 hacia 2: %s\n", buffer);  

            write(fd2_1[1], saludoToUno, strlen(saludoToUno)); // escribimos el mensaje para 1

            break;
        default: // padre (1)

            pid2 = fork();

            switch(pid2){
                case -1:
                    printf("Error"); 
                    break;
                case 0: // hijo (3)
                    memset(buffer, 0, sizeof(buffer));
                    read(fd1_3[0], buffer, sizeof(buffer)); // leemos el mensaje recibido de 1

                    printf("Mensaje desde 1 hacia 3: %s\n", buffer);  

                    write(fd3_1[1], saludoToUnoBis, strlen(saludoToUnoBis)); // escribimos el mensaje para 1                 

                    break;
                default: // padre (1)
                    
                    printf("Proceso 1, PID %d\n", getpid());

                    write(fd1_2[1], saludoToDos, strlen(saludoToDos)); // escribimos el mensaje para 2

                    memset(buffer, 0, sizeof(buffer));
                    read(fd2_1[0], buffer, sizeof(buffer)); // leemos el mensaje recibido de 2
                    printf("Mensaje desde 2 hacia 1: %s\n", buffer); 

                    char saludoToTres[] = "Hola 3 soy 1\0";
                    write(fd1_3[1], saludoToTres, strlen(saludoToTres)); // escribimos el mensaje para 3
                    
                    memset(buffer, 0, sizeof(buffer));
                    read(fd3_1[0], buffer, sizeof(buffer)); // leemos el mensaje recibido de 3
                    printf("Mensaje desde 3 hacia 1: %s\n", buffer); 
                    
                    break;
            }
    }

   while((pid1 = wait(NULL))>0); 
}