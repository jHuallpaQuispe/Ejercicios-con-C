#include <stdio.h>
#include <stdlib.h>

int main()
{
	//Escribir un prrograma que lea un numero de teclado,que indica cuantos numeros 
	//enteros ingresara el usuario a continuacion.
	
	//Crear el vector para almacenar el tamaño exacto de los datos y leer los enteros
	//que seran guardados en el vector "dinámico".
	
	//informar el promedio de los datos ingresados 
	
	int *b;
	int cant, acu = 0;
	float promedio;
	printf("\n\n\t\t CUANTOS NUMEROS QUIERE INGRESAR? :	");
	scanf("%d",&cant);

	b = (int*) malloc(cant * sizeof(int)); // la funcion malloc no sabe para que se quiere utilzar la dirrecion, entonces se castea
	//malloc retorna un void*(PUNTERO A UN TIPO DESCONOCIDO)
	int i;
	
	for(i = 0; i <cant; i++){
		printf("\n\t %d -> INGRESE UN NUMERO:	", i+1);
		scanf("%d",(b+i));
		
		acu += *(b+i);
	}
	
	promedio = (float)acu/cant;
	
	printf("\n\n\t\t EL PROMEDIO ES: 	%.02f",promedio);
	
	free(b);
	
	printf("\n\n\n\n");
	return 0;
}