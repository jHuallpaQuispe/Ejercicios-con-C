#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{
	//Contruir un programa que se denomine GRADOS.EXE y que se invoque desde linea de comandos
	//con dos argumentos. El primero representa un valor de temperatura y tiene formato flotante.
	//El segundo representa el sistema en que esta expresada dicha temperatura y puede ser C(Celcius),
	//F(Farenheit) o K (Kelvin).
	
	if(argc != 3){
		printf("\n\n LA CANTIDAD DE ARGUMENTOS INGRESADOS SON INCORRECTOS");
		exit(1);
	}
	
	float temperatura = atof(*(argv+1));
	float celcius, farenheit, kelvin;

	if(*(*(argv+2)) == 'F' || *(*(argv+2)) == 'f'){
		farenheit = temperatura;
		celcius = (farenheit - 32) / 1.8;
		kelvin = celcius + 273.15;
		
		printf("\n\n\t\t ---> GRADOS	%.2f	FARENHEIT", farenheit);
		printf("\n\n\t\t GRADOS	%.2f	CELCIUS", celcius);
		printf("\n\n\t\t GRADOS	%.2f	KELVIN", kelvin);
	}else if(*(*(argv+2)) == 'C' || *(*(argv+2)) == 'c'){
		celcius = temperatura;
		farenheit = (celcius* 1.8) + 32;
		kelvin = celcius + 273.15;
		
		printf("\n\n\t\t ---> GRADOS	%.2f	CELCIUS", celcius);
		printf("\n\n\t\t GRADOS	%.2f	FARENHEIT", farenheit);
		printf("\n\n\t\t GRADOS	%.2f	KELVIN", kelvin);
    }else if(*(*(argv+2)) == 'K' || *(*(argv+2)) == 'k'){
		kelvin = temperatura;
		celcius = kelvin - 273.15;
		farenheit = (celcius * 1.8) + 32;
		
		printf("\n\n\t\t ---> GRADOS	%.2f	KELVIN", kelvin);
		printf("\n\n\t\t GRADOS	%.2f	FARENHEIT", farenheit);
		printf("\n\n\t\t GRADOS	%.2f	CELCIUS", celcius);
	}else{
		printf("\n\n\n NO SÉ QUE TEMPERATURA ES");
		exit(1);
	}
	
	/*printf("\n\n\t\t GRADOS	%.2f	FARENHEIT", farenheit);
	printf("\n\n\t\t GRADOS	%.2f	CELCIUS", celcius);
	printf("\n\n\t\t GRADOS	%.2f	KELVIN", kelvin);
	printf("\n\n\n\n");*/
	
	return 0;
}