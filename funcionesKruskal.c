#include "header.h"
void inicial(int nombre,int  elemento ,conjunto_CE* c){  //inicializa el conjunto_CE
    c->nombres[elemento].nombre_conjunto = nombre;  //guarda el nombre del conjunto
    c->nombres[elemento].siguiente_elemento=0; //puntero nulo al sig elemento
    c->encabezamientos_conjunto[nombre].cuenta = 1; // inicializa la cuenta en 1
    c->encabezamientos_conjunto[nombre].primer_elemento = elemento; //guarda el primer elemento
}

void combina(int a,int b,conjunto_CE* c){ //combina a y b en el conjunto c, y llama al resultado a o b arbitrariamente
    int i;
    if(c->encabezamientos_conjunto[a].cuenta > c->encabezamientos_conjunto[b].cuenta){ //A es el conjunto mas grande, combina b dentro de a
        i = c->encabezamientos_conjunto[b].primer_elemento;
    while(c->nombres[i].siguiente_elemento != 0){ //encuentra el final de b, cambiando el nombre de los conjuntos por a conforme se avanza
        c->nombres[i].nombre_conjunto = a;      //agrega a la lista a al final de la b y llama 'a' al resultado
        i = c->nombres[i].siguiente_elemento;   //ahora i es el indice del ultimo elemento de b
    }

    c->nombres[i].nombre_conjunto = a;
    c->nombres[i].siguiente_elemento = c->encabezamientos_conjunto[a].primer_elemento;
    c->encabezamientos_conjunto[a].primer_elemento = c->encabezamientos_conjunto[b].primer_elemento;
    c->encabezamientos_conjunto[a].cuenta = c->encabezamientos_conjunto[a].cuenta + c->encabezamientos_conjunto[b].cuenta;

    }else{
        i = c->encabezamientos_conjunto[a].primer_elemento; //B es el conjunto mas grande, combina a dentro de b
    while(c->nombres[i].siguiente_elemento != 0){
        c->nombres[i].nombre_conjunto = b;
        i = c->nombres[i].siguiente_elemento;
    }

    c->nombres[i].nombre_conjunto = b;
    c->nombres[i].siguiente_elemento = c->encabezamientos_conjunto[b].primer_elemento;
    c->encabezamientos_conjunto[b].primer_elemento = c->encabezamientos_conjunto[a].primer_elemento;
    c->encabezamientos_conjunto[b].cuenta = c->encabezamientos_conjunto[b].cuenta + c->encabezamientos_conjunto[a].cuenta;

    }
}



int encuentra(int x,conjunto_CE* c){        //devuelve el nombre del conjunto que tiene a x como miembro
    return(c->nombres[x].nombre_conjunto);
}

void kruskal(rama* arbol){              //funcion principal, ejecuta el algoritmo de kruskal y muestra el arbol solucion y su costo total
    int comp_n= VERTICES;
    arista a;
    conjunto_CE componentes;
    int v;
    int comp_u, comp_v;
    int costoFinal = 0;

    rama *solucion = NULL;              // arbol auxiliar para guardar el resultado

    for (v=0;v<comp_n;v++){
        inicial(v,v,&componentes);      //inicializa el conjunto_CE
    }

    while(comp_n>1){
        a = sacar_min(&arbol);          //toma el primer valor del arbol que ya habia sido ordenado
        comp_u = encuentra(a.u,&componentes);   //devuelve el nombre del conjunto que tiene el vertice u como miembro
        comp_v = encuentra(a.v,&componentes);   //devuelve el nombre del conjunto que tiene el vertice v como miembro

    if(comp_u != comp_v){                       //comprueba que no haya ciclos comprobando que los vertices no formen parte del mismo conjunto
        combina(comp_u,comp_v,&componentes);
        comp_n -= 1;
        inserta(a.u,a.v,a.costo, &solucion);    //guarda la arista y su costo en el arbol solucion
        costoFinal += a.costo;                  //suma el costo para para obtener el peso minimo del arbol
    }
    }
    lista(solucion);
    printf("\nCosto total del arbol: %d\n",costoFinal);
}


