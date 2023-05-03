#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ARTI{
	short int art;
	char cod[50];
	char desc[100];
	char fab[50];
	short int stock;

};

struct proveedor{
	
	char NOM[50];
	int cantArticulos;
};

struct Indices{
	
	int art;
	int pos;
};
#define Nu 10
int main(){
	
	FILE * FP, *FP2;
	struct ARTI BD, aux;
	int I, J;
	if( (FP = fopen("BD_Articulos", "rb")) == NULL){
		printf("\n\n\t ERROR EN LA ABERTURA DEL ARCHIVO");
		exit(1);
	}
	
	//char * codigo[] = {"CLI090922","CLI090922","CLI090922","CLI090922","IRSVEL.22","IRSVELCR","SP000484","ASTREAC","AST01400","AST36614","AST36613","HEISTZ301","SP000396","SP000398","SP000399","SP000397","008031.7","008003.7","005120.7","HEISTZ202"};
	//char * descripcion[] = {"Radiador.Valderoma.II.Horizon","Radiador.Valderoma.II.Horizon","Radiador.Valderoma.II.Vertica","Radiador.Valderoma.II.Vertica","Radiador.Vela.roma.II.Vertica","Radiador.Vela.Cromado.Vertica","Radiador.Vela.Eluctrico.rtica","Recambio.Reactivos.Lyquido.ca","Recogehojas.con.Mango.uido.ca","Recogehojas.de.Fondo.Shark.ca","Recogehojas.de.Superficie.Shar","Red.para.hojas.100.cm.ce.Shar","Reduccion.1/2..100.cm.ce.Shar","Reduccion.1/4..100.cm.ce.Shar","Reduccion.1/8..100.cm.ce.Shar","Reduccion.3/8..100.cm.ce.Shar","Reduccion.Hermeto..cm.ce.Shar","Reductor.De.Presion.m.ce.Shar","Reductor.Pe.M/H.ion.m.ce.Shar","Reductor.pH.Estanques.ce.Shar"};
	//char * fabricante[] = {"Climastar","Climastar","Climastar","Climastar","Irsap.tar","Irsap.tar","Irsap.tar","AstraLPoo","AstraLPoo","AstraLPoo","AstraLPoo","Heissner.","Potermic.","Potermic.","Potermic.","Potermic.","Arco.mic","Monfa.ic","Jimten.c","Heissner."};
	
	
	/*int cantidad_elementosF = sizeof(fabricante) / sizeof(char *);
	int cantidad_elementosC = sizeof(codigo) / sizeof(char *);
	int cantidad_elementosD = sizeof(descripcion) / sizeof(char *);
	printf("\n\n	FABRICANTE	%d",cantidad_elementosF);
	printf("\n\n	CODIGO	%d",cantidad_elementosC);
	printf("\n\n	DESCRIPCION	%d",cantidad_elementosD);*/

	/*ESCRITURA*/
	
   /*for(I = 0; I < Nu; I++){
	
            strcpy(BD.cod, codigo[I]);
            strcpy(BD.desc, descripcion[I]);
            strcpy(BD.fab, fabricante[I]);
            BD.art = 100+rand()%9899;
            BD.stock = 5+rand()%70;

            fwrite(&BD, sizeof(BD), 1, FP);
    }*/
    /*1.LECTURA*/

    printf("\n\n\t %-20s %5s %30s %30s %10s\n\n","ART","CODIGO","DESCRIPCION","FABRICANTE","STOCK");
    fread(&BD, sizeof(BD),1,FP);
	while(!feof(FP)){
		printf("\n\n\t  %-20d %-10s %35s %20s %10d",BD.art,BD.cod,BD.desc,BD.fab,BD.stock);
		fread(&BD, sizeof(BD),1,FP);
	
	}
	

	/*	2.MOSTRAR LOS ARTICULOS CUYO STOCK ES MENOR QUE 8 */
/*	printf("\n\n\t ARTICULOS CON STOCK MENOR A 8:	");
	rewind(FP);
	fread(&BD, sizeof(BD),1,FP);
	while(!feof(FP)){
		if(BD.stock < 8)
			printf("\n\n\t  %-20d %-10s %35s %20s %10d",BD.art,BD.cod,BD.desc,BD.fab,BD.stock);
		fread(&BD, sizeof(BD),1,FP);
	}*/
	
	/*3.DETERMINAR QUIEN ES EL PROVEEDOR QUE MAR ARTICULOS SUMINISTRA*/
/*	rewind(FP);
	if( (FP2 = fopen("BD_Articulos", "rb")) == NULL){
		printf("\n\n\t ERROR EN LA ABERTURA DEL ARCHIVO");
		exit(1);
	}
	int contProveedor;
	struct proveedor MAX;
	
	fread(&BD,sizeof(BD),1,FP);
	
	strcpy(MAX.NOM, BD.fab);
	MAX.cantArticulos = 1;

	while(!feof(FP)){
		contProveedor = 0;
		fread(&aux,sizeof(BD),1,FP2);
		while(!feof(FP2)){
			if(!strcmp(BD.fab, aux.fab) )
				contProveedor++;
				
			fread(&aux,sizeof(BD),1,FP2);
		}
		if(contProveedor > MAX.cantArticulos){
				strcpy(MAX.NOM, BD.fab);
				MAX.cantArticulos = contProveedor;
		}
		rewind(FP2);
		fread(&BD,sizeof(BD),1,FP);
	}
	
	printf("\n\n\t EL PROVEEDOR CON MAS ARTICULOS --> 	%s", MAX.NOM);
	*/

   /*4. PERMITIR EL INGRESO DE UN #ART Y BUSCARLO*/

/*	rewind(FP);
	int num;
	printf("\n\n\t INGRESE EL #ARTICULO:	");
	scanf("%d",&num);
	
	fread(&BD,sizeof(BD),1,FP);
	while(!feof(FP)){
		if(BD.art == num)
			printf("\n\n\t  %-20d %-10s %35s %20s %10d",BD.art,BD.cod,BD.desc,BD.fab,BD.stock);
		fread(&BD,sizeof(BD),1,FP);	
	}
*/

/*5. CREAR EL ARCHIVO INDEXADO*/
	if( (FP2 = fopen("BD_Articulos_Indices", "rb+")) == NULL){
		printf("\n\n\t ERROR EN LA ABERTURA DEL ARCHIVO");
		exit(1);
	}
	
/*	rewind(FP);
	int pos = 0 ;
	struct Indices x;
	fread(&BD,sizeof(BD),1,FP);
	while(!feof(FP)){
		x.art = BD.art;
		x.pos = pos;
		fwrite(&x,sizeof(x),1,FP2);
		pos++;
		
		fread(&BD,sizeof(BD),1,FP);
	}
	*/
	    /*LECTURA del archivo indice*/

/*    fread(&x, sizeof(x),1,FP2);
	while(!feof(FP2)){
		printf("\n\n\t  %-20d %-10d ",x.art,x.pos);
		fread(&x, sizeof(x),1,FP2);
	
	}*/
	/*6. ORDENAR EL INDICE*/
/*	fseek(FP2,0L,SEEK_END);
	int N = ftell(FP2)/sizeof(x);
	
	struct Indices aux2;
	
	for(I= 0 ; I < N - 1; I++){
		for(J = 0; J < N-1-I;J++){
			fseek(FP2,(long)(J*sizeof(x)),SEEK_SET);
			fread(&x,sizeof(x),1,FP2);
			fread(&aux2,sizeof(x),1,FP2);
			if(x.art > aux2.art){
				
				fseek(FP2,(long)((-2)*sizeof(x)),SEEK_CUR);
				fwrite(&aux2,sizeof(x),1,FP2);
				fwrite(&x, sizeof(x),1,FP2);
			}
			
			
		}
		
	}
		
	/*7. BUSQUEDA BINARIA CON EL ARCHIVO INDEXADO*/
	int ARTI;
	printf("\n\n\t INGRESE EL #ARTICULO:	");
	scanf("%d",&ARTI);
	
	struct Indices dato;
	fseek(FP2,0L,SEEK_END);
	int N = ftell(FP2)/sizeof(dato);
	int bajo = 0, alto, medio, posicion;
	
	alto = N -1;
	while(bajo <= alto ){
		medio = (bajo+alto)/ 2;
		fseek(FP2,(long)((medio)*sizeof(dato)),SEEK_SET);
		fread(&dato,sizeof(dato),1,FP2);
		if(dato.art == ARTI ){
			posicion = dato.pos; // encontrado
			break;
		}
		if(ARTI < dato.art)
			alto = medio - 1;
		else
			bajo = medio + 1;
	}
	
	fseek(FP,(long)((posicion)*sizeof(BD)),SEEK_SET);
	fread(&BD,sizeof(BD),1,FP);
	printf("\n\n\t  %-20d %-10s %35s %20s %10d",BD.art,BD.cod,BD.desc,BD.fab,BD.stock);
//	printf("\n\n	%d",N);


	fclose(FP2);
	fclose(FP);
	printf("\n\n	FIN DEL PROGRAMA");
	return 0;
}