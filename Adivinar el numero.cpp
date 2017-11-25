#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

	unsigned int miNumero = -1, contador = 0;
	unsigned int numero;
	/* AGREGUE SUS VARIABLES AQUÍ */
	srand(time(0));
	numero = rand()%1000;
	

	/* AGREGUE SU CODIGO AQUÍ */
	while(miNumero != numero){
		printf("%d",numero);
		printf("Ingrese un numero positivo menor que 1000: \n\n");
		scanf("%u", &miNumero);
		if (miNumero > numero){
			printf("El numero ingresado es MAYOR al generado por el programa, intentelo nuevamente... \n\n");
		}if(miNumero < numero){
			printf("El numero ingresado es MENOR al generado por el programa, intentelo nuevamente... \n\n");
		}
		contador++;
		
	}
	printf("FELICIDADES, acertaste en el intento numero: %d \n\n", contador);
	//system(“PAUSE”);
	return 0;
}
