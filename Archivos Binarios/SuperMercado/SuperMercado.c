#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct articulo{
	int art;
	char desc[20];
	int stock;
	char prove[15];
	float costo;
};

struct proveedor{
	char nom[15];
	int cantArtDif;	
};
#define N 8
int main(){
	
	
	char * articulos[] = {"Chocolate", "Gomitas", "Chupetin", "Galletitas","Alfajor","Gaseosa","Monster","Pipas"};
    char * proveedores[] = {"Kennedy","Redfield","Wong","Valentine","Redfield","Valentine","Redfield","Kennedy"};
    float costos [] = {10.50,4.25,8.30,1.75,9.80,5.70,12.40,8.25};
	
	FILE * FP, *FP2;
	
	int i ;
	struct articulo artic, aux;
	
	// ESCRITURA
/*	FP = fopen("BD","wb");
	
	
	for(i = 0; i < N; i++){
		artic.art = 1000+rand()%100;
		strcpy(artic.desc,articulos[i]);
		artic.stock = 100+rand()%50;
		strcpy(artic.prove,proveedores[i]);
		artic.costo = costos[i];
		fwrite(&artic,sizeof(artic),1,FP);
		
	}
	
*/	

// LECTURA

	FP = fopen("BD","rb");
	
	fread(&artic,sizeof(artic),1,FP);
	while(!feof(FP)){
		printf("\n\n\t %-10d %10s %10d %20s %10.02f", artic.art, artic.desc, artic.stock, artic.prove, artic.costo);
		fread(&artic,sizeof(artic),1,FP);
	}
	
	rewind(FP);
	struct proveedor MAX;
	int cont ,B = 0; // BANDERA
	FP2 = fopen("BD","rb");
	
	fread(&artic,sizeof(artic),1,FP);
	while(!feof(FP)){
		cont = 0;
		rewind(FP2);
		fread(&aux,sizeof(aux),1,FP2);
		while(!feof(FP2)){
			
			if(!strcmp(artic.prove,aux.prove))
				cont++;
			fread(&aux,sizeof(aux),1,FP2);
		}
		if(!B){ // SOLO PARA GUARDAR EL PRIMER REGISTRO
			strcpy(MAX.nom, artic.prove);
			MAX.cantArtDif = cont;
			B = 1;
		}else if(cont > MAX.cantArtDif){
			strcpy(MAX.nom,artic.prove);
			MAX.cantArtDif = cont;
		}
		fread(&artic,sizeof(artic),1,FP);
	}
	printf("\n\n\n\t\t 	EL PROVEEDOR ES 	%s con %d ARTICULOS DIFERENTES",MAX.nom,MAX.cantArtDif);
	printf("\n\n\n\n 	FIN DEL PROGRAMA");
	fclose(FP);
	fclose(FP2);
	return 0;
}