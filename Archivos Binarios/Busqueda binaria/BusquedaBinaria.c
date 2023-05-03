#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ALUMNO{
	char nom[20];
	char sex;
	int edad;
	
};

int main(){
	
	FILE * FP;
	struct ALUMNO x, ENCONTRADO;
	int BAJO, ALTO, MEDIO , L;
	char buscar[20];
	
	if( (FP = fopen("BD1","rb")) == NULL ){
		printf("\n\n ERROR APERTURA DE ARCHIVO \n\n");
		exit(1);
	};
	
	
	printf("\n\n\t %-20s %10s %10s\n\n","NOMBRE","SEXO","EDAD");
	fread(&x, sizeof(x), 1 , FP);
	while(!feof(FP)){
		printf("\n\n\t %-20s %9c %10d",x.nom, x.sex, x.edad);
		fread(&x, sizeof(x), 1 , FP);
	}
	
	L = ftell(FP)/sizeof(x);
	
	printf("\n\n\n\t INGRESE UN NOMBRE:	");
	gets(buscar);
	
	/*BUSQUEDA BINARIA*/
	
	BAJO = 0;
	ALTO = L - 1; // 8

	while(BAJO <= ALTO){
		MEDIO = (BAJO+ALTO) / 2;
		fseek(FP,(long)((MEDIO)*sizeof(x)),SEEK_SET);
		fread(&x, sizeof(x), 1 , FP);
		
		if(!strcmpi(buscar, x.nom)){
			ENCONTRADO = x; // lo encontramos
			break;
		}
		if( (strcmpi(buscar,x.nom)) < 0 )
			ALTO = MEDIO - 1;
		else
			BAJO = MEDIO +1;
			
	}
	
	printf("\n\t %d --> %-20s %9c %10d",MEDIO+1,ENCONTRADO.nom, ENCONTRADO.sex, ENCONTRADO.edad);
	

	
	fclose(FP);
	return 0;
}