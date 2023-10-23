#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (void){

    pid_t pr1, pr2, pr3, pr4, pr5, pr6, pr7, pr8, pr9;

    //Ahora mismo estoy en el proceso 1
    printf("Soy el proceso 1, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());

    pr2 = fork();               //Creamos proceso 2
    
    switch(pr2){
        case -1:
            printf("Error");
        break;
        
        case 0:                 //Soy el proceso 2 y creo el 5, 6 y 7
        
            printf("\tSoy el proceso 2, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());

            pr5 = fork();       //Creo el proceso 5

            switch(pr5){
                case -1:
                    printf("Error");
                break;

                case 0:         //Soy el proceso 5
                    printf("\t\tSoy el proceso 5, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
                break;

                default:        //Pasa el proceso 2 para crear 6 y 7

                    pr6 = fork();   //Creo el proceso 6

                    switch(pr6){
                        case -1:
                            printf("Error");
                        break;

                        case 0:     //Soy el proceso 6
                            printf("\t\tSoy el proceso 6, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
                        break;

                        default:    //Pasa el proceso 2 para crear el 7

                            pr7 = fork();   //Creo el proceso 7

                            switch(pr7){
                                case -1:
                                    printf("Error");
                                break;

                                case 0:     //Soy el proceso 7
                                    printf("\t\tSoy el proceso 7, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
                                break;

                                default:    //Pasa el proceso 2
                                break;
                            }
                        
                        break;
                    }
                break;
            }

        break;
        
        default:            //Pasa el proceso 1 y creamos el 3
        
            pr3 = fork();       //Creamos el proceso 3

            switch(pr3){
                case -1:
                    printf("Error");
                break;
                
                case 0:         //Soy el proceso 3
                    printf("\tSoy el proceso 3, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
                break;
                
                default:    //Pasa el proceso 1 y creamos el 4

                    pr4 = fork();   //Creamos el proceso 4

                    switch(pr4){
                        case -1:
                            printf("Error");
                        break;

                        case 0:     //Soy el proceso 4 y además creo el 8
                            printf("\tSoy el proceso 4, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
                            
                            pr8 = fork();   //Creo el proceso 8
                            switch(pr8){
                                case -1:
                                    printf("Error");
                                break;
                                
                                case 0:     //Soy el proceso 8 y además creo el 9
                                    printf("\t\tSoy el proceso 8, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
                                    
                                    pr9 = fork();   //Creo el proceso 9

                                    switch(pr9){
                                        case -1:
                                            printf("Error");
                                        break;
                                        
                                        case 0: //Soy el proceso 9
                                            printf("\t\t\tSoy el proceso 9, mi PID es %d y el PID de mi padre es %d\n", getpid(), getppid());
                                        break;
                                        
                                        default: //Soy el proceso 8
                                        break;

                                    }
                                break;
                                
                                default: //Soy el proceso 4
                                break;
                            }

                        break;

                        default: //Soy el proceso 1
                        break;

                    }

                break;
            }

        break;
    }
    
    while(wait(NULL) != -1);
    
    printf("\E[31mEl proceso %d termina \E[m \n", getpid());

    return 0;
}