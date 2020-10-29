/*
 * P3-E1.c
 *
 *  Created on: 10 abr. 2017
 *      Author: jose
 */
#include "P3.h"

typedef struct tiempo {
	int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

typedef struct {
	char * nombre;
	Tiempo ultima_mod;
} Archivo;

int compara_tiempos( Tiempo *t1, Tiempo * t2 ){
	if(t1->anio>t2->anio) return -1;
	if(t1->anio>t2->anio) return 1;
	if(t1->mes > t2->mes)return -1;
	if(t1->mes < t2->mes)return 1;
	if(t1->dia > t2->dia)return -1;
	if(t1->dia < t2->dia)return 1;
	if(t1->hora > t2->hora)return -1;
	if(t1->hora < t2->hora)return 1;
	if(t1->minuto > t2->minuto)return -1;
	if(t1->minuto < t2->minuto)return 1;
	if(t1->segundo > t2->segundo)return -1;
	if(t1->segundo < t2->segundo)return 1;
	else return 0;
}

void imprime_tiempo( Tiempo t ) {
	printf("%d/%d/%d %d:%d:%d\n", t.dia,t.mes,t.anio,t.hora, t.minuto,t.segundo);
}

void ordena_alfa( Archivo * lista, int n ) {
	int i,j;
	Archivo temp;
	for(i=0;i<(n-1);i++)
		for(j=1;j<n;j++)
			if(strcmp(lista[i].nombre,lista[j].nombre)==1){
				temp=lista[i];
				lista[i]=lista[j];
				lista[j]=temp;
			}
}

void ordena_temporal(Archivo * lista, int n ){
	int i,j;
	Archivo temp;
	for(i=0;i<(n-1);i++)
		for(j=1;j<n;j++)
			if(compara_tiempos(&lista[i].ultima_mod,&lista[j].ultima_mod)==-1){
				temp=lista[i];
				lista[i]=lista[j];
				lista[j]=temp;
			}
}

void E1_main()
{
	Tiempo t1={1974,8,3,18,23,59};
	Tiempo t2={1974,8,3,18,22,57};
	int i;
	Archivo lista[]={"Archivo2",{1974,8,3,18,23,59},"Archivo1",{1974,8,3,18,22,57}};
	for(i=0;i<2;i++)
		printf("%s \n",lista[i].nombre);
	printf("%d\n",compara_tiempos(&t1,&t2));
	imprime_tiempo(t1);
	ordena_alfa(lista,2);
	for(i=0;i<2;i++)
		printf("%s \n",lista[i].nombre);
	ordena_temporal(lista,2);
	for(i=0;i<2;i++)
		imprime_tiempo(lista[i].ultima_mod);

	return;
}
