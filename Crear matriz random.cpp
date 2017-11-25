#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int main ()
{
    int i,j,A[10][10],n;
    srand(time(NULL));
     printf("ingrese la dimencion de la matriz...");
       scanf("%d",&n);
   for(i=1;i<=n;i++){
   for(j=1;j<=n;j++){
                      A[i][j]=rand()%10;
                      }
                      }
                       for(i=1;i<=n;i++){
                       for(j=1;j<=n;j++){
                      printf("[%d]",A[i][j]);
                      }
                      printf("\n");
                      }
                      
                      
    
    getchar();
    getchar();
    
    
    
}
