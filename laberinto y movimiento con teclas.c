#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct celda
{
 char izq,arr,der,abj;
 char per;
} CELDA;

CELDA crear(char izq, char arr, char der, char abj,char per)
{
 CELDA nuevo;
 nuevo.izq=izq;
 nuevo.arr=arr;
 nuevo.der=der;
 nuevo.abj=abj;
 nuevo.per=per;
 return nuevo;
}

void cargar(char datos[4][32])
{
     FILE*archivo;
    int i,j;
    char dato;
    if((archivo=fopen("lab.txt","r"))==NULL){ printf("No se encuentra el archivo...");
}
    for(i=1;i<=4;i++){
                      for(j=1;j<=31;j++){
                      fscanf(archivo,"%c",&dato);
                      datos[i-1][j-1]=dato;
}
}

fclose(archivo);
}

void crea_laberinto(char datos[4][32],CELDA laberinto[5][5])
{
 CELDA D;
 int i,j,k=0;
 for(i=0;i<5;i++){
    for(j=0;j<6;j++){
		  D=crear(datos[i][k],datos[i][k+1],datos[i][k+2],datos[i][k+3],datos[i][k+4]);
          laberinto[i][j]=D;
          k+=5;
    }
    k=0;
 }
}

void imprime_celda(CELDA lab[5][5])
{
 int i=0,j=0;
  for(i=0;i<4;i++){
    for(j=0;j<5;j++){
    				 printf("(%c,%c,%c,%c,%c)",lab[i][j].izq,lab[i][j].arr,lab[i][j].der,lab[i][j].abj,lab[i][j].per);
    }
    printf("\n");
  }
  printf("\n");

}
void IMPRIMIR(CELDA lab[5][5]){
	int i,j,n=4,m=6;
	for(i=0;i<n;i++)
          { 
           for(j=0;j<m;j++)
               {
               if(lab[i][j].arr=='1'){
                     printf("%c%c%c",205,205,205);
       					 }
               			else{
               				printf("   ");	
            }}
			printf("\n");     
    
           for(j=0;j<m;j++){
     			if(lab[i][j].izq=='1'&& lab[i][j-1].der!='1'){
                  printf("%c",186);
                  }
                  else{
                  printf(" ");
                  }
                  if(lab[i][j].per=='g'){
                    printf("%c",2);
     					}else{
           					if(lab[i][j].per=='q'){
                          					printf("%c",127);
                          					}
           						if(lab[i][j].per=='v'){
                          				printf(" ");
                          						}
           					if(lab[i][j].per=='r'){
                          					printf("%c",1);
           								}

							} 
					if(lab[i][j].der=='1'){
                          printf("%c",186);
                          }else{
                                printf(" ");
                                }

               }
           printf("\n");
           for(j=0;j<m;j++)
               {
           			if(lab[i][j].abj=='1'&& lab[i+1][j].arr!='1'){
                        printf("%c%c%c",205,205,205);
                        }else{
                        printf("   ");
                        }
               }
          printf("\n");
		  }
          
	}


int main(){
    int Max_filas=4;
    int Max_columnas=5;
    char datos[4][32];
	char dir,aux;
	int i,j,flag,cont_queso=0;
    CELDA laberinto[5][5];
    srand(time(NULL));
    cargar(datos);
    crea_laberinto(datos,laberinto);
	//imprime_celda(laberinto);
	i=1+rand()%(Max_filas-1);
    j=1+rand()%(Max_columnas-1);
    printf("\n\t\tINSTRUCIONES\n");
    printf("\n\n     ESC = SALIR\n\n");
    printf("     DIRECCION:\n");
    printf("                   %c\n\n",30);
    printf("                %c     %c\n\n",17,16);
    printf("                   %c\n\n",31);
    printf("     LISTO? Presione < ENTER > para iniciar juego\n");
     dir = getch();
     
     if(dir == (13) ){
     
    
while(laberinto[i][j].per!='r'){
                                        if(laberinto[i][j].per!='q' && laberinto[i][j].per!='g'){
                                                                 laberinto[i][j].per='r';
                                        }else{
                                              i=1+rand()%(Max_filas-1);
                                              j=1+rand()%(Max_columnas-1);
                                              }
                                        }
                                        
	while( dir != (27) && aux!= 'g' && flag!=1)
    {      
    system("cls");
    IMPRIMIR(laberinto);
       dir = getch();
    //Arriba//
    if(dir== (72) ){ 
             if(laberinto[i-1][j].abj!='1'){ 
                  aux = laberinto[i-1][j].per;
                  laberinto[i-1][j].per = 'r';
                  laberinto[i][j].per = 'v';
                  i--;
                  if(aux == 'q'){
                    cont_queso+=1;
                    }
                                        }
             }
    //Derecha//
    if(dir==(77)){ 
                   if(laberinto[i][j+1].izq!='1'){
                   aux = laberinto[i][j+1].per;
                   laberinto[i][j+1].per = 'r';
                   laberinto[i][j].per = 'v';
                   j++;
                   if(aux == 'q'){
                    cont_queso+=1;
                                  }
                                             }
                  }
    //Izquierda//
    if(dir== (75)){ 
                    if(laberinto[i][j-1].der!='1'){
                    aux = laberinto[i][j-1].per;  
                    laberinto[i][j-1].per = 'r';
                    laberinto[i][j].per = 'v';
                    j--;
                    if(aux == 'q'){
                    cont_queso+=1;
                                     }
                                               }
                  }
    //Abajo//
    if(dir== (80)){ 
                    if(laberinto[i+1][j].arr!='1'){
                    aux = laberinto[i+1][j].per;                        
                    laberinto[i+1][j].per = 'r';
                    laberinto[i][j].per = 'v';
                    i++;
                    if(aux == 'q'){
                    cont_queso+=1;
                                     }
                                              }
                    }
        /*if(laberinto[i][j].per == laberinto[0][j] || laberinto[i][j] == laberinto[i][0]
    ||laberinto[i][j] == laberinto[Max_filas-1][j] || laberinto[i][j] == laberinto[i][Max_columnas-1]){
       flag=1;
      } */
}
}
system("cls");
if(aux == 'g'){
       printf("\n\n Ratoncito se lo comio un Gato :-(\n");
       }
if(flag==1){
            printf("\n\n Ratoncito acaba de salir del Laberinto con vida...\n");
            }
printf("\n\n Quesos Comidos: %d\n\n",cont_queso);
printf("    <<<  FIN DEL JUEGO  >>>\n\n");
system("pause");
return 0;
}
