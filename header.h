#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int tipo_elemento;
#define random rand()%20
#define VERTICES 5

typedef struct _ARISTA{
    int u;   //vertice u
    int v;  //vertice v
    int costo;
}arista;

typedef struct _RAMA{
    arista a;
    struct _RAMA *sig;
}rama;

typedef struct _ENCABEZADO{
    int cuenta;
    int primer_elemento;
}encabezado;

typedef struct _NOMBRE{
    int nombre_conjunto;
    int siguiente_elemento;
}nombre;

typedef struct _CONJUNTO_CE{
    nombre nombres[VERTICES];
    encabezado encabezamientos_conjunto[VERTICES];
}conjunto_CE;

//funciones kruskal
void inicial(int,int,conjunto_CE*);
void combina(int,int,conjunto_CE*);
int encuentra(int,conjunto_CE*);
void kruskal(rama*);

//funciones para cola de prioridad
void inserta(int i, int j, int M_Costos, rama** nodo);
arista sacar_min(rama**);
void lista(rama* A);

//funciones de ingreso de costos
void aristaAuto(int **M_Costos);
void aristaManual(int **M_Costos);
