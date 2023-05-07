#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumnos{
	int legajo;
	char carrera[20];
};
struct Examen{
	int legajo;
	int nota;
};
#define N 10
int main(){
	
	
	int LEGAJOS[] = {1501,1509,1523,1507,1506,1512,1503,1526,1580,1599};
	char * CARRERAS[] = {"Ingenieria","Derecho","Programacion","Ingenieria","Contabilidad","Medicina","Ingenieria","Ingenieria","Derecho","Programacion"};
	int NOTAS[] = {0,10,8,6,4,3,0,7,6,0};
	FILE * FPALUM, * FPEXA;
	
	FPALUM = fopen("INGRESO","rb"); // PARA ESCRITURA "wb"
	FPEXA = fopen("EXAMEN","rb");	// PARA ESCRITURA "wb"
	
	srand(100);
	struct Alumnos alum;
	struct Examen resultado;
	int i ,j;
/*	
	//	ESCRITURA DE INGRESANTES
	for(i = 0; i < N; i++){
		
		strcpy(alum.carrera,CARRERAS[i]);
		alum.legajo = LEGAJOS[i];
		fwrite(&alum,sizeof(alum),1,FPALUM);
	}
	//	ESCRITURA DE RESULTADOS DEL EXAMEN
	for(j= 0; j< N; j++){
		
		resultado.legajo = LEGAJOS[j];
		resultado.nota = NOTAS[j];
		fwrite(&resultado,sizeof(resultado),1,FPEXA);
	}
	
*/	
	//	lECTURA DE INGRESANTES
	fseek(FPALUM,0L,SEEK_SET);
	
	fread(&alum,sizeof(alum),1,FPALUM);
	while(!feof(FPALUM)){
		
		printf("\n\n\t %-5d %15s",alum.legajo,alum.carrera);
		fread(&alum,sizeof(alum),1,FPALUM);
	}



	//	LECTURA DE RESULTADOS
	
	printf("\n\n\n");
	rewind(FPEXA);
	
	fread(&resultado,sizeof(resultado),1,FPEXA);
	while(!feof(FPEXA)){
		
		printf("\n\n\t %-5d %10d ",resultado.legajo, resultado.nota);
		fread(&resultado,sizeof(resultado),1,FPEXA);
	}

	

	/*	PUNTO A  */
	int cont = 0; // PARA LOS QUE SE INSCRIBIERON
	fseek(FPALUM,0L,SEEK_SET);
	fread(&alum,sizeof(alum),1,FPALUM);
	while(!feof(FPALUM)){
		
		if(!strcmpi(alum.carrera,"Ingenieria"))
			cont++;
		fread(&alum,sizeof(alum),1,FPALUM);	
	}
	
	printf("\n\n\t SE INCRIBIERON A INGENIERIA :	%d",cont);
	
	
	/*	PUNTO B  */
	
	cont = 0; // PARA LOS QUE SE PRESENTARON AL EXAMEN, SI TIENEN 0, NO SE PRESENTARON AL EXAMEN
	
	fseek(FPALUM,0L,SEEK_SET);
	fread(&alum,sizeof(alum),1,FPALUM);
	while(!feof(FPALUM)){
		
		if(!strcmpi(alum.carrera,"Ingenieria")){
			rewind(FPEXA);
			fread(&resultado,sizeof(resultado),1,FPEXA);
			while(!feof(FPEXA)){
				
				if(alum.legajo == resultado.legajo)
					if(resultado.nota > 0)
						cont++;
					
				fread(&resultado,sizeof(resultado),1,FPEXA);
			}
		}
		
		fread(&alum,sizeof(alum),1,FPALUM);
	}

	printf("\n\n\n\t Y SE PRESENTARON:	%d",cont);
	
	
	
	/*	PUNTO C  */
	
	cont = 0; // PARA LOS QUE APROBARON CON 6 A MAS
	rewind(FPALUM);
	fread(&alum,sizeof(alum),1,FPALUM);
	while(!feof(FPALUM)){
		
		if(!strcmpi(alum.carrera,"Ingenieria")){
			
			rewind(FPEXA);
			fread(&resultado,sizeof(resultado),1,FPEXA);
			while(!feof(FPEXA)){
				if(alum.legajo == resultado.legajo)
					if(resultado.nota >= 6)
						cont++;
				fread(&resultado,sizeof(resultado),1,FPEXA);
			}
		}
		fread(&alum,sizeof(alum),1,FPALUM);
	}
	
	printf("\n\n\n\t Y LOS QUE APROBARON CON 6 A MAS SON:	%d",cont);
	fclose(FPEXA);
	fclose(FPALUM);
	
	
	printf("\n\n\n\n");
	return 0;
}