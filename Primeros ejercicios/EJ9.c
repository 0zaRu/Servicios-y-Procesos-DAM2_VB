#include <stdio.h>
#include <string.h>
#define MAX 100
 
int main(){
	 
	int cambio;
	char frase[MAX];

	printf("Introduce la palabra: ");
	scanf("%s", &frase);
	
	printf("\nLa palabra introducida es: \"%s\"", frase);

	printf("\nLa palabra invertida es:   ");
		for(int i=0; i< strlen(frase)/2; i++){		
            cambio=frase[i];
            frase[i]=frase[strlen(frase)-i-1];
            frase[strlen(frase)-i-1]=cambio;
        }

	printf("%s", frase);

return 0;
}