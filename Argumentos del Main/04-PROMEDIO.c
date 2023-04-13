#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{
	/*Realizar un programa denominado PROMEDIO.EXE que reciba valores enteros por
	  linea de comandos e imprima el promedio de estos.
	  Evitar la division por cero y notar que la cantidad de valores es arbitratia.*/
	
	if(argc < 3){
		printf("\n\n LA CANTIDAD DE ARGUMENTOS INGRESADOS SON INCORRECTOS");
		exit(1);
	}
	
	int acu = 0, i;
	float promedio;
	for(i = 1; i < argc; i++){
		acu += atoi(*(argv+i));
	}
	// i - 1, porque al final del for i vale el mismo valor deargc siendo que no entra al for
	promedio = (float)acu/(i-1);
	printf("\n\n\t\t EL PROMEDIO ES %.2f",promedio);
	return 0;
}