#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{
	//Contruir un programa que determine si "PATH" se encuentra entre las variables 
	//de entorno. Realizar una comparacion para que no importen las diferencias
	//en mayusculas y minusculas.
	int i = 0;
	char buscar[] = {"PATCH"};
	
	for(i = 0; *(envp+i); i++)
		if(!strcmpi(buscar, *(envp+i))){
			printf("\n\n\t SI SE ENCONTRÓ LA PALABRA '%s'\n\n'",buscar);
			exit(1);
		}
	printf("\n\n\t NO SE ENCONTRO LA PALABRA '%s'",buscar);*/
	
	/*
	char buscar[] = {"PATCH"};
	int i , j = 0;
	for(i = 0; *(envp+i); i++){
		if(buscar[0] == (*(envp+i))[j]){
			j++;
			if(buscar[1] == (*(envp+i))[j]){
				j++;
				if(buscar[2] == (*(envp+i))[j]){
					j++;
					if(buscar[3] == (*(envp+i))[j]){
						printf("\n\n\t SI SE ENCONTRÓ LA PALABRA '%s'\n\n'",buscar);
					}
				}
			}
		}
	}
	printf("\n\n\t NO SE ENCONTRO LA PALABRA '%s'",buscar);		
	printf("\n\n\n\n");
	
	return 0;
}