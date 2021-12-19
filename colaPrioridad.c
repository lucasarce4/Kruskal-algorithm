#include "header.h"

void inserta(int i, int j, int M_Costos, rama** nodo){
     if ((*nodo) == NULL){                                  //cola vacia
        (*nodo) = (rama*) malloc (sizeof(rama));
        (*nodo)->a.u = i;                                   //vertice u de la arista
        (*nodo)->a.v = j;                                   // vertice v de la arista
        (*nodo)->a.costo = M_Costos;                        //costo de la arista
        (*nodo)->sig = NULL;
    } else {
            rama *nuevo = (rama*) malloc (sizeof(rama));
        if ((*nodo)->a.costo > M_Costos){   //si el costo de la nueva arista es menor que la del nodo actual se guarda primero en la cola
            nuevo->a.costo = M_Costos;  //se guarda en el nodo nuevo
            nuevo->a.u = i;             //vertice u de la arista
            nuevo->a.v = j;             //vertice v de la arista
            nuevo->sig = (*nodo);       //se guarda el nodo en el posicion siguiente al nuevo
            (*nodo) = nuevo;            //se reemplaza el nodo actual con el nuevo para cambiarlos de lugar
        } else if (((*nodo)->a.costo <= M_Costos) && ((*nodo)->sig != NULL) && ((*nodo)->sig->a.costo > M_Costos)){ //Guarda la nueva arista entre dos nodos --arista existente < arista nueva < arista existente
            nuevo->a.costo = M_Costos;
            nuevo->a.u = i;
            nuevo->a.v = j;
            nuevo->sig = (*nodo)->sig;
            (*nodo)->sig = nuevo;
            }else {
            inserta(i,j,M_Costos,&((*nodo)->sig)); //si el costo de la arista es el mayor se llama recursivamente a la funcion
        }
    }
}


void lista(rama* nodo){     //funcion para imprimir la cola ordenada
  if(nodo!=NULL){
         printf("Arista (%d,%d) - Costo: %d\n",nodo->a.u,nodo->a.v,nodo->a.costo); //imprime los vertices y el costo de la arista
        lista(nodo->sig);   //se llama recursivamente el nodo siguiente
}
}

arista sacar_min(rama** nodo){      //funcion que devuelve la arista de menor costo y la elimina de la lista
        arista aux;                 //se crea una arista auxiliar
    if(nodo != NULL){               //se comprueba que el nodo no sea nulo
        aux = (*nodo)->a;           //se copia la arista
        (*nodo) =  (*nodo)->sig;    //se cambia al nodo siguiente
    }
        return(aux);                //retorna la arista
}
