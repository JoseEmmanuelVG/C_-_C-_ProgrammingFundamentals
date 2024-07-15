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
int area_rectangulo();
int perimetro_area_circulo();
int angulos_triangulo();


 int main()
{
int op;
while(1){
color_aleatorio();
printf("IPN");posicion(50,2);printf("BIENVENIDO");posicion(100,1);printf("UPIITA");
posicion(40,3);printf("Indica la operaci%cn que desees",162);
posicion(2,5);printf("MEN%c DE OPERACIONES:\n\n",233);

printf("1.-\t %crea de un Rect%cngulo  \n",181,160);
printf("2.-\t Per%cmetro y %crea de un circulo \n",161,160);
printf("3.-\t %cngulos de un triangulo \n",181);
printf("4.-\t Salir \n");
scanf("%d",&op);

switch(op)
{
case 1: area_rectangulo();
break;
case 2: perimetro_area_circulo();
break;
case 3: angulos_triangulo();
break;
case 4: system("pause>null");exit(0);;
break;
default:
    posicion(50,10);printf("Opcion no valida!! \t Intenta de nuevo.");
}
}
}

int area_rectangulo()
{
 int a,b,x,z;
 color_aleatorio();
 system("cls");

 posicion(45,2);printf("CALCULO DE %cREA DE UN RECT%cNGULO",181,181);
 posicion(2,4);printf("Ingresa la medida de los lados ");
 posicion(2,6);printf("Lados iguales-paralelos a:");
 scanf("%d",&a);
 posicion(2,8);printf("Lados iguales-paralelos b:");
 scanf("%d",&b);
 x=a*b;
 posicion(50,11);printf("%cREA DEL RECT%cNGULO =",181);
 posicion(50,13);printf("%du^2\n\n",x);

 for(z=5;z>0;z--)
    {
     posicion(47,15);printf("REGRESANDO AL MENU EN:  %d",z);
     Sleep(1500);
    }
 system("cls");
return;
}

int perimetro_area_circulo()
{
 int z;
 float a,p,r;
 double pi=3.14159265358979323846;
 color_aleatorio();
 system("cls");

 posicion(45,2);printf("CALCULO DE PER%cMETRO Y %cREA DE CIRCULO",140,181);
 posicion(2,4);printf("Ingresa la medida del radio ");
 scanf("%f",&r);
 a=(pi*r)*(pi*r);
 p=pi*(r*2);
 posicion(30,6);printf("EL %cREA DEL CIRCULO ES  =",181);     posicion(60,6);printf("EL PER%cMETRO DEL CIRCULO ES  =",181);
 posicion(30,8);printf("%fu^2\n\n",a);                        posicion(60,8);printf("%fu\n\n",p);


 for(z=5;z>0;z--)
    {
     posicion(47,15);printf("REGRESANDO AL MENU EN:  %d",z);
     Sleep(1500);
    }
 system("cls");
return;
}

int angulos_triangulo()
{
 int z;
 float A,B,C,A2,B2,C2,div1,div2,div3,Div1,Div2,Div3;
 double pi=3.14159265358979323846;
 color_aleatorio();
 system("cls");

 posicion(45,2);printf("%cNGULOS DE UN TRIANGULO",181);
 posicion(60,6);printf("|");posicion(60,7);printf("|");posicion(60,8);printf("|");posicion(60,9);printf("|");posicion(60,10);printf("|");  //LADO A
 posicion(56,10);printf("____");                                                                                                           //LADO B
 posicion(55,10);printf("/");posicion(56,9);printf("/");posicion(57,8);printf("/");posicion(58,7);printf("/");posicion(59,6);printf("/");  //LADO C
 posicion(54,11);printf("a");posicion(60,5);printf("b");posicion(61,11);printf("c");
 posicion(57,11);printf("B"); posicion(61,8);printf("A");posicion(56,8);printf("C");
 posicion(2,4);printf("Ingresa las medidas de los lados ");
 posicion(2,6);printf("Medida del lado A:");
 scanf("%f",&A);
 posicion(2,8);printf("Medida del lado B:");
 scanf("%f",&B);
 posicion(2,10);printf("Medida del lado C:");
 scanf("%f",&C);
 // LEY DE COSENOS: a=acos(((B*B)+(C*C)-(A*A))/(2*B*C));   b=acos(((A*A)+(C*C)-(B*B))/(2*A*C));  c=acos(((A*A)+(B*B)-(C*C))/(2*A*B)
 //PARA EVITAR ERORES DECIDI HACER LAS OPERACIONES POR PASOS
 A2=A*A;         B2=B*B;         C2=C*C;        //ELEVANDO AL CUADRADO LOS TERMINOS
 Div1=B2+C2-A2;  Div2=A2+C2-B2;  Div3=A2+B2-C2; //SUMA DE LOS DIVISORES
 div1=2*B*C;     div2=2*A*C;     div3=2*A*B;    //SUMA DE LOS DIVIDENDOS
 float a=Div1 / div1;
 float b=Div2 / div2;   //SE HACE LA DIVISION FLOTANTE PARA TOMAR TODOS LOS DECIMALES POSIBLES
 float c=Div3 / div3;
 posicion(30,13);printf("EL %cNGULO a =",181);              posicion(50,13);printf("EL %cNGULO b =",181);              posicion(70,13);printf("EL %cNGULO c =",181);
 posicion(30,15);printf("%f%c \n\n",(acos(a)*180)/pi,248);  posicion(50,15);printf("%f%c \n\n",(acos(b)*180)/pi,248);  posicion(70,15);printf("%f%c \n\n",(acos(c)*180)/pi,248);
 //LOS GRADOS RESULTANTES SON EN RADIANES POR LO QUE SE MULTIPLICA POR 180/PI PARA PASAR A GRADOS

 for(z=5;z>0;z--)
    {
     posicion(47,18);printf("REGRESANDO AL MENU EN:  %d",z);
     Sleep(1500);
    }
 system("cls");
return;

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
