#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <iostream>

	using namespace std;

	int main()
		{
			int x=0, y=0, pos1, pos2;
			char CATA1[]={'1','3','5','7', 'X'}, CATA2[]={'X','X','X','X'};

			OTRAVEZ:
				system("cls");
				srand(time(NULL));
				pos1=0+(rand()%5);

			cout<<"Las cifras son"<<CATA2[0]<<" "<<CATA2[1]<<" "<<CATA2[2]<<" "<<CATA2[3]<<"ERRORES"<<y;

			if (CATA1[pos1]=='X')
				{
					y++;
					cout<<"Erraste en tu selección: "<<CATA1[pos1];
					if(y>3)
						{
							cout<<"Tus oportunidades se agotaron";
							goto OVER;
						}
					else
						{
							goto OTRAVEZ;
						}
				}
			else
				{
				if(CATA1[pos1]==CATA2[pos1])
				{

				if (CATA1[0]==CATA2[0] && CATA1[1]==CATA2[1] && CATA1[2]==CATA2[2] && CATA1[3]==CATA2[3])
					{
						cout<<"Ganaste";
						goto OVER;
					}
				else
					{
						goto OTRAVEZ;
					}
				}
			else
				{
					cout<<"El valor es: "<<CATA1[pos1]<<"Donde esta el valor? En 0, en 1, en 2 o en 3?";
					cin>>pos2;
				}

			if(pos1==pos2)
				{
					cout<<"Le atinaste";
					CATA1[pos1]=CATA2[pos2];
					goto OTRAVEZ;
				}
			else
				{
					cout<<"Ya fuiste";
					goto OTRAVEZ;
				}
		OVER:
			system("pause>Kaleb es gay");
			system("pause>Kaleb es gay");
		}
}



