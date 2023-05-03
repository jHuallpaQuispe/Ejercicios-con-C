#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Fecha{
	int Dia;
	int Mes;
	int Anio;
	
};

void Corregir(struct Fecha *);

int main()
{
	struct Fecha hoy;
	
	hoy.Dia = 29;
	hoy.Mes = 2;
	hoy.Anio = 2005;
	
	printf("\n\n HOY = %02d : %02d : %d \n\n", hoy.Dia, hoy.Mes, hoy.Anio);
	
	
	Corregir(&hoy);
	
	printf("\n\n HOY = %02d : %02d : %d \n\n", hoy.Dia, hoy.Mes, hoy.Anio);
	
	printf("\n\n\n\n");
	return 0;
}

void Corregir(struct Fecha * p)
{
	if(p->Dia == 29 && p->Mes ==2){
		p->Dia = 1;
		p->Mes = 3;
	}
}