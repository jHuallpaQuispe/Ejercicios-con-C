#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno{
	char Nom[20];
	char Sex;
	int Nota;
};

#define N 8

int main()
{
	struct Alumno vec[N], *p;
	struct Alumno * vPunteros[N], *pAux;
	int i, j;
	
	char * Nombres [N] = {"Jherson", "Paola", "Anthony", "Alexandra","Nancy","Cancio","Betty","Chocho"};
	char  Sexo[N] = {'M','F','M','F','F','M','F','M'};
	
	/*INICIALIZACION DEL VECTOR DE PUNTEROS*/
	for(i = 0; i < N; i++)
//		vPunteros[i] = &vec[i];
		*(vPunteros+i)= vec+i;
		
	p = vec;
	for(i = 0; i< N;i++){
		strcpy((p+i)->Nom ,*(Nombres+i));
		(p+i)->Sex = *(Sexo+i);
		(p+i)->Nota = 2+rand()%8;
		
		/*
		fflush(stdin);
		printf("\n\n\t\t NOMBRE	: 	");
		gets(p->Nom);
		printf("\n\n\t\t SEXO	: 	");
		p->Sex = getchar();
		printf("\n\n\t\t NOTA	: 	");
		scanf("%d",&(p->Nota));*/		
	}
	printf("\n\n\n\n\t\t BARRIENDO VECTOR DE ESTRUCTURAS \n");
	printf("\n\t %-15s %8s %10s\n","NOMBRE", "SEXO", "NOTA");
	for(p = vec; p < vec+N; p++){
		printf("\n\n\t %-15s %8c %10d",p->Nom, p->Sex, p->Nota);
	}
	
	
	printf("\n\n\n\n\t\t BARRIENDO CON VECTOR DE PUNTEROS \n");
	printf("\n\t %-15s %8s %10s\n","NOMBRE", "SEXO", "NOTA");
	for(i = 0; i < N; i++){
		printf("\n\n\t %-15s %8c %10d",(*(vPunteros+i))->Nom, (*(*(vPunteros+i))).Sex, (*(vPunteros[i])).Nota);
	}
		
	p = vec;
	for(i = 0; i < N-1; i++)
		for(j = 0; j < N-i-1; j++ )
			if((*(vPunteros+j))->Nota <(*(vPunteros+j+1))->Nota){
				pAux = *(vPunteros+j);
				*(vPunteros+j) =*(vPunteros+j+1);
				*(vPunteros+j+1) = pAux;
				
			}	


	printf("\n\n\n\n\t\t BARRIENDO CON VECTOR DE PUNTEROS \n");
	printf("\n\t %-15s %8s %10s\n","NOMBRE", "SEXO", "NOTA");
	for(i = 0; i < N; i++){
		printf("\n\n\t %-15s %8c %10d",(*(vPunteros+i))->Nom, (*(vPunteros+i))->Sex, (*(vPunteros+i))->Nota);
	}
	
	printf("\n\n\n\n\t\t BARRIENDO VECTOR DE ESTRUCTURAS \n");
	printf("\n\t %-15s %8s %10s\n","NOMBRE", "SEXO", "NOTA");
	for(p = vec, i = 0; i < N; i++){
		printf("\n\n\t %-15s %8c %10d",(p+i)->Nom, (*(p+i)).Sex, (p+i)->Nota);
	}

	printf("\n\n\n\n");
	return 0;
}

