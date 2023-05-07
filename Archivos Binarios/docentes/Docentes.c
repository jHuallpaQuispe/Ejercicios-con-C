#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Docente{
	int legajo;
	char nom[20];
};
struct Materia{
	char nom[20];
	int nivel;
	int legajoDocente;
	
};
#define N 4
int main(){
	
	
	char * NOMBRES[] = {"Jorge","Daniela","Bidel","Jasmin"};
	int LEGAJOS[] = {1505,1509,1506,1502};
	
	int LEGAJOSM[] = {1505,1509,1506,1502,1509,1506,1502,1509,1505};
	char * MATERIAS[] = {"Matematica","Programacion","Fisica","Ingles","Programacion","Fisica","Ingles","Programacion","Matematica"};
	int NIVELES[] = {1,1,1,1,2,3,2,3,3};
	
	
	FILE * FP_DOC, *FP_MAT;
	
/*	FP_DOC = fopen("DOCENTES","wb");
	
	// ESCRITURA DOCENTES
	struct Docente profe;
	int i;
	for(i = 0; i < N; i++){
		strcpy(profe.nom,NOMBRES[i]);
		profe.legajo = LEGAJOS[i];
		fwrite(&profe,sizeof(profe),1,FP_DOC);
	}
	// ESCRITURA MATERIAS
	FP_MAT = fopen("MATERIAS","wb");
	struct Materia mat;
	
	for(i = 0; i < 9; i++){
		
		strcpy(mat.nom,MATERIAS[i]);
		mat.nivel = NIVELES[i];
		mat.legajoDocente = LEGAJOSM[i];
		fwrite(&mat,sizeof(mat),1,FP_MAT);
	}
*/
	//	LECTURA DOCENTES
	FP_DOC = fopen("DOCENTES","rb");
	
	struct Docente profe;
	printf("\n\n\t   DOCENTES");
	fread(&profe,sizeof(profe),1,FP_DOC);
	while(!feof(FP_DOC)){
		printf("\n\n\t %-4d %10s",profe.legajo,profe.nom);
		fread(&profe,sizeof(profe),1,FP_DOC);
	}

	// 	LECTURA MATERIAS
	printf("\n\n");
	FP_MAT = fopen("MATERIAS","rb");
	
	struct Materia mat;
	printf("\n\t\t MATERIAS");
	fread(&mat,sizeof(mat),1,FP_MAT);
	while(!feof(FP_MAT)){
		printf("\n\n\t %-4d %15s %5d",mat.legajoDocente, mat.nom , mat.nivel);
		fread(&mat,sizeof(mat),1,FP_MAT);
	}
	
	/*	PUNTO A  */
	rewind(FP_MAT);
	
	printf("\n\n\n\t LOS DOCENTES QUE DICTAN EL NIVEL 3 SON:");
	
	fread(&mat,sizeof(mat),1,FP_MAT);
	while(!feof(FP_MAT)){
		
		if(mat.nivel == 3){
			rewind(FP_DOC);
			fread(&profe,sizeof(profe),1,FP_DOC);
			while(!feof(FP_DOC)){
				if(mat.legajoDocente == profe.legajo)
					printf("\n\n\t %-10s %20s",profe.nom, mat.nom);
				
				fread(&profe,sizeof(profe),1,FP_DOC);
			}
		}
		fread(&mat,sizeof(mat),1,FP_MAT);
	}
	
	/*	PUNTO B  */
	
	char nombreProfe[20];
	char profeMax[20];
	int cantMaterias;
	int cont , B = 0; // BANDERA
	struct Materia mat2;
	FILE * FP_MAT2;
	
	FP_MAT2 = fopen("MATERIAS","rb");
	rewind(FP_MAT);
	
	fread(&mat,sizeof(mat),1,FP_MAT);
	while(!feof(FP_MAT)){
		cont = 0;
		// DOBLE VENTANA
		rewind(FP_MAT2);
		fread(&mat2,sizeof(mat2),1,FP_MAT2);
		while(!feof(FP_MAT2)){
			if(mat.legajoDocente == mat2.legajoDocente)
				cont++;
			fread(&mat2,sizeof(mat2),1,FP_MAT2);
		}
		
		//PARA BUSCAR EL NOMBRE SEGUN LEGAJO
		rewind(FP_DOC);
		fread(&profe,sizeof(profe),1,FP_DOC);
		while(!feof(FP_DOC)){
			if(mat.legajoDocente == profe.legajo)
				strcpy(nombreProfe,profe.nom);
				
			fread(&profe,sizeof(profe),1,FP_DOC);
		}
			
		if(!B){ // para guardar el 1er maxima
			strcpy(profeMax,nombreProfe);
			cantMaterias = cont;
			B = 1;
		}else if(cont > cantMaterias){ // comparando segun la cantidad de materias
			strcpy(profeMax,nombreProfe);
			cantMaterias = cont;
		}
		
		fread(&mat,sizeof(mat),1,FP_MAT);
	}
	
	printf("\n\n\t EL PROFE QUE MAS MATERIAS DICTA:	%s",profeMax);
	printf("\n\n\t DICTA:	%d	MATERIAS",cantMaterias);
	fclose(FP_DOC);
	fclose(FP_MAT);
	fclose(FP_MAT2);
	printf("\n\n\n\n");
	return 0;
}