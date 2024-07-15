#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>

void posicion(int a, int b)
{
    COORD coord;
    coord.X=a;
    coord.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int matriz_aleatoria();
int color_aleatorio();

 main()
{
int z;
    do
    {
    color_aleatorio();
    matriz_aleatoria();
    printf("\n\n QUIERES REPETIR EL PROGRAMA??");
    printf("\n PRESIONA 1 +_*");
    z=getche();
    system("cls");
    }while(z==49);
 printf("\n\n FIN DEL PROGRAMA -_- \n GRACIAS POR TU TIEMPO");
}


int matriz_aleatoria()
{
int Matriz[5][8], R,C;
int op,x,nv,a,z;
    srand(time(NULL));
    printf("Tu matriz es la siguiente\n\n ");
    for( R=0 ; R < 5 ; R++ )
    {
        for( C=0 ; C < 8; C++)
        {
        printf("%i \t",Matriz[R][C]=25+rand()%51);
        }
    printf("\n\n ");
    }

printf("\n Te gustaria cambiar algun dato de tu matriz asignada???\n ");
printf("\n 1) Si me gustaria       2)No me gustaria\n ");
scanf("%d",&op);
if(op==1)
{
do
{
printf("\nQUE DATO TE GUSTARIA CAMBIAR?\n");
printf("\n\t Ingresa el valor del dato o datos a cambiar\t");
scanf("%d",&x);
printf("\n\t Ingresa el valor del nuevo dato o datos\t");
scanf("%d",&nv);

    printf("\n\nTu nueva matriz es la siguiente\n\n");

        for( R=0 ; R < 5 ; R++ )
        {
            for( C=0 ; C < 8; C++)
            {
            printf("%d \t",Matriz[R][C]);
                if (x==Matriz[5],R,C)
            {
                printf("%d \t",Matriz[R][C]=nv);

            }
        printf("\n\n ");
        }
}
    printf("SI QUIERES CONTINUAR CON TU MODIFICACION DE LA MATRIZ PRESIONA 5");
    scanf("%d",&a);
    system("cls");
}while(a==5);
}
else{printf("\nFIN DEL PROGRAMA");}
}

int color_aleatorio()
{
int c;
srand(time(NULL));
c=1+rand()%6;
    switch(c)
    {
    case 1:
        system("color 0F");
    break;
    case 2:
        system("color 1F");
    break;
    case 3:
        system("color 2F");
    break;
    case 4:
        system("color 3F");
    break;
    case 5:
        system("color 4F");
    break;
    default:
        system("color 5F");
    break;
    }

}
