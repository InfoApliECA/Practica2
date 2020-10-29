/*
 * P3_E4.c
 *
 *  Created on: 10 abr. 2017
 *      Author: jose
 */
#include "P3.h"

struct TipoPunto {
	double abcisa;
	double ordenada;
};

struct TipoCiudad{
	struct TipoPunto situacion;
	char nombre[50];
};

void Reordenar (struct TipoCiudad ciudades[],
				int num_ciudades,
				const char nombre_ciudad_referencia[]) {

	int i,j,k;
	struct TipoCiudad temp;
	double distancia,dist;

	for( i=0; i<num_ciudades; i++)
		//tiene en cuenta mayusculas y minusculas
		if(strcmp(nombre_ciudad_referencia,ciudades[i].nombre)==0) {
			temp = ciudades[0];
			ciudades[0]=ciudades[i];
			ciudades[i]=temp;
			break;
		}
	for(i=1;i<num_ciudades-1;i++){
		distancia=sqrt(pow((ciudades[0].situacion.abcisa-ciudades[i].situacion.abcisa),2)+pow((ciudades[0].situacion.ordenada-ciudades[i].situacion.ordenada),2));
		k=i;
		for(j=i+1;j<num_ciudades;j++){
			dist=sqrt(pow((ciudades[0].situacion.abcisa-ciudades[j].situacion.abcisa),2)+pow((ciudades[0].situacion.ordenada-ciudades[j].situacion.ordenada),2));
			if(dist<distancia){
				distancia=dist;
				k=j;
			}//fin if
		}//fin for j

		temp=ciudades[i];
		ciudades[i]=ciudades[k];
		ciudades[k]=temp;
	}//fin for i
}

void E4_main(){
	return;
}


