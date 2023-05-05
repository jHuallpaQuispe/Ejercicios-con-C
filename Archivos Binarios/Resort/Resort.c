#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fecha{
	int dia;
	int mes;
	int anio;
};
struct Servicio{
	char servicio[20];
	int id;
	struct Fecha hoy;
};
struct Precio{
	char servicio[20];
	int costo;
};

struct huesped{
	int id;
	int gastosTotales;
};
#define N 8

int main(){
	
	
	
	
	char * servicios[] = {"Pileta","Spa","Bar","Gimnasio"};
	char * usados[]={"Pileta","Spa","Bar","Gimnasio","Pileta","Spa","Bar","Gimnasio"};
	int ids[] = {1001,1002,1001,1001,1003,1003,1004,1004};
	int costos[]={100,200,150,300};
	
	
//	FILE * FP,*FP2;
	//	ESCRITURA SERVICIOS
/*	srand(100);
	FP = fopen("SERVICIOS","wb+");
	struct Servicio servicio;
	int i, j;
	for(j=0; j < N; j++){
			servicio.id = ids[j];
			strcpy(servicio.servicio, usados[j]);
			servicio.hoy.dia = 1+rand()%29;
			servicio.hoy.mes = 1+ rand()%12;
			servicio.hoy.anio = 2023+rand()%1;
			fwrite(&servicio,sizeof(servicio),1,FP);
		}


	//	LECTURA MERCADERIA
	rewind(FP);
	fread(&servicio,sizeof(servicio),1,FP);
	while(!feof(FP)){
		printf("\n\n\t %-10d %10s \t %02d : %02d : %02d",servicio.id, servicio.servicio, servicio.hoy.dia,servicio.hoy.mes,servicio.hoy.anio);
		fread(&servicio,sizeof(servicio),1,FP);
	}
	
*/

	// ESCRITURA DE PRECIOS
/*	int i;

	FP2 = fopen("LISTA_PRECIOS","wb+");
	struct Precio precio;
	for(i = 0; i < 4; i++){
		strcpy(precio.servicio, servicios[i]);
		precio.costo = costos[i];
		fwrite(&precio,sizeof(precio),1,FP2);
	}
	
	//	LECTURA PRECIOS
	rewind(FP2);
	fread(&precio,sizeof(precio),1,FP2);
	while(!feof(FP2)){
		printf("\n\n\t %-10s %10d",precio.servicio, precio.costo);
		fread(&precio,sizeof(precio),1,FP2);
	}
*/	
	
	// PUNTO 1
	FILE * FP, * FP2, *FP_Precios;
	FP = fopen("SERVICIOS","rb");
	FP2 =  fopen("SERVICIOS","rb");
	FP_Precios = fopen("LISTA_PRECIOS","rb");
	
	//	LECTURA MERCADERIA
	struct Servicio servicio;
	fread(&servicio,sizeof(servicio),1,FP);
	while(!feof(FP)){
		printf("\n\n\t %-10d %10s \t %02d : %02d : %02d",servicio.id, servicio.servicio, servicio.hoy.dia,servicio.hoy.mes,servicio.hoy.anio);
		fread(&servicio,sizeof(servicio),1,FP);
	}
	//	LECTURA PRECIOS
	printf("\n\n\n\t\t PRECIOS DE LOS SERVICIOS");
	struct Precio x;
	fread(&x,sizeof(x),1,FP_Precios);
	while(!feof(FP_Precios)){
		printf("\n\n\t %-10s %10d$",x.servicio, x.costo);
		fread(&x,sizeof(x),1,FP_Precios);
	}
	
	struct Precio precio;
	struct Servicio serv1;
	struct Servicio serv2;
	struct huesped MAX;
	int acu;
	int B = 0; //bandera
	rewind(FP);
	rewind(FP_Precios);
	fread(&serv1,sizeof(serv1),1,FP);
	while(!feof(FP)){
		acu = 0;
		rewind(FP2);
		// BUSCANDO LOS HUESPEDES SEGUN SU ID
		fread(&serv2,sizeof(serv2),1,FP2);
		while(!feof(FP2)){
			// VEMOS EN EL ARCHIVO SI EL MISMO ID SE REPITE, PARA SABER SU SERVICIO CONSUMIDO
			if(serv1.id == serv2.id){
				
				rewind(FP_Precios);
				// BUSCAMOS EL PRECIO DEL SERVICIO CONSUMIDO EN LA ARCHIVO DE PRECIOS
				fread(&precio,sizeof(precio),1,FP_Precios);
				while(!feof(FP_Precios)){
					
					if(!strcmpi(serv2.servicio, precio.servicio))
						acu += precio.costo;
					fread(&precio,sizeof(precio),1,FP_Precios);
				}
			}
			
			fread(&serv2,sizeof(serv2),1,FP2);
		}
		
		if(!B){ // solo para guardar el 1er huesped
			MAX.id = serv1.id;
			MAX.gastosTotales = acu;
			B = 1;
		}else if (acu > MAX.gastosTotales){ // EN BUSCA DEL MAXIMO 
			MAX.id = serv1.id;
			MAX.gastosTotales = acu;
		}
			
		fread(&serv1,sizeof(serv1),1,FP);
	}
	
	printf("\n\n\t\t EL HUESPED QUE MAS GASTO FUE -- > %10d",MAX.id);
	printf("\n\t\t Y GASTO -- >  %10d$",MAX.gastosTotales);
	
	
	// PUNTO 2
	char buscarServicio[20];
	printf("\n\n INGRESE UN SERVICIO:	");
	gets(buscarServicio);	
	
	rewind(FP);
	printf("\n\n LOS HUESPEDES QUE USAN %s SON:		", buscarServicio);
	fread(&servicio,sizeof(servicio),1,FP);
	while(!feof(FP)){
		
		if(!strcmpi(buscarServicio, servicio.servicio)){
			printf("\n\n\t %-10d FECHA DE USO --> %02d : %02d :%02d",servicio.id, servicio.hoy.dia, servicio.hoy.mes, servicio.hoy.anio);
		}
		fread(&servicio,sizeof(servicio),1,FP);	
	}
	
	printf("\n\n\n\n");
	fclose(FP);
	fclose(FP2);
	fclose(FP_Precios);

	return 0;
}