#include <math.h>
#include <windows.h>
#include <time.h>
//#include <graphics.h>

void posicion(int a, int b)
{
    COORD coord;
    coord.X=a;
    coord.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void menu()
{
posicion(2,5);printf("MEN%c DE OPERACIONES:\n\n",233);
printf("1.-\t %crea de un Rect%cngulo  \n",181,160);
printf("2.-\t Per%cmetro y %crea de un circulo \n",161,160);
printf("3.-\t %cngulos de un triangulo \n",181);
printf("4.-\t Salir \n");
printf("OPCION ESCOJIDA:\n");
}

float area_rectangulo(float x,float y)
{
return (x*y);
}


float area_circulo(double x,float y)
{
return (x*(y*y));
}
float perimetro_circulo(double x,float y)
{
return (2*x*y);
}

// LEY DE COSENOS: a=acos(((B*B)+(C*C)-(A*A))/(2*B*C));   b=acos(((A*A)+(C*C)-(B*B))/(2*A*C));  c=acos(((A*A)+(B*B)-(C*C))/(2*A*B)
float angulo_a(float x,float y,float z)
{
return acos(((y*y)+(z*z)-(x*x))/(2*y*z));
}
float angulo_b(float x,float y,float z)
{
return acos(((x*x)+(z*z)-(y*y))/(2*x*z));
}
float angulo_c(float x,float y,float z)
{
return acos(((x*x)+(y*y)-(z*z))/(2*x*y));
}




int main()
{
    int op,z;
    float a,b,c,x,Ar,Per,r,A,B,C;
    double pi=3.14159265358979323846;

while (1)
{
   color_aleatorio();
   //int windows(50,500,"MENU_DE_FUNCIONES_CORRECCION_JEVG",300.300);
   //readimagefile("ipn.jpg",1,1,10,10);
   //readimagefile("upiita.jpg",100,1,10,10);
posicion(2,1);printf("IPN");posicion(50,2);printf("BIENVENIDO");posicion(100,1);printf("UPIITA");
posicion(40,3);printf("Indica la operaci%cn que desees",162);

menu();
scanf("%i",&op);
switch(op)
{
case 1:
    system("cls");
    color_aleatorio();
    posicion(45,2);printf("CALCULO DE %cREA DE UN RECT%cNGULO",181,181);
    posicion(60,5);printf("A"); posicion(60,11);printf("A");
    posicion(50,6);printf("____________________"); posicion(50,10);printf("____________________");
    posicion(49,7);printf("|");posicion(49,8);printf("|");posicion(49,9);printf("|");posicion(49,10);printf("|");
    posicion(70,7);printf("|");posicion(70,8);printf("|");posicion(70,9);printf("|");posicion(70,10);printf("|");
    posicion(47,8);printf("B"); posicion(72,8);printf("B");

 posicion(2,6);printf("Ingresa la medida de los lados ");
 posicion(2,8);printf("Lados iguales-paralelos A:");
 scanf("%f",&a);
 posicion(2,10);printf("Lados iguales-paralelos B:");
 scanf("%f",&b);
 x=area_rectangulo(a,b);
 posicion(50,13);printf("%cREA DEL RECT%cNGULO =",181);
 posicion(55,14);printf("%fu^2\n\n",x);
 for(z=5;z>0;z--)
    {
     posicion(47,17);printf("REGRESANDO AL MENU EN:  %d",z);
     Sleep(1500);
    }
 system("cls");
break;

case 2:
    system("cls");
    color_aleatorio();
    posicion(45,2);printf("CALCULO DE PER%cMETRO Y %cREA DE CIRCULO",140,181);

 posicion(2,4);printf("Ingresa la medida del radio ");
 scanf("%f",&r);
 Ar=area_circulo(pi,r);
 Per=perimetro_circulo(pi,r);
 posicion(30,6);printf("EL %cREA DEL CIRCULO ES  =",181);     posicion(60,6);printf("EL PER%cMETRO DEL CIRCULO ES  =",181);
 posicion(30,8);printf("%fu^2\n\n",Ar);                        posicion(60,8);printf("%fu\n\n",Per);

for(z=5;z>0;z--)
    {
     posicion(47,15);printf("REGRESANDO AL MENU EN:  %d",z);
     Sleep(1500);
    }
 system("cls");
break;

case 3:
     system("cls");
     color_aleatorio();
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
 a=angulo_a(A,B,C);
 b=angulo_b(A,B,C);
 c=angulo_c(A,B,C);
 posicion(30,13);printf("EL %cNGULO a =",181);              posicion(50,13);printf("EL %cNGULO b =",181);              posicion(70,13);printf("EL %cNGULO c =",181);
 posicion(30,15);printf("%f%c \n\n",(a*180)/pi,248);  posicion(50,15);printf("%f%c \n\n",(b*180)/pi,248);  posicion(70,15);printf("%f%c \n\n",(c*180)/pi,248);
for(z=5;z>0;z--)
    {
     posicion(47,17);printf("REGRESANDO AL MENU EN:  %d",z);
     Sleep(1500);
    }
 system("cls");
break;
case 4: system("pause>null");exit(0);;
break;
default:
    posicion(50,10);printf("Opcion no valida!! \t Intenta de nuevo.");
}

}
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
