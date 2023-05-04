#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct votos{
	
	char nom[20];
	char distrito[20];
	int votos;
};

struct votoTotal{
	char nom[20];
	int votos;
	
};
# define N 3
int main(){
	
	FILE * FP, * FP2;
	
	
/*	if((FP = fopen("BDVOTOS","wb")) == NULL){
		printf("\n\n\n ERROR EN LA APERTURA DEL ARCHIVO");
		exit(1);
	}*/
	
	char * candidatos[] = {"Ash", "Misty", "Brock"};
    char * distritos[] = {"Pueblo Paleta","Pueblo Lavanda","Ciudad Celeste"};
	
	struct votos BD;
	int i, j;
	srand(100);
	
	
	// ESCRITURA
	
/*	FP = fopen("BDVOTOS","wb");
	for(i = 0; i < N ; i++)
		for(j = 0; j < N ; j++){
			
			strcpy(BD.nom, candidatos[i]);
			strcpy(BD.distrito, distritos[j]);
			BD.votos = 300+rand()%100;
			fwrite(&BD, sizeof(BD),1,FP);
			
		}
*/	

	// LECTURA
	
/*	FP = fopen("BDVOTOS","rb");
	
	fread(&BD, sizeof(BD),1,FP);
	while(!feof(FP)){
		
		printf("\n\n\t %-20s %10s %10d",BD.nom, BD.distrito, BD.votos);
		fread(&BD, sizeof(BD),1,FP);	
	}
	
*/

/*	struct votoTotal BDRESU;
	// PUNTO 1
	
	int encontrado;
	FP = fopen("BDVOTOS","rb");
	FP2 = fopen("BD_RESUMEN", "wb+");
	
	
	fread(&BD, sizeof(BD), 1 , FP);
	while(!feof(FP))
	{
		encontrado = 0;
		rewind(FP2);
		fread(&BDRESU, sizeof(BDRESU),1 , FP2);
		while(!feof(FP2) && encontrado == 0){
			
			if(!strcmp(BD.nom, BDRESU.nom)){
				
				BDRESU.votos += BD.votos;
				fseek(FP2,(long)((-1)*sizeof(BDRESU)), SEEK_CUR);
				fwrite(&BDRESU, sizeof(BDRESU),1 , FP2);
				fseek(FP2,0L,SEEK_CUR);
				encontrado = 1; 
			}
			
			fread(&BDRESU, sizeof(BDRESU),1 , FP2);
		}
		
		// SI NO SE ENCONTRO NADA EN BD_RESUMEN, LO AGREGAMOS
		if(encontrado == 0){
			
			fseek(FP2, 0L, SEEK_END);
			strcpy(BDRESU.nom, BD.nom);
			BDRESU.votos = BD.votos;
			fwrite(&BDRESU, sizeof(BDRESU),1, FP2);
		}
		
		fread(&BD, sizeof(BD), 1 , FP);
	}

*/



	// LECTURA BD_RESUMEN
/*	struct votoTotal X;
	FP2 = fopen("BD_RESUMEN", "rb");
	
	fread(&X, sizeof(X),1,FP2);
	while(!feof(FP2)){
		
		printf("\n\n\t %-20s %10d",X.nom, X.votos);
		fread(&X, sizeof(X),1,FP2);	
	}
*/	
	

	// PUNTO 2 
/*	struct votoTotal X ,aux;
	FP2 = fopen("BD_RESUMEN", "rb+"); 
	fseek(FP2,0L,SEEK_END);
	int CANT = ftell(FP2)/ sizeof(X);
	
	for(i = 0; i < CANT - i ;i++)
		for(j = 0; j < CANT-i-1; j++){
			
			fseek(FP2,(long)((j)* sizeof(X)),SEEK_SET);
			fread(&X,sizeof(X),1,FP2);
			fread(&aux,sizeof(aux),1,FP2);
			
			if(X.votos < aux.votos){
				fseek(FP2,(long)((-2)*sizeof(X)),SEEK_CUR);
				fwrite(&aux,sizeof(aux),1,FP2);
				fwrite(&X, sizeof(X),1 ,FP2);
			}
		}

*/
	// LECTURA BD_RESUMEN
	
/*	struct votoTotal X;
	FP2 = fopen("BD_RESUMEN", "rb");
	
	fread(&X, sizeof(X),1,FP2);
	while(!feof(FP2)){
		
		printf("\n\n\t %-20s %10d",X.nom, X.votos);
		fread(&X, sizeof(X),1,FP2);	
	}

	printf("\n\n");
	rewind(FP2);
	
	fread(&X,sizeof(X),1,FP2);
	printf("\n\n\t EL CANDIDATO GANOR ES: 	%s  CON  %d  VOTOS",X.nom,X.votos);

	fclose(FP2);
//	struct votoTotal X;
	char DISTRITO[20], NOM[20];
	int max= 0;
	FP = fopen("BDVOTOS","rb");
	FP2 = fopen("BD_RESUMEN", "rb");
	fread(&X, sizeof(X),1,FP2);
	
	strcpy(NOM,X.nom);
	
	fread(&BD,sizeof(BD),1,FP);
	while(!feof(FP)){
		
		if(!strcmp(BD.nom, NOM)){
			
			if(BD.votos > max){
				max = BD.votos;
				strcpy(DISTRITO,BD.distrito);
			}
		}
		fread(&BD,sizeof(BD),1,FP);
	}
	
	printf("\n\n\n\t OBTUVO MAS VOTOS EN EL DISTRITO:	%s",DISTRITO);
	
*/
	fclose(FP2);
	fclose(FP);
	printf("\n\n\n\n");
	return 0;
}