#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{
	/*Realizar un programa que reciba nombres como argumentos por linea de comandos y los 
	  muestre en pantalla ordenados alfabeticamente.
	  Realizar el ordenamiento sin mover ni copiar los strings. Utilizar para ello el 
	  vector de punteros.
	  Excluir del ordenamiento el nombre del programa ejecutable*/
	  
	char **p;
	int i, j;
	for(i = 1; i <argc; i++)
		*(p+i)= *(argv+i);

	printf("\n\n\t %-15s\n","NOMBRES");
	for(i = 1; i < argc; i++)
		printf("\n\n\t %-15s",*(argv+i));
		
		
	/*ORDENAMIENTO*/
	char *aux;
	for(i = 0 ; i< argc-1; i++)
		for(j=1; j < argc-i-1; j++)
			if(strcmpi( *(p+j), *(p+j+1)) >0){
				aux = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = aux;
			}
	printf("\n\n\n\t\t LOS NOMBRES ORDENADOS ALFABETICAMENTE");
	printf("\n\n\t %-15s\n","NOMBRES");
	
	for(i = 1; i <argc; i++)
		printf("\n\n\t %-15s",*(p+i));
	
	printf("\n\n\n\n");
	return 0;
}