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
    int primos_por_mostrar, n, d,x,y,list,z;
    int es_primo;

do
{
    system("color 1F");
    printf("Cuantos primos desea mostrar: ");
    scanf("%d", &primos_por_mostrar);

    n = 2;
    x=0;
    y=2;
    list=1;

    while (primos_por_mostrar > 0) {

        /* determinar si n es primo */
        es_primo = 1;
        for (d = 2; d < n; ++d) {
            if (n % d == 0) {
                es_primo = 0;
                break;
            }
        }

        /* mostrar el numero
         * y actualizar el contador */
        if (es_primo) {
           posicion(x,y++); printf("%i.- %d ",list++, n);
            primos_por_mostrar--;
        }
        n++;
    }


    printf("\n QUIERES REPETIR EL PROGRAMA??");
    printf("\n PRESIONA 1 +_*");
    z=getche();
    system("cls");

}while(z=49);
}


