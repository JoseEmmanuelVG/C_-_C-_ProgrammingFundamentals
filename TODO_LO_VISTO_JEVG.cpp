#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <iostream>

//para el nivel final, escoji hacer un juego de serpiente que vaya aumentando la dificultad mientras comas y tenga un "tiempo" limite
#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75

using namespace std;
int color_aleatorio();
int contador_descendente();
int cont_desc_inicio();
int refran_aleatorio();
int frases_aleatorias();
int pais_capital();
int adivina_la_cancion();
int frases_celebres();
int nivel_final();
int mensaje_GANADOR();
int mensaje_PERDEDOR();
int x, y, esc, borrar=54, n_b, intentos, vida_extra;//n_b=nueva coordenada para borrar o sobreponer para quitar una vida

//para el nivel final
char tecla;
int serpiente[50][50];
int n=1,cont, puntos, conti, punto, aumento, pos_x_serpiente=20, pos_y_serpiente=15, pos_x_comida=30, pos_y_comida=15, longitud=10, direccion=3, velocidad = 24;
void OcultaCursor()
{
 CONSOLE_CURSOR_INFO cci = {100, FALSE};
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void posicion(int a, int b)
{
    COORD coord;
    coord.X=a;
    coord.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//funciones del ultimo nivel
void marco()
{
for(int X=20; X<100; X++){posicion(X,5); printf ("%c",205);posicion(X,25); printf ("%c",205);} //Borde "x"
for(int Y=6; Y<25; Y++){posicion(19,Y); printf("%c",186);posicion(100,Y); printf("%c",186);}   // Borde "y"
posicion(19,5);printf("%c",201); posicion(19,25);printf("%c",200); posicion(100,5);printf("%c",187); posicion(100,25);printf("%c",188); // Esquinas "x,y"
}
void upiita_ipn()
{
posicion(40,6);printf("  _   _   ___   ___   ___   _____     _   ");
posicion(40,7);printf(" | | | | | _ %c |_ _| |_ _| |_   _|   /_%c  ",92,92);
posicion(40,8);printf(" | |_| | |  _/  | |   | |    | |    / _ %c ",92);
posicion(40,9);printf("  %c___/  |_|   |___| |___|   |_|   /_/ %c_%c",92,92,92);
for(int X=40; X<82; X++){posicion(X,10); printf ("%c",205);} //base "x"
for(int Y=6; Y<10; Y++){posicion(40,Y); printf("%c",186);posicion(82,Y); printf("%c",186);} //bordes "y"
posicion(40,5); printf("%c",203);posicion(40,10); printf("%c",200);posicion(82,5); printf("%c",203);posicion(82,10); printf("%c",188);//esquinas

posicion(53,21);printf("  ___   ___   _  _ ");
posicion(53,22);printf(" |_ _| | _ %c | %c| |",92,92);
posicion(53,23);printf("  | |  |  _/ | .` |");
posicion(53,24);printf(" |___| |_|   |_|%c_|",92);
for(int X=54; X<72; X++){posicion(X,20); printf ("%c",205);} //base "x"
for(int Y=21; Y<25; Y++){posicion(53,Y); printf("%c",186);posicion(72,Y); printf("%c",186);} //bordes "y"
posicion(53,25); printf("%c",202);posicion(53,20); printf("%c",201);posicion(72,20); printf("%c",187);posicion(72,25); printf("%c",202);//esquinas

}
void rastro()
{
for(int X= 1; X<longitud; X++) {posicion(serpiente[X][0] , serpiente[X][1]); printf("#");}
}
void borrar_rastro()
{
posicion(serpiente[n][0],serpiente[n][1]);printf(" ");
 }
void guardar_posicion()
{
serpiente[n][0]=pos_x_serpiente; serpiente[n][1]=pos_y_serpiente;
n++;
if(n == longitud) n = 1;
}
 void comida()
{
 if(pos_x_serpiente==pos_x_comida && pos_y_serpiente==pos_y_comida)
 {
 pos_x_comida=20+(rand()%80);   pos_y_comida=6+(rand()%19);
 longitud++;
 posicion(pos_x_comida, pos_y_comida); printf("%c", 4);
 }
}
void teclas()
{
 if(kbhit())
 {
    tecla=getch();
    switch(tecla)
    {
    case ARRIBA : if(direccion!=2) direccion=1; break;
    case ABAJO : if(direccion!=1) direccion=2; break;
    case DERECHA : if(direccion!=4) direccion=3; break;
    case IZQUIERDA : if(direccion!=3) direccion=4; break;
    }
 }
}
bool perder()
{
 if(pos_y_serpiente==5 || pos_y_serpiente==25 || pos_x_serpiente==19 || pos_x_serpiente==100)return false;
 for(int X=longitud-1; X>0; X--)
 {
 if(serpiente[X][0]==pos_x_serpiente && serpiente[X][1]==pos_y_serpiente)
 return false;
 }
 return true;
}

//tuneo -_- jejeje
void inicio()
{
posicion(5,1);cout<<"IPN";posicion(105,1);cout<<"UPIITA";
posicion(40,3);cout<<"BIENVENIDO A ESTE NUEVO JUEGO DE NIVELES"; posicion(10,5);cout<<"REGLAS BASICAS : ";
posicion(10,7);cout<<"1) Cuentas con 3 vidas";posicion(10,9);cout<<"2) Podras aumentar tus vidas en 2 respectivos niveles";
posicion(10,11);cout<<"3) Perderas 1 vida cada vez que contestas mal una prueba";posicion(10,13);cout<<"4) Si pierdes tus vidas, se termina el juego";
posicion(10,15);cout<<"5) Las reglas de cada nivel, las tendras antes del mismo";
cont_desc_inicio();
}
void Nivel_1()
{
posicion(5,1);cout<<"IPN";posicion(105,1);cout<<"UPIITA";
posicion(30,3);cout<<"NIVEL 1 - COMPLETA LA PALABRA FALTANTE, CON OPCIONES"; posicion(10,5);cout<<"REGLAS ESPECIFICAS : ";
posicion(10,7);cout<<"1) Escribe la palabra que completa el refran donde se indica (observa las opciones, te pueden ayudar)";
posicion(10,9);cout<<"2) Si contestas bien a la primera, tendras una vida extra";
posicion(10,11);cout<<"3) Perderas 1 vida cada vez que contestas mal una prueba";
posicion(10,13);cout<<"4) Solo necesitas completar corectamente una vez el refran para pasar al siguiente nivel";
cont_desc_inicio();
}
void Nivel_2()
{
posicion(5,1);cout<<"IPN";posicion(105,1);cout<<"UPIITA";
posicion(30,3);cout<<"NIVEL 2 - COMPLETA LA PALABRA FALTANTE DE LA FRASE"; posicion(10,5);cout<<"REGLAS ESPECIFICAS : ";
posicion(10,7);cout<<"1) Escribe la palabra que completa la frase donde se indica (esta vez no cuentas con opciones)";
posicion(10,9);cout<<"2) Si contestas bien a la primera, tendras una vida extra";
posicion(10,11);cout<<"3) Perderas 1 vida cada vez que contestas mal una prueba";
posicion(10,13);cout<<"4) Solo necesitas completar corectamente una vez la frase para pasar al siguiente nivel";
cont_desc_inicio();
}
void Nivel_3()
{
posicion(5,1);cout<<"IPN";posicion(105,1);cout<<"UPIITA";
posicion(25,3);cout<<"NIVEL 3-4-5 << CAPITALEES, CANCIONES y FRASES.C >>"; posicion(10,5);cout<<"REGLAS ESPECIFICAS NIVEL 3,4 y 5: ";
posicion(10,7);cout<<"1) Escribe acertadamente a lo que se te solicite y donde se indica";
posicion(10,9);cout<<"2) Necesitas acertar a << 3 capitales - 2 canciones - 2 frases >> para pasar de nivel a nivel respectivamente";
posicion(10,11);cout<<"3) Perderas 1 vida cada vez que contestas mal una prueba";
posicion(15,15);cout<<"NOTA: Apartir de ahora ya no habra vidas extras, aun cuando contestes a la primera";
cont_desc_inicio();
}
void Conteo_de_vidas()
{
posicion(5,1);cout<<"IPN";posicion(105,1);cout<<"UPIITA";
posicion(5,2);printf("  ___  __  __   ___   ___   _      ___   _  _   _____   ___         _____   ___   ___   _  _   ___   ___");
posicion(5,3);printf(" | __| %c %c/ /  / __| | __| | |    | __| | %c| | |_   _| | __|       |_   _| |_ _| | __| | %c| | | __| / __|",92,92,92,92);
posicion(5,4);printf(" | _|   >  <  | (__  | _|  | |__  | _|  | .` |   | |   | _|   _      | |    | |  | _|  | .` | | _|  %c__ %c",92,92);
posicion(5,5);printf(" |___| /_/%c_%c  %c___| |___| |____| |___| |_|%c_|   |_|   |___| ( )     |_|   |___| |___| |_|%c_| |___| |___/",92,92,92,92,92);
posicion(40,8);cout<<"VIDAS";posicion(48,8);cout<<"\3 \3 \3 \3";posicion(borrar,8);cout<<"          ";
posicion(5,12);printf("   ___   ___   ___    ___  ");
posicion(5,13);printf("  | _ %c | __| | _ %c  / _ %c ",92,92,92);      posicion(40,13);cout<<"DESGRACIADAMENTE PARA EL ULTIMO NIVEL, SOLO CONTARAS CON UNA SOLA OPORTUNIDAD";
posicion(5,14);printf("  |  _/ | _|  |   / | (_) |");                  posicion(40,14);cout<<"NO HECHES A PERDER TODO TU ESFUERZO, HABER LLEGADO HASTA AQUI ES TODO UN LOGRO";
posicion(5,15);printf("  |_|   |___| |_|_%c  %c___/ ",92,92);
posicion(15,23);printf("   _____   _   _ ");  posicion(69,23);printf("   ___   _   _   ___   ___    ___   ___ ");
posicion(15,24);printf("  |_   _| | | | |");  posicion(69,24);printf("  | _ %c | | | | | __| |   %c  | __| / __|",92,92);
posicion(15,25);printf("    | |   | |_| | "); posicion(69,25);printf("  |  _/ | |_| | | _|  | |) | | _|  %c__ %c",92,92);
posicion(15,26);printf("    |_|    %c___/  ",92);  posicion(69,26);printf("  |_|    %c___/  |___| |___/  |___| |___/",92);
cont_desc_inicio();
}
void Nivel_6()
{
posicion(5,1);cout<<"IPN";posicion(105,1);cout<<"UPIITA";
posicion(40,2);cout<<"NIVEL FINAL - JUEGO DE LA SERPIENTE"; posicion(10,4);cout<<"REGLAS ESPECIFICAS : ";
posicion(10,6);cout<<"1) Los movimients de la serpiente son controlados por las flechas de tu teclado";
posicion(10,7);cout<<"(Flecha hacia arriba, la serpiente va hacia arriba, y asi con las demas)";
posicion(10,9);cout<<"2) El juego termina-ganas cuando comes 11 veces sin chocar con el borde y el contador no ha llegado a 0";
posicion(10,10);cout<<"NOTA: La velocidad de la serpiente ira aumentando conforme comas (mas y mas rapido cada que comas)";
posicion(10,12);cout<<"3) El juego termina-pierdes cuando golpeas una pared de cualquier extremo del borde de contencion";
posicion(10,13);cout<<"3.1) El juego termina-pierdes cuando el contador llega a 0 y no has comido 11 veces";
posicion(15,15);cout<<"NOTAS: NO TE CRUCES CON TU COLA. PORQUE PODRIAS MORIR Y EL JUEGO ACABAR -__- ¿DAR CLICK PARA PAUSA?";
posicion(10,16);cout<<"NO TE DISTRAIGAS, NO PIERDAS EL TIEMPO CON EL TEXTO DEL BORDE, LAS COSAS NO SIEMPRE SON LO QUE PARECEN";

cont_desc_inicio();
}


int main()
{
//int x, y, esc, borrar=54, n_b, intentos, vida_extra;//Las repeti para poder hacer uso del while principal y que no hubiera errores, pero si las dejo, dejan de funcionar las vidas
int z,w;
do
{
color_aleatorio();  //goto // NIVEL2; // NIVEL3; // NIVEL4; //NIVEL5; // NIVEL6; //Por si quiere probar algun nivel en especifico.
inicio();//NIVEL1:
color_aleatorio();Nivel_1();if(esc==27){goto END;}
refran_aleatorio();
if(borrar==48){contador_descendente();goto END;}
if(x==0){posicion(45,0);cout<<"AVANZAS AL NIVEL 2";}
if(intentos==2){vida_extra=1;borrar=56;}
else{borrar=n_b;}//NIVEL2:
color_aleatorio();Nivel_2();if(esc==27){goto END;}
frases_aleatorias();
if(borrar==48){contador_descendente();goto END;}
if(x==0){posicion(45,0);cout<<"AVANZAS AL NIVEL 3";}
if(intentos==2){vida_extra=1;borrar=n_b+2;}
else{borrar=n_b;}//NIVEL3:
color_aleatorio();Nivel_3();if(esc==27){goto END;}
pais_capital();
if(borrar==48){contador_descendente();goto END;}
if(x==0){posicion(45,0);cout<<"AVANZAS AL NIVEL 4";}
borrar=n_b;//NIVEL4:
color_aleatorio(); adivina_la_cancion();
if(borrar==48){contador_descendente();goto END;}
if(x==0){posicion(45,0);cout<<"AVANZAS AL NIVEL 5";}
borrar=n_b;//NIVEL5:
color_aleatorio();frases_celebres();borrar=n_b;
if(borrar==48){contador_descendente();goto END;}
if(x==0){posicion(45,0);cout<<"AVANZAS AL NIVEL FINAL";}//NIVEL6:
borrar=n_b;
Conteo_de_vidas(); Nivel_6(); nivel_final();
if(conti!=0 && punto==0)
{int G=0;
while (G!=5)
    {G++;
    color_aleatorio();mensaje_GANADOR();
    Sleep(1000);
    }
color_aleatorio();mensaje_GANADOR();
goto END;
}
else if(cont==0 || punto!=0)
{int P=0;
while (P!=5)
    {P++;
    color_aleatorio();mensaje_PERDEDOR();
    Sleep(1000);
    }
color_aleatorio();mensaje_PERDEDOR();
goto END;
}
END:
posicion(45,20);cout<<" Quieres intentarlo de nuevo\n";posicion(45,21);cout<<(" PRESIONA 1 +_* \n");
posicion(45,24);cout<<" No quieres intentarlo \n";posicion(45,25);cout<<(" PRESIONA CUALQUIER TECLA \n");
z=getch();
    system("cls");
    }while(z==49);
}

int refran_aleatorio() //NIVEL 1
{
int refran,a=30,b=3;
char palabra[50],respuesta[50];
intentos=1;
srand(time(NULL));

do
{
n_b=borrar;
int al, var, nums[10],y=1,i;
posicion(5,0);cout<<"IPN";posicion(105,0);cout<<"UPIITA";
posicion(30,1);cout<<"NIVEL 1 - ADIVINA LA PALABRA FALTANTE DEL REFRAN (CON OPCIONES)";
refran=1+rand()%10;
do{
    var=1;
    while(var>0)
    {
        var=0;
        for(i=0;i<y;i++)
        {
        if(refran==nums[i])
            {
            var++;
            refran=1+rand()%10;
            }
        }
    }
     nums[y-1]=refran;
       y++;
}while(y<=10);
    switch(refran)
    {
    case 1:
    strcpy(palabra,"BIEN");
    posicion(a,b);cout<<"No hay mal que por ##### no venga\n\n";//bien
    cout<<"\tOpciones : "<<"\n\n1)BUENA \n\n2)BIEN \n\n3)DELANTE\n\n\n";
    break;

    case 2:
    strcpy(palabra,"APRENDE");
    posicion(a,b);cout<<"Quien duerme mucho, poco #####.\n\n";//aprende
    cout<<"\tOpciones : "<<"\n\n1)ENSE";printf("\%cA",165); cout<<"\n\n2)GANA \n\n3)APRENDE\n\n\n";
    break;

    case 3:
       strcpy(palabra,"PALO");
    posicion(a,b);cout<<"De tal #### tal astilla.\n\n";//palo
    cout<<"\tOpciones : "<<"\n\n1)MADERA \n\n2)PALO \n\n3)ASTILLA\n\n\n";
    break;

    case 4:
    strcpy(palabra,"HERRERO");
    posicion(a,b);cout<<"En casa de ######, azad";printf("\%cn",162);cout<<" de palo.\n\n";//herrero
    cout<<"\tOpciones : "<<"\n\n1)HERRERO \n\n2)CARPINTERO \n\n3)PINTOR\n\n\n";
    break;

    case 5:
    strcpy(palabra,"TAZAS");
    posicion(a,b);cout<<"Al que no quiere caldo se le dan dos #####.\n\n";//tazas
    cout<<"\tOpciones : "<<"\n\n1)VASO \n\n2)PLATOS \n\n3)TAZAS\n\n\n";
    break;

    case 6:
    strcpy(palabra,"VER");
    posicion(a,b);cout<<"No hay peor ciego que el que no quiere ####.\n\n";//ver
    cout<<"\tOpciones : "<<"\n\n1)ESCUCHAR \n\n2)VER \n\n3)SEGUIR\n\n\n";
    break;

    case 7:
    strcpy(palabra,"VER");
    posicion(a,b);cout<<"No hay peor ciego que el que no quiere ####.\n\n";//ver
    cout<<"\tOpciones : "<<"\n\n1)ESCUCHAR \n\n2)VER \n\n3)SEGUIR\n\n\n";
    break;

    case 8:
    strcpy(palabra,"VUELA");
    posicion(a,b);cout<<"El que no corre, ########.\n\n";//vuela
    cout<<"\tOpciones : "<<"\n\n1)SALTA \n\n2)CAMINA \n\n3)VUELA\n\n\n";
    break;

    case 9:
    strcpy(palabra,"CIEN");
    posicion(a,b);cout<<"No hay mal que dure ##### a";printf("\%cos",164);cout<<" ni cuerpo que lo resista.\n\n";//CIEN
    cout<<"\tOpciones : "<<"\n\n1)CIEN \n\n2)MIL \n\n3)DIEZ\n\n\n";
    break;

    default:
     strcpy(palabra,"MALA");
    posicion(a,b);cout<<"Hierba ###### nunca muere.\n\n";//MALA
    cout<<"\tOpciones : "<<"\n\n1)SANTA \n\n2)MALA \n\n3)BUENA\n\n\n";
    break;
    }
posicion(40,8);cout<<"VIDAS";
posicion(48,8);cout<<"\3 \3 \3 \3";posicion(borrar,8);cout<<"          ";
posicion(0,13);cout<<"\tEscribe tu respuesta : ";gets(respuesta);
strupr(respuesta);
x=strcmp(palabra,respuesta);
if(x!=0){borrar=n_b-2;cout<<"\n ERROR HAS PERDIDO UNA VIDA";}
Sleep(1000);
intentos++;
system("cls");
}while(x!=0&&borrar!=48);
}

int frases_aleatorias()
{
int frase,a=0,b=3;
char palabra[50],respuesta[50];
intentos=1;
srand(time(NULL));

do
{
n_b=borrar;
int al, var, nums[10],y=1,i;
posicion(5,0);cout<<"IPN";posicion(105,0);cout<<"UPIITA";
posicion(30,1);cout<<"NIVEL 2 - ADIVINA LA PALABRA FALTANTE DE LA FRASE";
frase=1+rand()%10;
do{
    var=1;
    while(var>0)
    {
        var=0;
        for(i=0;i<y;i++)
        {
        if(frase==nums[i])
            {
            var++;
            frase=1+rand()%10;
            }
        }
    }
     nums[y-1]=frase;
       y++;
}while(y<=10);
    switch(frase)
    {
    case 1:
    strcpy(palabra,"ATRAS");
    posicion(a,b);cout<<"No hay que ir para ##### ni para darse impulso.\n\n";//atrás
    break;

    case 2:
    strcpy(palabra,"CAMINO");
    posicion(a,b);cout<<"No hay caminos para la paz; la paz es el ######.\n\n";//camino
    break;

    case 3:
       strcpy(palabra,"GUERRA");
    posicion(a,b);cout<<"Haz el amor y no la #######.\n\n";//guerra
    break;

    case 4:
    strcpy(palabra,"VIVIR");
    posicion(a,b);cout<<"Aprende a ##### y sabr";printf("\%cs",160);cout<<" morir bien.\n\n";//vivir
    break;

    case 5:
    strcpy(palabra,"SABEMOS");
    posicion(a,b);cout<<"Cada día ###### m";printf("\%cs",160);cout<<" y entendemos menos.\n\n";//sabemos
    break;

    case 6:
    strcpy(palabra,"AMAR");
    posicion(a,b);cout<<"La medida del amor es #### sin medida.\n\n";//amar
    break;

    case 7:
    strcpy(palabra,"CAMBIAR");
    posicion(a,b);cout<<"La educaci";printf("\%cn",162);cout<<" es el arma m";printf("\%cs",160);cout<<" poderosa para ##### el mundo\n\n";//cambiar
    break;

    case 8:
    strcpy(palabra,"VUELA");
    posicion(a,b);cout<<"El que no corre, ########.\n\n";//vuela
    break;

    case 9:
    strcpy(palabra,"VIVIENDOLA");
    posicion(a,b);cout<<"Pasamos mucho tiempo gan";printf("\%cndonos",160);cout<<" la vida, pero no el suficiente tiempo #######.\n\n";//viviendola
    break;

    default:
     strcpy(palabra,"MATA");
    posicion(a,b);cout<<"Lo que no te #####, te hace m";printf("\%cs",160);cout<<" fuerte.\n\n";//mata
    break;
    }
posicion(40,6);cout<<"VIDAS";
posicion(48,6);cout<<"\3 \3 \3 \3";posicion(borrar,6);cout<<"       ";
posicion(0,9);cout<<"Escribe tu respuesta : ";gets(respuesta);
strupr(respuesta);
x=strcmp(palabra,respuesta);
if(x!=0){borrar=n_b-2;cout<<"\n ERROR HAS PERDIDO UNA VIDA";}
Sleep(1000);
intentos++;
system("cls");
}while(x!=0&&borrar!=48);
}

int pais_capital()
{
int paises,a=1,b=3,ans_bien=0,cont=2;
char capital[50],respuesta[50];
intentos=1;
srand(time(NULL));

do
{
n_b=borrar;
int al, var, nums[15],y=1,i;
posicion(5,0);cout<<"IPN";posicion(105,0);cout<<"UPIITA";
posicion(30,1);cout<<"NIVEL 3 - ACIERTA LA CAPITAL";
paises=1+rand()%15;
do{
    var=1;
    while(var>0)
    {
        var=0;
        for(i=0;i<y;i++)
        {
        if(paises==nums[i])
            {
            var++;
            paises=1+rand()%15;
            }
        }
    }
     nums[y-1]=paises;
       y++;
}while(y<=15);
    switch(paises)
    {
    case 1:
    strcpy(capital,"BERLIN"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->ALEMANIA<---\n\n";
    break;

    case 2:
    strcpy(capital,"BUENOS AIRES"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->ARGENTINA<---\n\n";
    break;

    case 3:
    strcpy(capital,"BRASILIA"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->BRASIL<---\n\n";
    break;

    case 4:
    strcpy(capital,"PEKIN"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->CHINA<---\n\n";
    break;

    case 5:
    strcpy(capital,"WASHINGTON"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->ESTADOS UNIDOS<---\n\n";
    break;

    case 6:
    strcpy(capital,"PARIS"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->FRANCIA<---\n\n";
    break;

    case 7:
    strcpy(capital,"ROMA"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->ITALIA<---\n\n";
    break;

    case 8:
    strcpy(capital,"JERUSALEN"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->ISRAEL<---\n\n";
    break;

    case 9:
    strcpy(capital,"TOKIO"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->JAPON<---\n\n";
    break;

    case 10:
    strcpy(capital,"CIUDAD DE MEXICO"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->MEXICO<---\n\n";
    break;

    case 11:
    strcpy(capital,"MOSCU"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->RUSIA<---\n\n";
    break;

    case 12:
    strcpy(capital,"LONDRES"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->INGLATERRRA<---\n\n";
    break;

    case 13:
    strcpy(capital,"MADRID"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->ESPAÑA<---\n\n";
    break;

    case 14:
    strcpy(capital,"OTTAWA"); posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->CANADA<---\n\n";
    break;

    default:
    strcpy(capital,"LISBOA");posicion(a,b);cout<<"Menciona la capital del siguiente pais: \n\n\t  --->PORTUGAL<---\n\n";
    break;
    }
posicion(40,6);cout<<"VIDAS";
posicion(48,6);cout<<"\3 \3 \3 \3 \3";posicion(borrar,6);cout<<"       ";
posicion(1,9);cout<<"Escribe tu respuesta : ";gets(respuesta);
strupr(respuesta);
x=strcmp(capital,respuesta);
intentos++;
if(x==0){cout<<"\n EXCELENTE TE QUEDAN ";printf("%i",cont);cout<<" CAPITALES CORRECTAS PARA PASAR AL SIGUIENTE NIVEL";ans_bien++;cont--;}
Sleep(2000);
if(x!=0){borrar=n_b-2;cout<<"\n ERROR HAS PERDIDO UNA VIDA";}
Sleep(1000);
system("cls");
}while(ans_bien!=3&&borrar!=48);
}

int adivina_la_cancion()
{
int canciones,a=1,b=3,ans_bien=0,cont=1;
char interprete[50],cancion[50],respuesta_i[50],respuesta_c[50];//para comparar tanto las respuestas de interprete como las de cancion ||
intentos=1;
srand(time(NULL));

do
{
n_b=borrar;
int al, var, nums[10],y=1,i;
posicion(5,0);cout<<"IPN";posicion(105,0);cout<<"UPIITA";
posicion(40,1);cout<<"NIVEL 4 - ADIVINA LA CANCI";printf("%cN",224);
canciones=1+rand()%10;
do{
    var=1;
    while(var>0)
    {
        var=0;
        for(i=0;i<y;i++)
        {
        if(canciones==nums[i])
            {
            var++;
            canciones=1+rand()%10;
            }
        }
    }
     nums[y-1]=canciones;
       y++;
}while(y<=10);
    switch(canciones) // escoji las canciones mas famosas segun un video de youtube, espero no este tan facil profe jejeje
    {
    case 1:
    strcpy(interprete,"MAROON 5");strcpy(cancion,"SUGAR");
    posicion(a,b);cout<<"Menciona el interprete o el nombre de la cancion que esta sonando en este momento:  ";
    PlaySound(TEXT("Maroon 5 - Sugar.wav"),NULL,SND_ASYNC);
    break;

    case 2:
    strcpy(interprete,"BRUNO MARS");strcpy(cancion,"UPTOWN FUNK");
    posicion(a,b);cout<<"Menciona el interprete o el nombre de la cancion que esta sonando en este momento:  ";
     PlaySound(TEXT("Bruno Mars - Uptown Funk.wav"),NULL,SND_ASYNC);
    break;

    case 3:
    strcpy(interprete,"ED SHEERAN");strcpy(cancion,"SHAPE OF YOU");
    posicion(a,b);cout<<"Menciona el interprete o el nombre de la cancion que esta sonando en este momento:  ";
    PlaySound(TEXT("Ed Sheeran - Shape of You"),NULL,SND_ASYNC);
    break;

    case 4:
    strcpy(interprete,"ENRIQUE IGLESIAS");strcpy(cancion,"BAILANDO");
    posicion(a,b);cout<<"Menciona el interprete o el nombre de la cancion que esta sonando en este momento:  ";
    PlaySound(TEXT("Enrique Iglesias - Bailando"),NULL,SND_ASYNC);
    break;

    case 5:
    strcpy(interprete,"JUSTIN BIEBER");strcpy(cancion,"SORRY");
    posicion(a,b);cout<<"Menciona el interprete o el nombre de la cancion que esta sonando en este momento:  ";
    PlaySound(TEXT("Justin Bieber - Sorry"),NULL,SND_ASYNC);
    break;

    case 6:
    strcpy(interprete,"KATY PERRY");strcpy(cancion,"ROAR");
    posicion(a,b);cout<<"Menciona el interprete o el nombre de la cancion que esta sonando en este momento:  ";
    PlaySound(TEXT("Katy Perry - Roar.wav"),NULL,SND_SYNC);
    break;

    case 7:
    strcpy(interprete,"LUIS FONSI");strcpy(cancion,"DESPACITO");
    posicion(a,b);cout<<"Menciona el interprete o el nombre de la cancion que esta sonando en este momento:  ";
   PlaySound(TEXT("Luis Fonsi - Despacito.wav"),NULL,SND_ASYNC);
    break;

    case 8:
    strcpy(interprete,"PSY");strcpy(cancion,"GANGNAM STYLE");
    posicion(a,b);cout<<"Menciona el interprete o el nombre de la cancion que esta sonando en este momento:  ";
    PlaySound(TEXT("PSY - Gangnam Style.wav"),NULL,SND_ASYNC);
    break;

    case 9:
    strcpy(interprete,"TYLOR SWIFT");strcpy(cancion,"SHAKE IT OFF");
    posicion(a,b);cout<<"Menciona el interprete o el nombre de la cancion que esta sonando en este momento:  ";
    PlaySound(TEXT("Taylor Swift - Shake It Off.wav"),NULL,SND_ASYNC);
    break;

    default:
    strcpy(interprete,"WIZ KHALIFA");strcpy(cancion,"SEE YOU AGAIN");
    posicion(a,b);cout<<"Menciona el interprete o el nombre de la cancion que esta sonando en este momento:  ";
    PlaySound(TEXT("Wiz Khalifa - See You Again.wav"),NULL,SND_ASYNC);
    break;
    }
posicion(40,6);cout<<"VIDAS";
posicion(48,6);cout<<"\3 \3 \3 \3 \3";posicion(borrar,6);cout<<"       ";
posicion(5,9);cout<<"Nombre de el interprete/grupo de la cancion : ";gets(respuesta_i);
strupr(respuesta_i);x=strcmp(interprete,respuesta_i);
if(x==0){posicion(70,9);cout<<"CORRECTO </";}else{posicion(70,9);cout<<"INCORRECTO ";printf("%c",88);}
posicion(5,11);cout<<"Nombre de la cancion : ";gets(respuesta_c);
strupr(respuesta_c);y=strcmp(cancion,respuesta_c);
if(y==0){posicion(70,11);cout<<"CORRECTO </";}else{posicion(70,11);cout<<"INCORRECTO ";printf("%c",88);}
intentos++;
if(x==0||y==0){cout<<"\n \n EXCELENTE TE QUEDAN ";printf("%i",cont);cout<<" RESPUESTAS CORRECTAS PARA EL SIGUIENTE NIVEL";ans_bien++;cont--;}
Sleep(2000);
if(x!=0&&y!=0){borrar=n_b-2;cout<<"\n \n ERROR HAS PERDIDO UNA VIDA";}
Sleep(1000);
system("cls");
}while(ans_bien!=2&&borrar!=48);
}

int frases_celebres()
{
int frases_c,a=1,b=3,ans_bien=0,cont=1;
char autor[50],respuesta[50];
intentos=1;
srand(time(NULL));

do
{
n_b=borrar;
int al, var, nums[10],y=1,i;
posicion(5,0);cout<<"IPN";posicion(105,0);cout<<"UPIITA";
posicion(30,1);cout<<"NIVEL 5 - QUIEN ES EL AUTOR DE ESTA FRASE CELEBRE?";
frases_c=1+rand()%10;//frases celebres
do{
    var=1;
    while(var>0)
    {
        var=0;
        for(i=0;i<y;i++)
        {
        if(frases_c==nums[i])
            {
            var++;
            frases_c=1+rand()%10;
            }
        }
    }
     nums[y-1]=frases_c;
       y++;
}while(y<=10);
    switch(frases_c)
    {
    case 1:
    strcpy(autor,"BENITO JUAREZ"); posicion(a+30,b);cout<<"Menciona el autor de la siguiente frase celebre: ";
    posicion(a+15,b+1);cout<<"<<El respeto al derecho ajeno es la pa>>\n\n";
    break;

    case 2:
    strcpy(autor,"STEVE JOBS"); posicion(a+30,b);cout<<"Menciona el autor de la siguiente frase celebre: ";
    posicion(a+15,b+1);cout<<"<<Si tu no trabajas pñor tus sueños, alguien mas te contratara para que trabajes por los suyos>>\n\n";
    break;

    case 3:
    strcpy(autor,"NELSON MANDELA"); posicion(a+30,b);cout<<"Menciona el autor de la siguiente frase celebre: ";
    posicion(a+15,b+1);cout<<"<<La educacion es el arma mas poderosa que puedes usar paracambiar al mundo>>\n\n";
    break;

    case 4:
    strcpy(autor,"ARISTOTELES"); posicion(a+30,b);cout<<"Menciona el autor de la siguiente frase celebre: ";
    posicion(a+15,b+1);cout<<"<<El sabio no dice nunca todo lo que piensa, pero siempre piensa todo lo que dice>>\n\n";
    break;

    case 5:
    strcpy(autor,"STEVE JOBS"); posicion(a+30,b);cout<<"Menciona el autor de la siguiente frase celebre: ";
    posicion(a+15,b+1);cout<<"<<El tiempo es limitado no lo malgastes viviendo la vida de otro >>\n\n";
    break;

    case 6:
    strcpy(autor,"NIKOLA TESLA"); posicion(a+30,b);cout<<"Menciona el autor de la siguiente frase celebre: ";
    posicion(a+15,b+1);cout<<"<<En realidad no me preocupa que quieran robar mis ideas, me preocupa que ellos no las tengan>>\n\n";
    break;

    case 7:
    strcpy(autor,"TOMAS ALBA EDISON"); posicion(a+30,b);cout<<"Menciona el autor de la siguiente frase celebre: ";
    posicion(a+15,b+1);cout<<"<<El valor de una idea radica en el uso de la misma>>\n\n";
    break;

    case 8:
    strcpy(autor,"CONFUCIO"); posicion(a+30,b);cout<<"Menciona el autor de la siguiente frase celebre: ";
    posicion(a+15,b+1);cout<<"<<Elije un trabajo que ames y no tendras que trabajar ningun dia de tu vida>>\n\n";
    break;

    case 9:
    strcpy(autor,"WILLIAM SHAKESPEARE"); posicion(a+30,b);cout<<"Menciona el autor de la siguiente frase celebre: ";
    posicion(a+15,b+1);cout<<"<<Ser o no ser, esa es la cuestion>>\n\n";
    break;

    default:
    strcpy(autor,"ELON MUSK"); posicion(a+30,b);cout<<"Menciona el autor de la siguiente frase celebre: ";
    posicion(a+15,b+1);cout<<"<<Muchas cosas son improbables, solo unas pocas son imposibles>>\n\n";
    break;
    }
posicion(40,6);cout<<"VIDAS";
posicion(48,6);cout<<"\3 \3 \3 \3 \3";posicion(borrar,6);cout<<"       ";
posicion(1,9);cout<<"Escribe tu respuesta : ";gets(respuesta);
strupr(respuesta);
x=strcmp(autor,respuesta);
if(x==0){cout<<"\n\n EXCELENTE TE QUEDAN ";printf("%i",cont);cout<<" AUTORS CORRECTOS PARA PASAR AL SIGUIENTE NIVEL";ans_bien++;cont--;}
Sleep(2000);
if(x!=0){borrar=n_b-2;cout<<"\n\nERROR HAS PERDIDO UNA VIDA";}
Sleep(1000);
system("cls");
}while(ans_bien!=2&&borrar!=48);
}

int nivel_final()
{
int cont=2000,puntos=20;
n_b=borrar;
OcultaCursor();
marco();
upiita_ipn();
posicion(pos_x_comida,pos_y_comida); printf("%c", 4);

while((cont!=0 && perder()) && puntos!=0)
{
    posicion(5,0);cout<<"IPN";posicion(105,0);cout<<"UPIITA";
    posicion(50,0);cout<<"NIVEL FINAL";
posicion(23,1);printf("   _        _       ___   ___   ___   ___   ___   ___   _  _   _____   ___ ");
posicion(23,2);printf("  | |      /_%c     / __| | __| | _ %c | _ %c |_ _| | __| | %c| | |_   _| | __|",92,92,92,92,92,92);
posicion(23,3);printf("  | |__   / _ %c    %c__ %c | _|  |   / |  _/  | |  | _|  | .` |   | |   | _| ",92,92,92);
posicion(23,4);printf("  |____| /_/ %c_%c   |___/ |___| |_|_%c |_|   |___| |___| |_|%c_|   |_|   |___|",92,92,92,92,92,92,92,92);

    cont--;
    borrar_rastro();
    guardar_posicion();
    rastro();
    comida();
    teclas();
    teclas();

    if(direccion==1) pos_y_serpiente--;
    if(direccion==2) pos_y_serpiente++;
    if(direccion==3) pos_x_serpiente++;
    if(direccion==4) pos_x_serpiente--;

    if (pos_x_serpiente==pos_x_comida && pos_y_serpiente==pos_y_comida){puntos--;aumento=puntos;}
    Sleep(velocidad+(aumento-4));
    posicion(5,10);cout<<"CONTADOR : ";posicion(7,12);printf("%i",cont);
    posicion(1,15);cout<<"COMIDA RESTANTE : ";posicion(8,17);printf("%i",puntos);if(puntos<10){posicion(9,17);cout<<" ";}
}
conti=cont;punto=puntos;
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
int contador_descendente()
{
for(int x=9;x>=0;x--)
{
    posicion(35,8);cout<<"HAS PERDIDO";
    posicion(30,9);cout<<"TE QUEDASTE SIN VIDAS";
    posicion(20,10);cout<<"Tempo de espera para volver a jugar o salir";
    posicion(40,11);printf("%i",x);
    Sleep(1000);
}
}
int cont_desc_inicio()
{
  for(int x=9;x>=0;x--)
{
posicion(50,18);cout<<"ESTAS LISTO??";
posicion(45,19);cout<<"EL JUEGO COMENZARA EN :";
posicion(57,21);printf("%i",x);Sleep(1000);
}
posicion(10,22);cout<<"SI NO ESTAS LISTO, PRESIONA ESC";posicion(70,22);cout<<"SI ESTAS LISTO, PRESIONA CUALQUIER TECLA";
esc=getch();
system("cls");
}
int mensaje_GANADOR()
{
posicion(2,3);printf(" __        ______         __        ______     _______ .______           ___           _______..___________. _______ ");
posicion(2,4);printf("|  |      /  __  %c       |  |      /  __  %c   /  _____||   _  %c         /   %c         /       ||           ||   ____|",92,92,92,92);
posicion(2,5);printf("|  |     |  |  |  |      |  |     |  |  |  | |  |  __  |  |_)  |       /  ^  %c       |   (----``---|  |----`|  |__   ",92);
posicion(2,6);printf("|  |     |  |  |  |      |  |     |  |  |  | |  | |_ | |      /       /  /_%c  %c       %c   %c        |  |     |   __|  ",92,92,92,92);
posicion(2,7);printf("|  `----.|  `--'  |      |  `----.|  `--'  | |  |__| | |  |%c  %c----. /  _____  %c  .----)   |       |  |     |  |____ ",92,92,92);
posicion(2,8);printf("|_______| %c______/       |_______| %c______/   %c______| | _| `._____|/__/     %c__%c |_______/        |__|     |_______|",92,92,92,92,92);

posicion(5,10);printf(" _______     # ________      # ___   __      # ________      # ______      # ______      # ______       #");
posicion(5,11);printf("/______/%c    #/_______/%c     #/__/%c /__/%c    #/_______/%c     #/_____/%c     #/_____/%c     #/_____/%c      #",92,92,92,92,92,92,92,92);
posicion(5,12);printf("%c::::__%c/__  #%c::: _  %c %c    #%c::%c_%c%c  %c %c   #%c::: _  %c %c    #%c:::_ %c %c    #%c:::_ %c %c    #%c:::_ %c %c     #",92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92);
posicion(5,13);printf(" %c:%c /____/%c # %c::(_)  %c %c   # %c:. `-%c  %c %c  # %c::(_)  %c %c   # %c:%c %c %c %c   # %c:%c %c %c %c   # %c:(_) ) )_   #",92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92);
posicion(5,14);printf("  %c:%c%c_  _%c/ #  %c:: __  %c %c  #  %c:. _    %c %c #  %c:: __  %c %c  #  %c:%c %c %c %c  #  %c:%c %c %c %c  #  %c: __ `%c %c  #",92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92);
posicion(5,15);printf("   %c:%c_%c %c %c #   %c:.%c %c  %c %c #   %c. %c`-%c  %c %c#   %c:.%c %c  %c %c #   %c:%c/.:| | #   %c:%c_%c %c %c #   %c %c `%c %c %c #",92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92);
posicion(5,16);printf("    %c_____%c/ #    %c__%c/%c__%c/ #    %c__%c/ %c__%c/#    %c__%c/%c__%c/ #    %c____/_/ #    %c_____%c/ #    %c_%c/ %c_%c/ #",92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92);
posicion(5,17);printf("            ##              ##              ##              ##            ##            ##             ##");

}
int mensaje_PERDEDOR()
{
posicion(20,3);printf(" __        ______            _______. __   _______ .__   __. .___________.  ______   ");
posicion(20,4);printf("|  |      /  __  %c          /       ||  | |   ____||  %c |  | |           | /  __  %c  ",92,92,92,92);
posicion(20,5);printf("|  |     |  |  |  |        |   (----`|  | |  |__   |   %c|  | `---|  |----`|  |  |  | ",92);
posicion(20,6);printf("|  |     |  |  |  |         %c   %c    |  | |   __|  |  . `  |     |  |     |  |  |  | ",92,92);
posicion(20,7);printf("|  `----.|  `--'  |     .----)   |   |  | |  |____ |  |%c   |     |  |     |  `--'  | ",92);
posicion(20,8);printf("|_______| %c______/      |_______/    |__| |_______||__| %c__|     |__|      %c______/  ",92,92,92);

posicion(3,10);printf("  __    __       ___           _______.     .______    _______ .______       _______   __   _______    ______   ");
posicion(3,11);printf(" |  |  |  |     /   %c         /       |     |   _  %c  |   ____||   _  %c     |       %c |  | |       %c  /  __  %c  ",92,92,92,92,92,92);
posicion(3,12);printf(" |  |__|  |    /  ^  %c        |   (----`    |  |_)  | |  |__   |  |_)  |    |  .--.  ||  | |  .--.  ||  |  |  | ",92);
posicion(3,13);printf(" |   __   |   /  /_%c  %c       %c   %c         |   ___/  |   __|  |      /     |  |  |  ||  | |  |  |  ||  |  |  | ",92,92,92,92);
posicion(3,14);printf(" |  |  |  |  /  _____  %c  .----)   |        |  |      |  |____ |  |%c  %c----.|  '--'  ||  | |  '--'  ||  `--'  | ",92,92,92);
posicion(3,15);printf(" |__|  |__| /__/     \___%c |_______/         | _|      |_______|| _| `._____||_______/ |__| |_______/  %c______/  ",92,92);
}
