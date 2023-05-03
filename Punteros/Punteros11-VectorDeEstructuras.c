#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno{
	char Nom[20];
	char Sex;
	int Nota;
};

#define N 4

int main()
{
	struct Alumno vec[N], *p;
	struct Alumno aux;
	int i, j;
	
	for(p = vec; p < vec+N; p++){
		fflush(stdin);
		printf("\n\n\t\t NOMBRE	: 	");
		gets(p->Nom);
		printf("\n\n\t\t SEXO	: 	");
		p->Sex = getchar();
		printf("\n\n\t\t NOTA	: 	");
		scanf("%d",&(p->Nota));
		
	}
	printf("\n\n\n\n\t %-15s %8s %10s\n","NOMBRE", "SEXO", "NOTA");
	for(p = vec; p < vec+N; p++){
		printf("\n\n\t %-15s %8c %10d",p->Nom, p->Sex, p->Nota);
	}
	
	p = vec;
	for(i = 0; i < N-1; i++)
		for(j = 0; j < N-i-1; j++ )
			if((p+j)->Nota <(p+j+1)->Nota){
				aux = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = aux;
			}
		
	printf("\n\n\n\n\t %-15s %8s %10s\n","NOMBRE", "SEXO", "NOTA");
	for(p = vec, i = 0; i < N; i++){
		printf("\n\n\t %-15s %8c %10d",(p+i)->Nom, (*(p+i)).Sex, (p+i)->Nota);
	}
	
	
	printf("\n\n\n\n");
	return 0;
}

