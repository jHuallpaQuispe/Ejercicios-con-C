#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct articulo{
	char juego[30];
	float precio;
	char proveedor[20];
};
struct incremento{
	char proveedor[20];
	float porcentaje;
};
#define N 10
int main(){
	
	FILE * FP, *FP2;
	
	
	
	char * play[] = {"LOL","RE","C.S","FIFA","SEKIRO","HALO","C.S","FIFA","SEKIRO","LOL"};
    char * proveedor[] = {"JHERSON","PEPITO","PAOLA","MARTINA","CARLITO","ANTHONY","JHERSON","PAOLA","CARLITO","PEPITO"};
    float porcentajes[] = {0.5,0.30,0.80,0.60,0.70,0.90};
	
	
	srand(200);
	//	ESCRITURA MERCADERIA
/*	FP = fopen("MERCADERIA","wb");
	struct articulo juego;
	int i;
	for(i = 0; i < N; i++){
		
		strcpy(juego.juego, play[i]);
		strcpy(juego.proveedor, proveedor[i]);
		juego.precio = 50+rand()%200;
		fwrite(&juego,sizeof(juego),1,FP);
	}
*/
	//	LECTURA MERCADERIA
/*	FP = fopen("MERCADERIA","rb");
	struct articulo juego;
	fread(&juego,sizeof(juego),1,FP);
	while(!feof(FP)){
		printf("\n\n\t %-10s %10s %10.02f",juego.juego, juego.proveedor, juego.precio);
		fread(&juego,sizeof(juego),1,FP);
	}

*/
	//ESCRITURA AUMENTOS
/*	FP2 = fopen("AUMENTOS","wb");
	struct incremento aumento;
	int i;
	for(i = 0; i < N; i++){
		
		strcpy(aumento.proveedor, proveedor[i]);
		aumento.porcentaje = porcentajes[i];
		fwrite(&aumento,sizeof(aumento),1,FP2);
	}
	
*/	
	// LECTURA AUMENTOS
/*	FP2 = fopen("AUMENTOS","rb");
	struct incremento aumento;
	fread(&aumento,sizeof(aumento),1,FP2);
	while(!feof(FP2)){
		printf("\n\n\t %-10s %10.02f",aumento.proveedor, aumento.porcentaje);
		fread(&aumento,sizeof(aumento),1,FP2);
	}
*/	


	// PUNTO A
/*	FP = fopen("MERCADERIA","rb+");
	FP2 = fopen("AUMENTOS","rb"); 
	struct articulo juego;
	struct incremento aumento;
	int encontrado;
	
	fread(&juego,sizeof(juego),1,FP);
	while(!feof(FP)){
		encontrado = 0;
		rewind(FP2);
		fread(&aumento,sizeof(aumento),1,FP2);
		while(!feof(FP2) && encontrado == 0){
			if(!strcmp(juego.proveedor, aumento.proveedor)){
				fseek(FP,(long)((-1)*sizeof(juego)),SEEK_CUR);
				juego.precio += (juego.precio * aumento.porcentaje);
				fwrite(&juego,sizeof(juego),1,FP);
				fseek(FP,0L,SEEK_CUR);
				encontrado = 1;
			}
			fread(&aumento,sizeof(aumento),1,FP2);
		}
		fread(&juego,sizeof(juego),1,FP);
	}
*/
	
	//PUNTO B
/*	FP = fopen("MERCADERIA","rb");
	struct articulo juego;
	fread(&juego,sizeof(juego),1,FP);
	while(!feof(FP)){
		printf("\n\n\t %-10s %10s %10.02f",juego.juego, juego.proveedor, juego.precio);
		fread(&juego,sizeof(juego),1,FP);
	}
	rewind(FP);
	
	char prove[20];
	printf("\n\n\n\t INGRESE UN PROVEEDOR:	");
	gets(prove);
	fread(&juego,sizeof(juego),1,FP);
	printf("\n\n\t %-10s COMERCIALIZA:",prove);
	while(!feof(FP)){
		
		if(!strcmpi(juego.proveedor, prove))
			printf("\t %-10s  ",juego.juego);
			fread(&juego,sizeof(juego),1,FP);
	}
*/

	//PUNTO C
/*	FP = fopen("MERCADERIA","rb");
	struct articulo juego;
	fread(&juego,sizeof(juego),1,FP);
	while(!feof(FP)){
		printf("\n\n\t %-10s %10s %10.02f",juego.juego, juego.proveedor, juego.precio);
		fread(&juego,sizeof(juego),1,FP);
	}
	rewind(FP);
	
	char juegoMax[30];
	float precioMax;
	fread(&juego,sizeof(juego),1,FP);
	strcpy(juegoMax,juego.juego);
	precioMax = juego.precio;
	while(!feof(FP)){
		
		if(juego.precio > precioMax){
			strcpy(juegoMax,juego.juego);
			precioMax = juego.precio;
		}
		fread(&juego,sizeof(juego),1,FP);
	}
	printf("\n\n\n");
	printf("\n\n\t %-10s ES EL MAS CARO Y CUESTA %10.02f",juegoMax,precioMax);
	printf("\n\n\n\n 	FIN DEL PROGRAMA");
*/
	fclose(FP);
	fclose(FP2);
	return 0;
}