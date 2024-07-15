#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <iostream>

using namespace std;
int x,z,y,val_1,valor,aux;
int color_aleatorio();
//int valores_ascendentes();
//int valores_descendentes();

void posicion(int a, int b)
{
    COORD coord;
    coord.X=a;
    coord.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
do
{
color_aleatorio();
srand(time(NULL));
posicion(50,0);cout<<"Arreglos aleatorios y ordenados";
cout<<"\n \n \n Cuantos numeros te gustaria que tuviese tu arreglo? \t";
cin>>x;
int arre [x];
system("cls");
posicion(35,2);cout<<" Tu arreglo aleatorio es el siguiente: \n \n";

    for(val_1=0; val_1 < x; val_1 ++)
    {
    arre[val_1]=50+rand()%51;
    cout<<"\t \t"<<arre[val_1];
    }

posicion(10,6);cout<<" ¿QUE ES LO QUE QUIERES HACER AHORA? \n";
cout<<" \n OPCION 1) Ordenar ascendentemente = Presiona 5 \n";
cout<<" \n OPCION 2) Ordenar descendentemente = Presiona cualquier tecla";
y=getch();
system("cls");
if(y==53)
{
    for(int w=0; w<x ;w++)
    {
        for(val_1=0; val_1 < x; val_1 ++)
        {
        if(arre[val_1]>arre[val_1+1])
        {
        aux=arre[val_1];
        arre[val_1]=arre[val_1+1];
        arre[val_1+1]=aux;
        }
        }
    }
posicion(35,2);cout<<"Los valores ordenados ascendentemente son: \n \n";
    for(val_1=0; val_1 < x; val_1 ++)
    {
    cout<<"\t \t"<<arre[val_1];
    }
}
     else if (y!=53)
{
     for(int w=0; w<x ;w++)
    {
        for(val_1=0; val_1 < x-1; val_1 ++)
        {
        if(arre[val_1]<arre[val_1+1])
        {
        aux=arre[val_1];
        arre[val_1]=arre[val_1+1];
        arre[val_1+1]=aux;
        }
        }
    }
posicion(35,2); cout<<"Los valores ordenados descendentemente son: \n \n";
    for(val_1=0; val_1 < x; val_1 ++)
    {
    cout<<"\t \t"<<arre[val_1];
    }
}




cout<<"\n\n QUIERES REPETIR EL PROGRAMA??\n"<<("\n PRESIONA 1 +_* \n");
cout<<"\n\n NO QUIERES REPETIR EL PROGRAMA??\n"<<("\n PRESIONA CUALQUIER TECLA \n");
z=getch();

    system("cls");
    }while(z==49);
 cout<<"\n\n FIN DEL PROGRAMA -_- \n GRACIAS POR TU TIEMPO";
 system("pause>null");
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

