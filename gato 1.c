#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matriz(fila,col){
	int M[5][5],i,j;
	for(i=0;i<5;i++){
        for(j=0;j<5;j++){
	if(M[fila-1][col-1]==M[i][j]){
		M[i][j]=1;
	}
			else{
				M[i][j]=0;
			}
			printf("[%d]",M[i][j]);

		}
		printf("\n");
	}

}


	int main(){
		int fila,col;
		printf("ingrese fila...");
		scanf("%d",&fila);
		printf("ingrese columna...");
		scanf("%d",&col);
		matriz(fila,col);
		getchar();
		getchar();
	system("PAUSE");
  return 0;
}
