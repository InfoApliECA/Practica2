/*
 * P3_E10.c
 *
 *  Created on: 10 abr. 2017
 *      Author: jose
 */
#include "P3.h"

/*
 * Recomendado:leer algunas transparencias donde con dibujos muy sencillos se muestran
 * las operaciones relacionadas con listas simplemente enlazadas:
 * http://www.dc.uba.ar/materias/int-com/2011/cuat1/Descargas/ListasEnlazadas.pdf
 * http://www.esi2.us.es/~vivas/fi1ii/Tema%208/trasp_T08.pdf
 * http://www.cs.utexas.edu/users/fussell/cs310h/lectures/Lecture_18-310h.pdf
 */

typedef struct Automovil{
	char patente[8];		// 3 letras 3 nros y un guion
	char vin[18];			// 17 digitos y letras para nro.grabado en el motor
	char* marca;
	char* modelo;
	int potencia;			// en alguna unidad, por ej. HP DIN
	char* color;
}Auto;

Auto* creaAuto(char *p, char *v,char* ma, char* mo, int pot,char* c){
	 Auto* auxi = (Auto*) malloc( sizeof(Auto) );

	 strcpy( auxi->patente,p );
	 strcpy( auxi->vin, v );

	 auxi->marca = (char*) malloc( strlen(ma) +1 );
	 strcpy( auxi->marca, ma);

	 auxi->modelo = (char*) malloc( strlen(mo) + 1);
	 strcpy( auxi->modelo, mo);

	 auxi->potencia = pot;

	 auxi->color = (char*) malloc( strlen(c) + 1);
	 strcpy( auxi->color, c );

	 return auxi;
 }


void mostrarAuto( Auto * a ){
	printf("El auto tiene patente: %s\n",a->patente);
	printf("VIN: %s\n",a->vin);
	printf("Marca: %s\n",a->marca);
	printf("Modelo: %s\n",a->modelo);
	printf("Potencia en CV: %d\n",a->potencia);
	printf("Color: %s\n",a->color);

	return;
}

int comparadominios( Auto *a, Auto *b ){
	//si el dominio de a es <que el de b retorna un valor negativo, 0 si son iguales y positivo si el de a es mayor que el de b
	return strcmp( a->patente, b->patente );
}

void cambiaColor( Auto *a, char *c ){
	//ver si funciona por si usé crea auto, aqui no lo usé
	a->color = (char*) malloc( strlen(c) + 1);
	strcpy( a->color, c);
	return;
}


/*
 * Lista enlazada: estructura de datos dinamica para almacenar estructuras 'nodo'
 */

typedef struct Nodo{
	Auto *a;
	struct Nodo* next;//puntero al siguiente nodo que contiene un auto
} nodo;

/*
 * push(): inserta un nodo en la cabeza de la lista (principio), el final se indica
 * con NULL, recibe puntero al comienzo y al nuevo nodo para poder modificar el puntero
 * mismo debo pasar su direccion,por eso paso **, recuerde que en C se pasan argumentos
 * por valor.
 * Aqui se va modificando la cabeza de la lista con cada nodo que agrego al principio
 * Algoritmo Insertar Nodo_{_	p = new Nodo
 * 	info(p) = Elemento de datos a insertar
 * 	sig(p) = inicio
 * 	inicio = p_}
 */

void push( nodo** cabeza, Auto* nuevo ){
	//asigno memoria para el nuevo nodo

	nodo *nuevonodo = (nodo*) malloc( sizeof(nodo) );
	//almacenar el nodo nuevo
	nuevonodo->a = nuevo;
	nuevonodo->next = *cabeza;
	*cabeza = nuevonodo;
}

//crea un nodo nuevo
nodo* nuevoNodo( Auto* nuevo ){
	nodo *nuevonodo=(nodo*)malloc(sizeof(nodo));

	//almacenar el auto nuevo
	nuevonodo->a=nuevo;
	nuevonodo->next=NULL;
	return nuevonodo;
}

//imprimir la lista desde la cabeza hasta la cola (NULL)
void printList(nodo* cabeza){
	nodo* temp=cabeza;
	while(temp){ 			//!=NULL
		mostrarAuto(temp->a);
		temp=temp->next;
	}
}

//inserta un nuevo nodo a la lista, el orden esta dado por el dominio(orden creciente)
void sortedInsert(nodo** cabeza, nodo* nuevo){
	nodo* actual;

	//caso lista vacia o que el que este a la cabeza tenga un dominio mayor que el que quiero insertar
	//quiero saber si el dominio de la cabeza esta despues del dominio del nodo a insertar
	if((*cabeza==NULL) || ((*cabeza!=NULL) && (comparadominios((*cabeza)->a,nuevo->a)>0))){
		nuevo->next=(*cabeza);
		*cabeza=nuevo;
	}
	else{
		//ubicar el nodo anterior a la insercion
		actual=*cabeza;
		while(actual->next !=NULL && comparadominios(actual->next->a,nuevo->a)<0){
			actual=actual->next;//sigo buscando uno mas grande
			}
		nuevo->next=actual->next;//lo intercalo
		actual->next=nuevo;
	}
}

//ordena la lista
void insertionSort(nodo **cabeza)
{
	//inicializo lista ordenada
	nodo *cabezaordenada=NULL;
	//recorre la lista e inserta cada nodo en orden
	nodo* actual=*cabeza;
	nodo* siguiente;
	while(actual!=NULL){
		//almacenar el enlace al siguiente para la proxima iteracion
		siguiente=actual->next;
		//inserta el nodo actual en la lista ordenada
		sortedInsert(&cabezaordenada,actual);
		//actualizo actual
		actual=siguiente;
	}
	//actualiza cabeza para que sea la cabeza de la lista ordenada
	*cabeza=cabezaordenada;
}

void CambiaColorL(Auto *pa, nodo* cabeza, char *c){
	nodo* temp=cabeza;
	while (temp){
		if (comparadominios(temp->a,pa)==0){
			cambiaColor(temp->a,c);
			break;
		}
		temp=temp->next;
	}
}

void eliminar (nodo **L,  nodo *p) {
        nodo *tmp;
       if (*L==p) /* Eliminar el primer elemento */
            *L=p->next;
       else {
            tmp=*L;
            while (tmp->next!=p)
                        tmp=tmp->next;
            /* tmp apunta al anterior */
            tmp->next=p->next;
       }
      free(p);
}

nodo* PotenciaMax(nodo* cabeza){
	nodo* temp=cabeza,*aux=cabeza;
	int pmax=temp->a->potencia;
	while(temp){//!=NULL
		if((temp-> a->potencia) > pmax){
			pmax= temp-> a->potencia;
			aux=temp;
		}

		temp=temp->next;//Driver program to test above functions
	}
	return aux;
}


/*
 * main() para probar las funciones
 */
int E10_main()
{
	Auto a={"ABC 123","1HGBH41JXMN109186","Fiat","Fiorino",44,"rojo alpine"};
	Auto b={"JHG 776","VF33CN6AP1Y400321","Renault", "Clio",76,"azul crepusculo"};
	Auto c={"AHU 234","8AD3CN6AP4G003230","Volkswagen","Fox Highline",110,"negro"};


	nodo *cabeza=NULL;//lista vacia
	nodo *na,*nb,*nc,*potmax;
	na=nuevoNodo(&a);
	sortedInsert(&cabeza,na);
	nb=nuevoNodo(&b);
	sortedInsert(&cabeza,nb);
	nc=nuevoNodo(&c);
	sortedInsert(&cabeza,nc);
	printList(cabeza);
	CambiaColorL(&c,cabeza,"green hep");
	printList(cabeza);
	//eliminar(&cabeza,nc);
	//printList(cabeza);
	potmax=PotenciaMax(cabeza);
	mostrarAuto(potmax->a);

	return 0;
}


