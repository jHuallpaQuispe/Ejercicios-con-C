#include <stdio.h>
#include <stdlib.h>
#define N 8



int main()
{
	int VEC[N];
	int i;
	int *P;
	int *PMIN;
	for(P = VEC ;P < VEC + N; P++){
		printf("\n	DATO = ");
		scanf("%d", P); // sin & porque P ya es una direccion
	}

	/* IMPRESION 1 */+
	printf("\n\n\n\t\t IMPRESION 1 DEL VECTOR \n\n\t\t");
	for(P= VEC ;P < VEC + N; P++)
		printf("%5d", *P);
		
	/* IMPRESION 2 */+
	printf("\n\n\n\t\t IMPRESION 2 DEL VECTOR \n\n\t\t");
	for(P= VEC ,i = 0; i <N; i++)
		printf("%5d", *(P+i));
		
	for(P = VEC; P < VEC + N; P++)
		if(*P < *PMIN)
			PMIN = P;

	printf("\n\n\t\t EL MINIMO ES %d", *PMIN);
	printf("\n\n\t\t SU POSICION ES %d", PMIN - VEC);
	printf("\n\n\n\n");
	
	return 0;
}