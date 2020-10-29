/*
 * P3_E7.c
 *
 *  Created on: 10 abr. 2017
 *      Author: jose
 */
#include "P3.h"

typedef union byte {
	short int si;
	int i;
	long long int lli;
	float f;
	double d;
	unsigned long long int ulli;

	unsigned char bytes[24];
} Bytes;

void E7_main()
{
	char buffer[21];
	unsigned char * p;

	short int intCor = 29813; 								// Entero corto 16 bits.
	int intEst = 548524874; 								// Entero estandar 32 bits, equivalente "long int"
	long long int intLar = -84467073709551615;				// Entero largo 64 bits
	float decEst = 4.7575f; 								// Decimal punto flotante estandar 32 bits
	double decLar = -7.348744198498e2f; 					// Decimal punto flotante largo 64 bits
	unsigned long long int uintLart = 18446744073709551610; // Entero largo 64 bits sin signo

	Bytes b;
	int i, tam;

	// no estandar: itoa(intCor,buffer,16);
	sprintf( buffer, "%x", intCor );
	printf("%s\n",buffer);
	// no estandar: itoa(intCor,buffer,8);
	sprintf( buffer, "%o", intCor );
	printf("%s\n",buffer);

	printf("La direccion de la union es: %p\n",&b);

	/*
	 * Sugerencia para hacerlo con punteros: usar pBytes incrementando en el lazo for
	 */
	unsigned char * pBytes;
	pBytes = (unsigned char *) &b;


	// short int
	b.si = intCor;
	tam = sizeof( b.si );
	printf("\n---------------------------------------");
	printf("\nshort int: %d (%d bytes)\n", b.si, tam);
	for( i = 0; i < tam; i++){
		printf("Byte %d: %x\n", i, b.bytes[i]);
		printf("Offset de bytes[%d] es %ul\n", i, offsetof( Bytes, bytes[i]));
	}

	// int
	b.i = intEst;
	tam = sizeof( b.i );
	printf("\n---------------------------------------");
	printf("\nint: %d (%d bytes)\n", b.i, tam );
	for( i = 0; i < tam; i++){
		printf("Byte %d: %x\n",i,b.bytes[i]);
		printf("Offset de 'bytes[%d] es %u\n", i, offsetof( Bytes, bytes[i]));
	}

	// long long int
	b.lli = intLar;
	tam = sizeof( b.lli );
	printf("\n---------------------------------------");
	printf("\nlong long int: %d (%d bytes)\n", b.lli, tam);
	for( i = 0; i < tam; i++){
		printf("Byte %d: %x\n",i,b.bytes[i]);
		printf("Offset de bytes[%d] es %u\n", i, offsetof( Bytes, bytes[i]));
	}

	// float
	b.f = decEst;
	tam = sizeof( b.f );
	printf("\n---------------------------------------");
	printf("\nfloat: %f (%d bytes)\n", b.f, tam);

	for( i = 0; i < tam; i++){
		printf("Byte %d: %x\n",i,b.bytes[i]);
		printf("Offset de bytes[%d] es %u\n", i, offsetof( Bytes, bytes[i]));
	}

	// double
	b.d = decLar;
	tam = sizeof( b.d );
	printf("\n---------------------------------------");
	printf("\ndouble: %f (%d bytes)\n", b.d, tam);

	for( i = 0; i < tam; i++){
		printf("Byte %d: %x\n",i,b.bytes[i]);
		printf("Offset de bytes[%d] es %u\n", i, offsetof( Bytes, bytes[i]));
	}

	// unsigned long long int
	b.ulli = uintLart;
	tam = sizeof( b.ulli );
	printf("\n---------------------------------------");
	printf("\nunsigned long long int: %u (%d bytes)\n", b.ulli, tam);

	for( i = 0; i < tam; i++){
		printf("Byte %d: %x\n",i,b.bytes[i]);
		printf("Offset de bytes[%d] es %u\n", i, offsetof( Bytes, bytes[i]));
	}

	return;
}


