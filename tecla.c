#include <stdio.h>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

void main()

{

char tecla;
char especial;

printf("Pulsa una tecla de direcion o la tecla escape para salir\n");

tecla= getch();
especial=getch();
_kbhit();


if (especial==-32)
{

switch(tecla)
{
case 72: printf(">> Arriba....\n");
break;
case 80: printf(">> Abajo....\n");
break;
case 75:printf(">> Izquierda...\n");
break;
case 77:printf(">> Derecha....\n");
break;
default:printf(">> Tecla desconocida....\n");
break;
}
}
else
{
if (tecla== 27)
printf(">> Saliendo...");
}
system("PAUSE");

}
