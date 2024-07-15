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

int color_aleatorio();
int volumen_torre();
int flotador_estatico();
int flotador_aprox();
float h,vt,v1=0,v2=0,r=12.5,R=23,vt;

 int main()
{
    while(1)
    {
    flotador_estatico();
    color_aleatorio();
posicion(0,0);printf("IPN");posicion(50,2);printf("BIENVENIDO");posicion(100,0);printf("UPIITA");
posicion(20,4);printf("PROGRAMA QUE CALCULA EL VOLUMEN DE AGUA QUE SE ENCUENTRA EN UNA TORRE");
posicion(25,5);printf("SOLO NECESITO SABER A QUE ALTURA SE ENCUENTRA EN FLOTADOR ");
posicion(19,6);printf("NOTA:TOMAR LAS ALTURAS M%cXIMAS Y M%cNIMAS COMO SE MUESTRA EN EL DIAGRAMA",181,214,181);
posicion(2,8);printf("Ingresa la altura del flotador:");
scanf("%f",&h);
volumen_torre();
    }
}

int volumen_torre()
{
    int z,x;
double pi=3.14159265358979323846;
color_aleatorio();
system("cls");
posicion(40,3);printf("EL VOLUMEN DE AGUA EN m^3 LA TORE ES:");
//Tome en cuenta que la altura maxima para calcular el volumen el cilindro era 19
//Y la minima para calcular el del cono era mas de 19, entonces resulto asi el programa
//Espero asi este bien profesor -__-
if (h>19)
{
v1=(19*pi*(r*r));
v2=(((h-19)*pi)/3)*((R*R)+(r*r)+(R*r));
}
else
{
v1=(h*pi*(r*r));
v2=0;
}
posicion(10,5);printf("Volumen cil%cndrico = %f m^3",161,v1);     posicion(70,5);printf("Volumen c%cnico truncado %f m^3",162,v2);
vt=v1+v2;
posicion(40,7);printf("VOLUMEN TOTAL = %f m^3",vt);
flotador_aprox();

posicion(20,22);printf("DESEAS REGRESAR AL INICIO PRESIONA 1; QUIERES FINALIZAR EL PROGRAMA PRESIONA 2 \n",233);
scanf("%i",&x);
if (x==1)
{
for(z=5;z>0;z--)
    {
     posicion(45,24);printf("REGRESANDO AL MEN%c EN:  %d",233,z);
     Sleep(1000);
    }
 system("cls");
return;
}
else
{
system("pause>null");exit(0);;
}
}


int flotador_aprox()
{
posicion(45,10);printf("____________________");posicion(45,9);printf("|        %c46       |",157);
posicion(45,11);printf("%c",92);posicion(46,12);printf("%c",92);posicion(47,13);printf("%c",92);
posicion(64,11);printf("/");posicion(63,12);printf("/");posicion(62,13);printf("/");
posicion(48,14);printf("|");posicion(48,15);printf("|");posicion(48,16);printf("|");posicion(48,17);printf("|");posicion(48,18);printf("|");
posicion(61,14);printf("|");posicion(61,15);printf("|");posicion(61,16);printf("|");posicion(61,17);printf("|");posicion(61,18);printf("|");
posicion(49,18);printf("____________"); posicion(48,20);printf("|     %c25    |",157);
posicion(55,11);printf("|");posicion(55,13);printf("|");posicion(55,15);printf("|");posicion(55,17);printf("|");posicion(55,19);printf("%c",124);
posicion(42,10);printf("__"); posicion(42,12);printf("14m");posicion(42,13);printf("__"); posicion(42,16);printf("19m");  posicion(42,18);printf("__");
posicion(50,19-(h/3.75));printf("_____%c____",219);
}


int flotador_estatico()
{
posicion(45,10);printf("____________________");posicion(45,9);printf("|        %c46       |",157);
posicion(45,11);printf("%c",92);posicion(46,12);printf("%c",92);posicion(47,13);printf("%c",92);
posicion(64,11);printf("/");posicion(63,12);printf("/");posicion(62,13);printf("/");
posicion(48,14);printf("|");posicion(48,15);printf("|");posicion(48,16);printf("|");posicion(48,17);printf("|");posicion(48,18);printf("|");
posicion(61,14);printf("|");posicion(61,15);printf("|");posicion(61,16);printf("|");posicion(61,17);printf("|");posicion(61,18);printf("|");
posicion(49,18);printf("____________"); posicion(48,20);printf("|     %c25    |",157);
posicion(55,11);printf("|");posicion(55,13);printf("|");posicion(55,15);printf("|");posicion(55,17);printf("|");posicion(55,19);printf("%c",124);
posicion(42,10);printf("__"); posicion(42,12);printf("14m");posicion(42,13);printf("__"); posicion(42,16);printf("19m");  posicion(42,18);printf("__");
posicion(48,12);printf("_______%c______",219);posicion(58,13);printf("|");posicion(58,16);printf("h");posicion(58,18);printf("|");
posicion(66,19);printf("hmin = 0m");posicion(66,10);printf("hmax = 33m");
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

