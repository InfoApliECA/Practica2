/*
 * P3_E8.c
 *
 *  Created on: 10 abr. 2017
 *      Author: jose
 */

#include "P3.h"

typedef union ascii{
	unsigned int c;
	struct {
		unsigned char bit0:1;
		unsigned char bit1:1;
		unsigned char bit2:1;
		unsigned char bit3:1;
		unsigned char bit4:1;
		unsigned char bit5:1;
		unsigned char bit6:1;
		unsigned char bit7:1;
	} A;
} Ascii;

char * modificapares( char* s ){
	int n,i;
	Ascii as;
	char *p;

	n = strlen( s );
	p = (char*) malloc(n + 1);

	strcpy( p, s );

	for( i = 0; i < n; i++ ){
		as.c = s[i];	//almaceno el caracter en un byte (0-255)
		as.A.bit0 = ~as.A.bit0;
		as.A.bit2 = ~as.A.bit2;
		as.A.bit4 = ~as.A.bit4;
		as.A.bit6 = ~as.A.bit6;
		p[i] = as.c;
	}
	return p;
}

void E8_main(){
	char frase[] = "a";
	char *p = modificapares(frase);
	printf( "%s\n", p );
	return;
}
