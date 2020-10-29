/*
 * P3_E9.c
 *
 *  Created on: 10 abr. 2017
 *      Author: jose
 */
#include "P3.h"

typedef struct comunicacion {
	unsigned char broadcast:1;
	unsigned char unicast:1;
	unsigned char multihop:1;
	unsigned char singlehop:1;
	unsigned char enviado:1;
	unsigned char noenviado:1;
	unsigned char recibido:1;
	unsigned char norecibido:1;
} Comunica;

void tipocomunicacion( Comunica c ){
	if( c.broadcast == 1 )
		printf( "La comunicacion es tipo: broadcast y " );
	else
		printf( "La comunicacion es tipo: unicast y " );

	if( c.multihop == 1 )
		printf( "multihop. " );
	else
		printf( "single hop. " );

	if( c.enviado == 1 )
		printf( "El mensaje se envio correctamente " );
	else
		printf( "El mensaje no pudo enviarse " );

	if( c.recibido == 1 )
		printf( "y se recibió OK.\n" );
	else
		printf( "y no fue recibido\n" );
}


	/*
	 * main(): simula condiciones aleatorias de envio y recepcion de mensajes
	 */
void E9_main()
{
	Comunica c;
	int i,n;

	srand( time( NULL ) );		// inicializa el generador de nuemeros pseudoaleatorios

	for( i = 0; i < 6; i++ ){
		n = rand() % 2;
		c.broadcast = n;

		if( n == 0 )
			c.unicast = 1;
		else
			c.unicast = 0;

		n = rand() % 2;
		c.multihop=n;

		if( n == 0 )
			c.singlehop = 1;
		else
			c.singlehop = 0;

		n = rand() % 2;
		c.enviado = n;
		if( n == 1 ){				//se pudo enviar
			c.noenviado=0;

			n = rand() % 2;
			c.recibido = n;
			if( c.recibido == 1)	//se recibio
				c.norecibido = 0;
			else 					//no se recibio
				c.norecibido = 1;
		}
		else{						//no se pudo enviar
			c.norecibido = 1;
			c.recibido = 0;
		}
		tipocomunicacion(c);
	}
	return;
}


