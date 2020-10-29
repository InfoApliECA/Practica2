/*
 * P3_E6.c
 *
 *  Created on: 10 abr. 2017
 *      Author: jose
 */
#include "P3.h"

typedef struct{
	unsigned char R, G, B;	//componentes primarios de un color
} RGB;

typedef struct{
	int ancho, alto;
	RGB **pixel;			//puntero a puntero a una estructura
} ImagenRGB;

typedef unsigned char Gris;

typedef struct{
	int ancho, alto;
	Gris **pixel;
} ImagenGris;

/* crea y retorna una nueva ImagenRGB */
ImagenRGB * creaImagenRGB( int ancho, int alto ){
	ImagenRGB *pi;
	int i;
	pi=(ImagenRGB*)malloc(sizeof(ImagenRGB));
	pi->ancho=ancho;
	pi->alto=alto;
	pi->pixel=(RGB**)malloc(alto*sizeof(RGB*));
	for(i=0;i<alto;i++)
		pi->pixel[i]=(RGB*)malloc(ancho*sizeof(RGB));
	return pi;
}

/* asigna el pixel de la fila y columna dadas */
void setPixelRGB( ImagenRGB *im, int fila, int columna, RGB * pix ){
	im->pixel[fila][columna].R=pix->R;
	im->pixel[fila][columna].G=pix->G;
	im->pixel[fila][columna].B=pix->B;
}

/* retorna el pixel de la fila y columna dadas */
RGB * getPixelRGB( ImagenRGB *im, int fila, int columna ){
	/*
	 * en pixel[fila][columna] hay un RGB (ver segundo malloc en creaImagenRGB,
	 *  para convertirlo a puntero paso dirección
	 */
	return (&(im->pixel[fila][columna]));
}

/* libera la memoria asociada con la imagen im */
void destruyeImagenRGB( ImagenRGB * im){
	//libero en orden opuesto a la asignación con malloc
	int i;
	//primero libero la matriz de pixeles
	for(i=0;i<im->alto;i++)
		free(im->pixel[i]);
	free(im->pixel);
	//libero el espacio reservado para la imagen
	free(im);
	return;
}

/* crea y retorna una nueva ImagenGris */
ImagenGris * creaImagenGris( int ancho, int alto ){
	ImagenGris *pg;
	int i;
	pg=(ImagenGris*)malloc(sizeof(ImagenGris));
	pg->ancho=ancho;
	pg->alto=alto;
	pg->pixel=(Gris**)malloc(alto*sizeof(Gris*));
	for(i=0;i<alto;i++)
		pg->pixel[i]=(Gris*)malloc(ancho*sizeof(Gris));
	return pg;
}

/* asigna el pixel de la fila y columna dadas */
void setPixelGris( ImagenGris *im, int fila, int columna, Gris * pix ){
	im->pixel[fila][columna]=*pix;
}

/* retorna el pixel de la fila y columna dadas */
Gris getPixelGris( ImagenGris *im, int fila, int columna ){
	return (im->pixel[fila][columna]);
}

/* libera la memoria asociada con la imagen im */
void destruyeImagenGris( ImagenGris * im){
	//idem a la de ImagenRGB
	int i;
	//libero en orden opuesto a la asignación con malloc
	//primero libero la matriz de pixeles
	for(i=0;i<im->alto;i++)
		free(im->pixel[i]);
	free(im->pixel);
	//libero el espacio reservado para la imagen
	free(im);
}

/* convierte un pixel RGB en uno Gris usando la fórmula: Gris = 0.299*R+0.587*G+0.114*B */
Gris RGBtoGris( RGB * pix ){
	//Gris es un unsigned char asi que como * por float lo tengo que convertir a un unsigned char, pierdo la parte decimal
	return ((unsigned char)(pix->R*0.299+pix->G*0.587+pix->B*0.114));
}

/* transforma la imagenRGB en una nueva ImagenGris */
ImagenGris * transforma( ImagenRGB * im ){
	int i,j;
	RGB *pix;
	Gris g;
	ImagenGris *pg=creaImagenGris(im->ancho,im->alto);
	for(i=0;i<pg->alto;i++)
		for(j=0;j<pg->ancho;j++){
			pix=getPixelRGB(im,i,j);
			g=RGBtoGris(pix);
			setPixelGris(pg,i,j,&g);
		}
	return pg;
}

void E6_main()
{
	//imagen microscópica, para probar las funciones!!
	ImagenRGB *p=creaImagenRGB(2,2);
	int i,j;
	RGB *q;
	RGB colores[]={{10,10,10},{20,20,20},{30,10,20},{10,20,30}};
	ImagenGris *pg;
	Gris g;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++){
			setPixelRGB(p,i,j,&colores[i*2+j]);
			q=getPixelRGB(p,i,j);
			printf("El pixel %d,%d contiene %u de rojo, %u de verde, %u de azul\n",i+1,j+1,q->R,q->G,q->B);
		}

	printf("Transformo la imagen en una Gris\n");
	pg=transforma(p);
	for(i=0;i<2;i++)
		for(j=0;j<2;j++){
			g=getPixelGris(pg,i,j);
			printf("El pixel %d,%d contiene %u de gris\n",i+1,j+1,g);
		}
	return;
}


