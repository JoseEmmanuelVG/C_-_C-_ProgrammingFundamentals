#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <iostream>

using namespace std;
int color_aleatorio();
int contador_descendente();

void posicion(int a, int b)
{
    COORD coord;
    coord.X=a;
    coord.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
int x=0,n=4,y,z,intentos;
char password[50], ans[50];
strcpy(password,"IPN");
color_aleatorio();
do
{
posicion(30,0);cout<<"BIENVENIDO, COLOCA TU CONTRASEÑA PARA INICIAR SESION: ";
posicion(35,3);cout<<"Presiona enter para ocultar tu contraseña";
posicion(20,4);cout<<"Si no la quieres ocultar tendras que anotarla 2 veces para comprobacion";
posicion(50,5);cout<<"Contraseña: "; //gets(ans); strupr(ans);y=strcmp(password,ans); //Si los dejo sin comentar, funciona pero muestra la contraseña

//UNA DISCULPA,  NO SUPE COMO OCULTAR Y GUARDAR AL MISMO TIEMPO LA CONTRASEÑA, YA QUE SI LA GUARDABA NO LA OCULTAVA O VICEVERSA
//Es por ello que siempre va al else

posicion(50,6);
do
{
intentos++;
    do{
    ans[x]=getch();
        if(ans[x]>32 && x<50) //NO ACEPTA CARACTERES ESPECIALES Y TIENE COMO MAX 50
        {
        putchar('#');
        x++;
        }
        else if(ans[x]==8 && x>0) //CUANDO SE BORRA ALGO
        {
        putchar(8);
        putchar('#');
        putchar(8);
        x--;
        }
    }while(ans[x]!=13); //SIEMPRE Y CUANDO NO SE DE ENTER
//gets(ans);
strupr(ans);
y=strcmp(password,ans);

if (y==0){posicion(30,8); cout<<"Abriendo sesion}";}
else {
    n--;
    posicion(25,6);printf("Te quedan : %i intentos\t  ",n);
    }
 }while(intentos<4);

contador_descendente();
posicion(1,1); cout<<"SEGURO SABES LA CONTRASEÑA?";
cout<<"\n\n Quieres intentarlo de nuevo\n"<<("\n PRESIONA 1 +_* \n");
cout<<"\n\n No quieres intentarlo \n"<<("\n PRESIONA CUALQUIER TECLA \n");
z=getch();
    system("cls");
    }while(z==49);
}

int contador_descendente()
{
for(int x=9;x>=0;x--)
{
    posicion(35,8);cout<<"Realizaste el numero maximo de intentos";
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
