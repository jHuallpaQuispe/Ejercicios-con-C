#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno{
	int legajo;
	char sexo;
	char nombre[30];
	float promedio;
};
void promedio(struct alumno *, struct alumno *);
int main()
{
	//struc alumno{
	//	int legajo; char sexo; char nombre[30]; float promedio;
	//};
	//1) Realice un programa que solicite memoria para 3 alumnos(un vector). El usuario ingresará los datos
	//que se cargan en las estructuras. Mostrar el nombre de los alumnos uno debajo del otro.
	
	//2) Realice una funcion que reciba un puntero al inicio del vector y un puntero a uno de los alumnos,
	//e indique si el promedio de ese alumno es mayor o menor al promedio general (de los 3).
	
	struct alumno *alum;
	int i;
	struct alumno * seleccionado;
	
	alum = (struct alumno *) malloc(3 * sizeof(struct alumno));
	
	for(i = 0; i < 3; i++){
		fflush(stdin);
		printf("\n\t IMGRESE EL NOMBRE: ");
		gets((alum+i)->nombre);

		printf("\n\t IMGRESE EL SEXO: ");
		(alum+i)->sexo = getchar();

		printf("\n\t INGRESA EL LEGAJO:	");
		scanf("%d",&((alum+i)->legajo));
		
		printf("\n\t IMGRESE EL PROMEDIO: ");
		scanf("%f",&((alum+i)->promedio));
	}
	
	
	printf("\n\n\t %-15s %12s %30s %30s\n","LEGAJO","NOMBRE","SEXO","PROMEDIO");
	for(i = 0; i < 3; i++){
		printf("\n\n\t %-15d %12s %28c %27.02f\n",(alum+i)->legajo,(alum+i)->nombre,(alum+i)->sexo,(alum+i)->promedio);	
	}
	
	seleccionado = alum+2;
	printf("\n\n\t EL ALUMNO(a) %s", seleccionado->nombre);
	
	promedio(alum,seleccionado);
	free(alum);
	
	printf("\n\n\n\n");
	return 0;
}

void promedio(struct alumno *alum, struct alumno *seleccionado ){
	
	float proGeneral=0;
	int i;
	for(i = 0; i < 3; i++)
		proGeneral+= (alum+i)->promedio;
	
	proGeneral = proGeneral/3;
	if((seleccionado)->promedio > proGeneral)
		printf("\n\n\t --> ES MAYOR AL PROMEDIO GENERAL");
	else
		printf("\n\n\t --> ES MENOR AL PROMEDIO GENERAL");
}