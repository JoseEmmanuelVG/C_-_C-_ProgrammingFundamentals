#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <iostream>
# include <string.h>

using namespace std;
int color_aleatorio();
int contador_descendente();
int x=115, cont=0, z, y;
struct libreria {
		char obra[20], autor[50];
		float precio, descuento;
        } ;
void posicion(int a, int b)
{
    COORD coord;
    coord.X=a;
    coord.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void menu()
{
posicion(40,1);cout<<"Administrador de libreria virtual";
posicion(5,3);cout<<"1) Registrar una obra";
posicion(5,5);cout<<"2) Ver registros";
posicion(5,7);cout<<"3) Salir\n";
y=getch();
}
int main( )
{
libreria d1[5];
do
{
color_aleatorio();
menu();
if (y==49){goto registro;}
else if(y==50){goto observarreg;}
while(x==115 && cont<20)
{
registro:
system("cls");
fflush(stdin);
posicion(40,1);cout<<"\n registro #"<<cont+1<<" \n";
cout<<"\n Ingresa Nombre de la obra \t"; gets(d1[cont].obra);
cout<<"\n Ingresa el Autor de la obra \t"; gets(d1[cont].autor);
cout<<"\n Ingresa Precio de la obra \t"; cin>>d1[cont].precio; fflush(stdin);
cout<<"\n Ingresa Descuento de la obra en %100 \t"; cin>>d1[cont].descuento; fflush(stdin);
cout<<"\n\nSi quieres agregar algo mas presiona s";fflush(stdin);
x=getch();
cont++;
if(cont==20)
    {cout<<"\n Se terminaron los espacios, estos son tus libros guardados:";}
}
observarreg:
system("cls");
cout<<"\n Registros almacenados: \n";
posicion(3,5);cout<<"Obra : \t";
posicion(23,5);cout<<"Autor : \t";
posicion(33,5);cout<<"Precio con dewscuento : \t";
for(x=0;x<cont; x++)
{
posicion(3,7);printf("%s",d1[x].obra);
posicion(23,7);printf("%s",d1[x].autor);
posicion(33,7);printf("%f",(d1[x].precio-(d1[x].precio*d1[x].descuento*.01)));
}
contador_descendente();
}while(y!=51);
END:
exit(0);
}
int contador_descendente()
{
for(int x=9;x>=0;x--)
{
    posicion(35,8);cout<<"Regresando al menu";
    posicion(45,9);cout<<"Tempo de espera:";
    posicion(53,10);printf("%i",x);
    Sleep(1000);
}
system("cls");
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
