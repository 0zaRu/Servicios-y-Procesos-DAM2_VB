#include <unistd.h>
#include <stdio.h>

int main(void){

    pid_t id_pActual, id_padre;

    id_pActual = getpid();
    id_padre = getppid();

	printf("PID de este proceso: %d\n",id_pActual);
	printf("PID del proceso padre: %d\n",id_padre);

    return 0;
}