/*ORDENAMIENTO CRECIENTE DE EDAD*/

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
	struct ALUMNO x, y;	
	int i, j ;
	if( ( (FP = fopen("BD","rb+")) == NULL) ){
		printf("\n\n ERROR APERTURA DE ARCHIVO LECTURA \n\n");
		exit(1);
	};
	
	fseek(FP,0L,SEEK_END);
	int N;
	N = ftell(FP)/ sizeof(x);
	/* ORDENAMIENTO */
	
	for(i = 0; i < N -1 ; i++){
		for(j = 0; j < N - 1 - i; j++){
			fseek(FP,(long)(j*sizeof(x)),SEEK_SET);
			fread(&x, sizeof(x), 1 , FP);
			fread(&y, sizeof(x), 1 , FP);
		
			if(x.edad> y.edad){	
				
				fseek(FP,(long)((-2)*sizeof(x)),SEEK_CUR);
				fwrite(&y, sizeof(y), 1 , FP);
				fwrite(&x, sizeof(x), 1 , FP);
				
			}
		}
	}
	
	/*MIRAR*/
	fseek(FP,0l,SEEK_SET);
	printf("\n\n\t %-20s %10s %10s\n\n","NOMBRE","SEXO","EDAD");
	fread(&x, sizeof(x), 1 , FP);
	while(!feof(FP)){
		printf("\n\n\t %-20s %9c %10d",x.nom, x.sex, x.edad);
		fread(&x, sizeof(x), 1 , FP);
	}

	
	fclose(FP);

	
	printf("\n\n\n\n");
	return 0;
}