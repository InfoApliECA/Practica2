/*
 * P3_E5.c
 *
 *  Created on: 10 abr. 2017
 *      Author: jose
 */
#include "P3.h"

struct Matrix {
    int N;
    int M;
    int **values;
};

void imprimeMatriz(struct Matrix *myMatrix) {
	int n,m;

	printf("Los valores que contiene la matriz son:\n[");
    for(n = 0; n < myMatrix->N; n++) {
        for(m = 0; m < myMatrix->M; m++) {
            printf("%d, ", myMatrix->values[n][m]);
        }
        printf("\n");
    }
    printf("]\n");
    return;
}

void allocateMatrix(struct Matrix *matrix, int n, int m) {
	int i;

	/* alojar filas */
	matrix->N = n;
    matrix->M = m;
    matrix->values = (int**) malloc(n * sizeof(int*));

	/* alojar columnas */
    for(i = 0; i < matrix->N; i++)
        matrix->values[i] = (int*) calloc(m , sizeof(int));

}

void LlenaMatriz(struct Matrix *myMatrix) {
	int n,m,value;

	for(n = 0; n < myMatrix->N; n++) {
        for(m = 0; m < myMatrix->M; m++) {
            value = rand() % 50;
            myMatrix->values[n][m] = value;
        }
    }
}

struct Matrix* sumaMatriz(struct Matrix *a, struct Matrix *b){
	int i,j;
	struct Matrix* s=(struct Matrix*)malloc(sizeof(struct Matrix));

	allocateMatrix(s,a->N,a->M);
	for(i=0;i<a->N;i++)
		for(j=0;j<a->M;j++)
			s->values[i][j]+=a->values[i][j]+b->values[i][j];
	return s;
}


void E5_main(){

	struct Matrix *pm=(struct Matrix*)malloc(sizeof(struct Matrix));
	struct Matrix *qm=(struct Matrix*)malloc(sizeof(struct Matrix));
	struct Matrix *p;

	//inicializar una única vez
	srand(time(NULL)); /* seeds random function */
	allocateMatrix(pm,2,2);
	LlenaMatriz(pm);
	imprimeMatriz(pm);
	allocateMatrix(qm,2,2);
	LlenaMatriz(qm);
	imprimeMatriz(qm);
	p=sumaMatriz(pm,qm);
	imprimeMatriz(p);
	return;
}


