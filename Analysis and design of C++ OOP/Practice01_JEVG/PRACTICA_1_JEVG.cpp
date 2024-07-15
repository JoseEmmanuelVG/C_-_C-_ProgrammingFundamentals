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
int a,x,y,z,w,error;
char p_real[]={'1','3','5','7','X'},p_mostrado[]={'-','-','-','-'};
posicion(60,10);cout<<"NOTAS:";
posicion(55,11);cout<<"Al tocarte un valor X, tus intentos se reducen AUTOMATICAMENTE";
posicion(55,12);cout<<"Solo te pueden salir 3 X";
posicion(55,13);cout<<"Si te sale una X, pon un numero cualquiera y enter para avanzar";
posicion(55,14);cout<<"Y enter para avanzar";

do
{
char p_real[]={'1','3','5','7','X'},p_mostrado[]={'-','-','-','-'}; // tuve que meter de nuevo las cadenas
color_aleatorio();                                                  //poque si no no funcionaba bien el ciclo
error=3;
    do
    {
    srand(time(NULL));
    x=0+(rand()%5);
    posicion(1,1);cout<<"IPN";posicion(100,1);cout<<"UPIITA";
    posicion(40,2);cout<<"BIENVENIDO, HORA DE JUGAR";
    posicion(25,5);cout<<"PRECIO DESCONOCIDO :"<<"\t ___"<<"\t ___"<<"\t ___"<<"\t ___";
    posicion(25,6);cout<<"PRECIO DESCONOCIDO :"<<"\t|_"<<p_mostrado[0]<<"_|" <<"\t|_"<<p_mostrado[1]<<"_|" <<"\t|_"<<p_mostrado[2]<<"_|" <<"\t|_"<<p_mostrado[3]<<"_|";
    posicion(35,7);cout<<"Casilla \t  0\t  1\t  2\t  3";
    posicion(25,9);cout<<"ERRORES PERMITIDOS : \t "<<error;
    posicion(5,11);cout<<"Tu valor es:   "<<p_real[x];
    posicion(5,12);cout<<"En que casilla te gustaria poner tu valor   ";cin>>y;cout<<"   ";

if(y<0 || y>4)
{
posicion(11,14);cout<<"ERROR, El intervalo de casillas es de 0-3";
p_mostrado[y]=p_real[x];
}
else
{
     if(x==y)
    {
    //w=y-a;
    //x=0+(rand()%w);
    posicion(11,14);cout<<"Correcto ya te puedes";printf("%c",34);cout<<" olvidar ";printf("%c",34);cout<<"del   "<<p_real[x]<<" ";
    p_mostrado[y]=p_real[x];
    //while(y=='1' || y=='5' || y=='7' || y=='X') // TRATE DE HACER QUE NO SE REPITIERA NINGUN NUMERO, PERO AL ENTRAR EN "X" SE REPETIAN
    //{
        //if(y=='1'){char p_real[]={'3','5','7','X'};if(y=='3'){char p_real[]={'5','7','X'};if(y=='5'){char p_real[]={'7','X'};
        //x=0+(rand()%4);}x=0+(rand()%3);}x=0+(rand()%2);}
        //else if(y=='3'){char p_real[]={'1','5','7','X'};if(y=='1'){char p_real[]={'5','7','X'};if(y=='5'){char p_real[]={'7','X'};
        //x=0+(rand()%4);}x=0+(rand()%3);}x=0+(rand()%2);}
        //else if(y=='5'){char p_real[]={'1','3','7','X'};if(y=='1'){char p_real[]={'3','7','X'};if(y=='3'){char p_real[]={'7','X'};
        //x=0+(rand()%4);}x=0+(rand()%3);}x=0+(rand()%2);}
        //else if(y=='7'){char p_real[]={'1','3','5','X'};if(y=='1'){char p_real[]={'3','5','X'};if(y=='3'){char p_real[]={'5','X'};
        //x=0+(rand()%4);}x=0+(rand()%3);}x=0+(rand()%2);}
        //else if(y=='X'){goto MenosX;}
    //}
    }
    else{posicion(11,14);cout<<"Incorrecto, sigue intentandolo              ";}//Deje tantos espacios para que no se amontonara con el mensaje de correcto -_-
    MenosX:
    if(p_real[x]=='X')
    {
    error--;
    posicion(25,9);cout<<"ERRORES PERMITIDOS : \t "<<error;
    }
    if(x==y && p_real[0]==p_mostrado[0] && p_real[1]==p_mostrado[1] && p_real[2]==p_mostrado[2] && p_real[3]==p_mostrado[3])
    {
     posicion(45,20);cout<<"HAS GANADO, FELICIDADES";
     contador_descendente();
     goto END;
    }
}
    }while(error>=1);
system("cls");
posicion(20,1);cout<<"LO SIENTO, SE TE TERMINARON LOS INTENTOS\n\n\n";
END:
cout<<"\n\n QUIERES REPETIR EL PROGRAMA??\n"<<("\n PRESIONA 1 +_* \n");
cout<<"\n\n NO QUIERES REPETIR EL PROGRAMA??\n"<<("\n PRESIONA CUALQUIER TECLA \n");
z=getch();
system("cls");
}while(z==49);
cout<<"\n\n FIN DEL PROGRAMA -_- \n GRACIAS POR TU TIEMPO";
system("pause>null");
}

int contador_descendente()
{
for(int x=9;x>=0;x--)
{
    posicion(50,22);cout<<"FINALIZANDO EN:";
    posicion(56,23);printf("%i",x);
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

