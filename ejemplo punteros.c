#include <stdio.h>
#include <malloc.h>
//definicion de una estructura
/* | int   |  puntero |
    la estructura (nodo) se basa en un int y un puntero

    en caso de arboles la estructura seria
    int dato, struct nodo next1, next2;
    debe tener 2 nodos que apuntan a la izquierda y derecha respectivamente*/
typedef struct nodo{
    int dato;
    struct nodo *next;
}*NODO;

//crear la lista con la estructura

NODO crearlista(int a){
    NODO nuevo;
    nuevo = (NODO)malloc(sizeof(struct nodo));
    nuevo->next=NULL;
    nuevo->dato=a;
    return nuevo;
}

//codigo para insertar un nodo en la lista
NODO insertar(int a,NODO lista){
    NODO tmp,aux;
    tmp = (NODO)malloc(sizeof(struct nodo));
    tmp->next=NULL;
    tmp->dato=a;
    aux = lista;
    while(aux->next!=NULL) aux=aux->next;
    aux->next=tmp;
    return lista;
}

//imprime la lista
void ver(NODO lista){
    NODO aux=lista;
    while(aux!=NULL){
        printf("%d",aux->dato);
        aux=aux->next;
    }
}

//elimina un elemento de la lista
void eliminar(int a,NODO *lista){
    NODO aux=*lista,tmp,prev;
    if(aux->dato==a){
        *lista=aux->next;
        tmp=aux;
        free(tmp);
    }
    else{
        prev=aux;
        while(aux!=NULL){
            if(aux->dato==a){
                prev->next=aux->next;
                tmp=aux;
                free(tmp);
            }
            else{
                prev=aux;
                aux=aux->next;
            }
        }
    }
}


int main(){
    int i;
    NODO lista;
    lista = crearlista(5);
    for(i=0;i<3;i++) lista=insertar(i,lista);
    ver(lista);
    eliminar(1,&lista);
    ver(lista);
    return 0;
}
