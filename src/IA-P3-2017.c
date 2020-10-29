/*
 ============================================================================
 Name        : IA-P3-2017.c
 Author      : JLS
 Version     :
 Copyright   : DSI-EIE-FCEIA
 Description : Ejercicios resueltos de practica C 
 ============================================================================
 */

#include "P3.h"

void main(void) {
	int ej;

	puts("\nInformatica Aplicada - Practica 2");
	puts("\n---------------------------------");

	while( 1 ){
		puts("\nIngrese nro. de ejercicio, 0 para salir: ");

		scanf("%d", &ej);

		switch( ej ){
		case 0:
			return;

		case 1:
			E1_main();
			break;

		case 2:
			E2_main();
			break;

		case 4:
			E4_main();
			break;

		case 5:
			E5_main();
			break;

		case 6:
			E6_main();
			break;

		case 7:
			E7_main();
			break;

		case 8:
			E8_main();
			break;

		case 9:
			E9_main();
			break;

		case 10:
			E10_main();
			break;
		case 11:
			E11_main();
			break;

		default:
			break;

		}
	}
	return;
}
