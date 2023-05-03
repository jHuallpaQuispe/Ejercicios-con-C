#include <stdio.h>
#include <stdlib.h>
#define N 5

void FUNCION(int *, int []);

int main()
{
	int A = 25;
	
	int VEC[N] = {12, 4 ,7 ,10, 23};
	int i;
	
	printf("\n\n\t\t VALORES ORGINALES \n\n\t\t");
	printf("%5d\t\t",A);
	for(i= 0 ;i <N; i++)
		printf("%5d", VEC[i]);
		
	FUNCION(&A, VEC);
		
	printf("\n\n\t\t VALORES DESPUES DE LA FUNCION \n\n\t\t");
	printf("%5d\t\t",A);
	
	for(i= 0 ;i <N; i++)
		printf("%5d", VEC[i]);
	
	printf("\n\n\n\n");
	
	return 0;
}
void FUNCION(int *P, int V[])
{
	int i;
	
	*P = 2* (*P);
	for(i = 0; i<N; i++)
		V[i] = 2*V[i];
	
}