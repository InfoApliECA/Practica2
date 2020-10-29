/*
 * P3-E2.c
 *
 *  Created on: 10 abr. 2017
 *      Author: jose
 */
#include "P3.h"

typedef struct {
	int n;
	double *coeficiente;
} Polinomio;

/* crea y retorna un nuevo Polinomio */
Polinomio * creaPolinomio(int orden){
	Polinomio *p=NULL;
	p=(Polinomio*)malloc(sizeof(Polinomio));
	p->n=orden;
	//ojo no olvidar reservar espacio para el vector de coeficientes, uso calloc
	p->coeficiente=(double*)calloc((orden+1),sizeof(double));
	return p;
}

/* asigna el n_ésimo coeficiente del Polinomio */
void setCoef(int n, double c, Polinomio * P)
{
	if(n<=P->n){
		P->coeficiente[n]=c;
	}
}

/* retorna el n_ésimo coeficiente del Polinomio */
double getCoef(int n, Polinomio * P){
	return P->coeficiente[n];
}

/* calcula el polinomio en x usando:
((...((c[n]*x+c[n-1])*x+c[n-2])*x+ ...+c[1]*x)+c[0]) */
double especializa( double x, Polinomio * P ){
	double suma=0;
	int i;
	for(i=0;i<=P->n;i++)
		suma+=P->coeficiente[i]*pow(x,i);
	return suma;
}

/* suma dos Polinomios retorna un nuevo Polinomio con el resultado */
Polinomio * sum( Polinomio *p1, Polinomio *p2){
	Polinomio *ps, *mayor;
	int orden,i,menor;
	if(p1->n>=p2->n){
		orden=p1->n;
		menor=p2->n;
		mayor=p1;
	}
	else{
		orden=p2->n;
		menor=p1->n;
		mayor=p2;
	}
	ps=creaPolinomio(orden);
	for(i=0;i<=menor;i++)
		ps->coeficiente[i]+=p1->coeficiente[i]+p2->coeficiente[i];
	for(i=menor+1;i<=mayor->n;i++)
		ps->coeficiente[i]+=mayor->coeficiente[i];
	return ps;
}

/* multiplica dos Polinomios y retorna un nuevo Polinomio con el resultado */
Polinomio * mult( Polinomio *p1, Polinomio *p2){
	Polinomio *ps;
	int i, orden,j;
	orden=p1->n+p2->n;
	ps=creaPolinomio(orden);
	for(i=0;i<=p1->n;i++)
		for(j=0;j<=p2->n;j++)
			ps->coeficiente[i+j]+=(p1->coeficiente[i])*(p2->coeficiente[j]);
	return ps;
}

/* libera la memoria asociada con el polinomio */
void destruyePolinomio( Polinomio *p ){
	//libero al revés
	free(p->coeficiente);
	free(p);
}

Polinomio * deriv( Polinomio *p ){
	Polinomio *pd;
	int orden,i;
	orden=p->n;
	pd=creaPolinomio(orden);
	for(i=orden;i>=1;i--)
		pd->coeficiente[i-1]=i*p->coeficiente[i];
	return pd;
}

/* busque por el método de bisección un cero de un polinomio dentro de un intervalo [a,b], con una precisión dada por épsilon y lo retorne*/
double ceropol( Polinomio *p, double a, double b, double epsilon){
	//si p(a)*p(b)>0 no hay raices en ese intervalo
	double c,pa,pb,pc;
	while(fabs(a-b)>=epsilon){
		c=(a+b)/2;
		pa=especializa(a,p);
		pb=especializa(b,p);
		pc=especializa(c,p);
		if(pc==0)
			return c;
		if(pa*pc>0)
			a=c;
		else if(pa*pc<0)
			b=c;
	}
	return c;
}



void E2_main()
{
	Polinomio *q=creaPolinomio(2);
	setCoef(0,-4,q);
	setCoef(1,-11,q);
	setCoef(2,3,q);
	printf("%lf\n",especializa(1.0,q));

}


