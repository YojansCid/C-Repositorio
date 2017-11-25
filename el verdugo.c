#include <stdio.h>
#include <stdlib.h>

typedef struct prisioneros{
       struct prisioneros *Sig;
       struct prisioneros *atras;
       int estado;  /* Estado = 1:muerto , Estado=0 ; vivo */ 
}*VERDUGO;

VERDUGO crear_prisioneros(VERDUGO cabeza, int numero_prisioneros, int posicion_amigo);
int salvar_amigo(VERDUGO cabeza,int numero_prisioneros,int posicion_amigo,int numero_frecuencia);
int main(int argc, char *argv[]){ 
  
  VERDUGO cabeza=NULL;  
  int numero_prisioneros,posicion_amigo,numero_frecuencia,posicion_inicio,posicion;
           
            printf("\n *Ingresar el numero de prisioneros: ");
            do{
            scanf("%d",&numero_prisioneros);
            }while(numero_prisioneros<2);
                   printf("\n *Ingresar el salto de prisioneros: ");
                   scanf("%d",&numero_frecuencia);
            printf("\n *Ingresar la posicion del amigo del verdugo:\n ");
            do{
               scanf("%d",&posicion_amigo);
            }while(posicion_amigo > numero_prisioneros);       

			printf("\nmatando prisioneros...");
			 system("PAUSE");

            cabeza=crear_prisioneros(cabeza,numero_prisioneros,posicion_amigo);
            posicion=salvar_amigo(cabeza,numero_prisioneros,posicion_amigo,numero_frecuencia);           
            printf("\n\n * EL PRIMER PRISIONERO QUE DEBE MORIR PARA QUE SE SALVE");
printf("\n\n *EL AMIGO DEL VERDUGO ES EL PRISIONERO NUMERO: %d\n ",posicion);
  system("PAUSE");	
  return 0;
}

VERDUGO crear_prisioneros(VERDUGO cabeza, int numero_prisioneros, int posicion_amigo){
        VERDUGO nodo,cola;
        int i;    
            for(i=1;i<=numero_prisioneros;i++){
                nodo=(VERDUGO)malloc(sizeof(struct prisioneros));
                if(i==posicion_amigo){
                   nodo->estado=1;
                }
                else{
                nodo->estado=0;
                }
                nodo->Sig;
                if(cabeza==NULL){
                   cabeza=nodo;
                   cola=nodo;
                }
                else{
                   cola->Sig=nodo;
                   nodo->atras=cola;
                   cola=cola->Sig;
                 }                
             }
             cola->Sig=cabeza;
             cabeza->atras=nodo;
}



int salvar_amigo(VERDUGO cabeza,int numero_prisioneros,int posicion_amigo,int numero_frecuencia){                       
    VERDUGO aux=cabeza,p;
    int contador_fin=1,contador_estado=0,posicion;        
           while(contador_fin<=numero_prisioneros){
           aux=aux->atras;     
           contador_fin++;
           }
           while(aux->estado==0)aux=aux->atras;
           contador_fin=0;
           aux=aux->atras;
           
           while(contador_fin < numero_prisioneros-1){
                 
                 if(aux->estado==0){
                    contador_estado++;
                    if(contador_estado==numero_frecuencia){                                   
                       contador_estado=0;
                       contador_fin++;
                       aux->estado=1;
                      
                       
                       }
                 }
                   
                  aux=aux->atras;    
                  p=aux;    
                    
           }
           p->estado=0;
           aux=cabeza;
           contador_fin=1;
           while(contador_fin<=numero_prisioneros){
            if(aux->estado==0)posicion=contador_fin;                                      
           aux=aux->Sig;     
           contador_fin++;
           }
            
                                                                                          
   return posicion;  
}
       
