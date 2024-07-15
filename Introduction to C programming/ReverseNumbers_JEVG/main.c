#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void posicion(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main() {
    int z,n,x,y,n1;

do
{
system("cls");
x=0;
y=3;
    printf("Ingresa un numero\n");
    scanf("%i",&n);



    for(n;n>0;n--)
    {
        n1=1;
        posicion(x++,y); printf("%i ",n);
        for(n1;n1<n;n1++)
    {
            posicion(x++,y); printf("%i",n);
    }

    }


printf("\n\n\n PRESIONA 1 PARA REPETIR");
z=getche();



}while(z=49);
}

