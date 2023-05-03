#include <stdio.h>
#include <stdlib.h>
#define N 8



int main()
{
	int VEC[N];
	int i;
	int *P;
	for(P = VEC ;P < VEC + N; P++){
		printf("\n	DATO = ");
		scanf("%d", P); // sin & porque P ya es una direccion
	}

	/* IMPRESION */
	printf("\n\n\n\t\t IMPRESION 1 DEL VECTOR \n\n\t\t");
	for(P= VEC ;P < VEC + N; P++)
		printf("%5d", *P);
	
	int *AUX;
	int J;
	/*ORDENAMIENTO*/
	for(i = 0; i < N-1; i++)
		for(P = VEC, J = 0; J<N - i - 1; J++)
				if(*(P+J) > *(P+J+1)){
					*AUX = *(P+J);
					*(P+J) = *(P+J+1);
					*(P+J+1) = *AUX;
				}
	printf("\n\n\n\t\t IMPRESION DEL VECTOR ORDENADO \n\n\t\t");
	for(P= VEC ;P < VEC + N; P++)
		printf("%5d", *P);

	printf("\n\n\n\n");
	
	return 0;
}