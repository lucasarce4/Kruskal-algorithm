#include "header.h"

int main(){
    srand(time(NULL));
    rama *arbol= NULL;
    int **M_Costos;
    int opcion=0;

    M_Costos = (int**)malloc(sizeof(int*)*VERTICES);      //carga la matriz en memoria dinamica
    if(M_Costos == NULL){
        printf("Error");
        return -1;
    }
    for (int i=0;i<VERTICES;i++){
        M_Costos[i]= (int*)malloc(sizeof(int)*VERTICES);
         if(M_Costos[i] == NULL){
        printf("Error");
        return -1;
    }
    }

    printf("Algoritmo de kruskal, ingrese los costos de las aristas\n");

    while(opcion <1 || opcion > 2){
        printf("1-Carga manual de aristas\n2-Carga automatica de aristas\n");
        scanf("%d",&opcion);
        if(opcion == 1){
            aristaManual(M_Costos);
            break;
        }else if(opcion == 2){
            aristaAuto(M_Costos);
            break;
        }else{
            printf("Opcion no valida\n");
            getchar();      //getchar para evitar bucle infinito en caso que se ingrese un char
        }
    }


    for(int i=0;i<VERTICES;i++){
        for(int j=i+1;j<VERTICES;j++){
            if(M_Costos[i][j]!=0){
                inserta(i,j,M_Costos[i][j],&arbol);     //llama a la funcion inserta con cada costo de la arista ingresado para guardarlo en el arbol
            }
        }
    }
    /*printf("\arbol ordenado\n");         //muestra las aristas del arbol ordenadas, esta funcion la deje comentada por que no era necesaria mostrarla, es solamente para ver el resultado de la funcion inserta
    lista(arbol);*/
    printf("\nArbol de costo minimo generado con kruskal\n");
    kruskal(arbol);

    for(int i=0;i<VERTICES;i++){
        free(M_Costos[i]);          //libera la matriz reservada
    }
    free(M_Costos);

    rama *aux;
    while(arbol != NULL){
        aux = arbol;
        arbol = arbol->sig;
        free(aux);
    }

    return 0;
}

void aristaAuto(int **M_Costos){
        printf("Arbol generado automaticamente con costos de 0 a 20\n");
        for(int i=0;i<VERTICES;i++){
        for(int j=i+1;j<VERTICES;j++){
            printf("Arista (%d,%d) - Costo: ",i,j);
            M_Costos[i][j] = random;
            printf("%d\n",M_Costos[i][j]);
        }
    }
}

void aristaManual(int **M_Costos){
        for(int i=0;i<VERTICES;i++){
        for(int j=i+1;j<VERTICES;j++){
            printf("Ingrese el costo de la arista (%d,%d): ",i,j);
            scanf("%d",&M_Costos[i][j]);
            if(M_Costos[i][j]<0){
                printf("Costo erroneo, ingrese un costo mayor o igual a 0\n");
                j--;
            }
        }
    }
}


