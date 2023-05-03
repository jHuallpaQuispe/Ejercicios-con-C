#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
	int A, *P, **PP;
	
	A=10;
	P = &A;
	PP = &P;
	
	printf("\n\n\t\t &A = %X	&P = %X	&PP = %X	",&A, &P, &PP);


	printf("\n\n\t\t A = %d		P = %X	PP = %X	",A, P, PP);
	
	printf("\n\n\t\t A = %d		*P = %d		**PP = %d	",A, *P, **PP);
	
	
	**PP = 863;
	
	printf("\n\n\t\t A = %d	*P = %d	**PP = %d	",A, *P, **PP);
	
	printf("\n\n\t\t &A = %X	P = %X	*PP = %X	",&A, P, *PP);
	
	printf("\n\n\n\n");
	return 0;
}

