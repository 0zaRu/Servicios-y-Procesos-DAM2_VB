//CODIGO DE ALBERTO RODRIGUEZ PEREZ
//EXAMEN DEL PRIMER TRIMESTRE DE DAM2C - 20/11/23

//IMPORTACIÓN DE BIBLIOTECAS
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//CREACIÓN DE PROCESOS
int instanciaProceso(int *proceso, int fd[]);
void escribePipe(int *fd, int numero, int tamBuffer);
int leePipe(int *fd);

//MAIN CON TODO EL EXAMEN
int main(void){
    //Lo primer es borrar FIFO en caso de que exista
    system("rm FIFO");

    //Comprobamos que tenemos acceso a un nuevo fichero FIFO
    if(mknod("FIFO", __S_IFIFO | 0666, 0) == -1){
        printf("Ha ocurrido un error ...\n");
        exit(-1);
    }

    //Creamos el cotenedor de PIDs (se que desperdicio p[0] pero así facilito la lectura), los fifo y el valor de numero
    pid_t p[5];
    int  fd2[2], fd3[2], fd4[2], numero = 2;
    int fp;
    
    //Asigno el PID del primer proceso
    p[1] = getpid();

    //CREO LOS PROCESOS Y LES ASIGNO UNA TUBERÍA DE COMUNICACIÓN (los sentidos de los fd no usados se borran en el metodo)
    !instanciaProceso(&p[2], fd2) && !instanciaProceso(&p[3], fd3) && instanciaProceso(&p[4], fd4);

    //COMUNICO LOS PROCESOS CON PIPES
    if(getpid() == p[1]){   //Entra el 1
        printf("Soy el proceso 1 con el pid %d\n", getpid());

        //suma todos los numeros recibidos de sus hijos (y cierra las tuberías en el metodo)
        numero += leePipe(&fd2[0]) + leePipe(&fd3[0]) + leePipe(&fd4[0]);

    } else if(getpid() == p[2]){    //Entra el 2
        printf("Soy el proceso 2 con el pid %d. Hijo de %d\n", getpid(), getppid());
        numero = 5;
        
        //Enviamos el numero a imprimir y el tamaño de buffer (3, porque hace falta poner el numero y \0 para acabar la cadena)
        escribePipe(&fd2[1], numero, 3);

    } else if(getpid() == p[3]){ //Entra el 3
        printf("Soy el proceso 3 con el pid %d. Hijo de %d\n", getpid(), getppid());
        numero = 11;

        //Cierro una tubería que quedó tras la creación de los métodos
        close(fd2[0]);

        //Enviamos el numero a imprimir y el tamaño de buffer (4, porque hace falta poner los 2 numeros (11) y \0 para acabar la cadena)
        escribePipe(&fd3[1], numero, 4);

    } else if(getpid() == p[4]){ //Entra el 4
        printf("Soy el proceso 4 con el pid %d. Hijo de %d\n", getpid(), getppid());
        numero = 6;

        //Cierro las 2 tuberías que quedaron tras la creación de métodos
        close(fd2[0]);
        close(fd3[0]);

        //Enviamos el numero a imprimir y el tamaño de buffer (3, porque hace falta poner el numero y \0 para acabar la cadena)
        escribePipe(&fd4[1], numero, 3);

    }

    //COMUNICO LOS PROCESOS CON FIFO (separo los if de pipe de los de fifo para claridad)
    if(getpid() == p[1]){   //entra el 1

        //Creo las variables necesarias para ver el fifo y el buffer de 1 (1 digito)
        int fp, bytesLeidos;
        char buffer[1];

        //Recorro el fifo hasta que he recibido 3 valores
        fp = open("FIFO", 0);
        for(int i = 0; i < 3;){        
            if(read(fp, buffer, sizeof(buffer)) != 0){
                printf("EL PROCESO 1 HA LEIDO: %s\n", buffer);
                i++;
            }
    }

    } else { //Entran el 2, 3 y 4
        sleep(1); //Este sleep es exclusivamente para que de tiempo a que se cree el fifo por parte del p1, no sería necesario para otra nada si fuesen 2 códigos separados
        
        //Creo la tubería para escribir en el fifo y envío los numeros de los procesos con 3 de tamaño de buffer (numero + \0)
        fp = open("FIFO", 1);

        //Los fp se cierran desde el proceso
        if(getpid() == p[2]) escribePipe(&fp, 2, 3);
        else if(getpid() == p[3]) escribePipe(&fp, 3, 3);
        else if(getpid() == p[4]) escribePipe(&fp, 4, 3);
        
        printf("El proceso %d ha escrito en el fifo\n", getpid());
    }


    //Dejamos este bucle para evitar procesos huérfanos
    while(wait(NULL) != -1);

    //Imprimimos qué procesos van a morir y con que numero
    printf("\tSoy el proceso %d y voy a morir con el valor %d\n", getpid(), numero);

    return 0;
}

/*
 * Metodo que recibe la tubería de escritura, el numero a enviar y el tamaño del buffer.
 * Limpia el buffer con memset, convierte el numero a cadena y lo escribe con la tubería, la cual cierra
*/
void escribePipe(int *fd, int numero, int tamBuffer){
    char buffer[tamBuffer];
    memset(buffer, 0, sizeof(buffer));

    sprintf(buffer, "%d", numero);
    write(*fd, buffer, strlen(buffer));
    close(*fd);
}

/*
 * Metodo que recibe la tubería de lectura.
 * Limpia el buffer (que es tamaño 4 para recibir hasya el numero 11), lo escribe con lo que lee en la tubería, la cierra y devuelve el numero como int
*/
int leePipe(int *fd){
    char buffer[4];
    memset(buffer, 0, sizeof(buffer));

    read(*fd, buffer, sizeof(buffer));
    close(*fd);

    return atoi(buffer);
}

/*
 * Método que recibe una posición donde almacenar el pid del hijo y el fd para crear la tubería.
 * Cierra las tuberías que no se van a usar y devuelve 1 (true) si es el hijo y 0 (false) si es el padre
*/
int instanciaProceso(int *proceso, int fd[]){
    pipe(fd);

    switch(fork()){
        case -1:
            printf("Error creando el proceso");
            return -1;
        case 0: //PROCESO HIJO
            close(fd[0]);
            *proceso = getpid();
            return 1;
        default: //PROCESO PADRE
            close(fd[1]);
            return 0;
    }
}