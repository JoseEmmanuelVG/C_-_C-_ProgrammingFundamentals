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

int main()
{
	string usuario;
	string clave;
	int estatus=0,cant_intentos=0;

do{

	cout<<"usuario:";
	cin>>usuario;
	cout<<"clave";
	cin>>clave;
if (usuario!="david" && clave!="123")
{
cant_intentos++;
	cout<<"te equivocaste";
}
	else
	estatus=1;

}while (cant_intentos<2&&estatus==0);

if(estatus==1){
	cout<<"se abrio la caja fuerte";
}
else
{
cout<<"supero la cantidad de intentos, se procede a llamar a la policia ";
}

}
