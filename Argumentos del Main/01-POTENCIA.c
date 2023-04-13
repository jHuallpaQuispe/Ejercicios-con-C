#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{
	//Contruir un programa que se denomine POTENCIA.EXE y que se invoque desde linea
	//de comandos con dos argumentos enteros X e Y, y muestr en pantalla el valor de X elevado a la Y.
	int x, y;
	
	if(argc != 3){
		printf("\n\n LA CANTIDAD DE ARGUMENTOS INGRESADOS SON INCORRECTOS");
		exit(1);
	}
		
	x = atoi(*(argv+1));
	y = atoi(*(argv+2));
	int i, acu = 1;
	for(i = 0; i <y; i++)
		acu *= x;
	printf("\n\n\t\t %s	ELEVADO	%s	=	%d",*(argv+1),*(argv+2),acu);
	
}