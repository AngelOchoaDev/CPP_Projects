#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

using namespace std;

class smartphone
{
	float camara;
	float pantalla;
	float procesador;
	int memoria;
	
	public:
		smartphone();
		smartphone(float, float, float, int);
		void fotografia();
		void videos();
		void llamadas();
		void jugar();
		void datos();
};

smartphone::smartphone()
{
	camara=0;
	pantalla=0;
	procesador=0;
	memoria=0;
	cout<<"\n\n\tSe ha creado el objeto (vacio)!";
	Sleep(1500);
	system("cls");
}

smartphone::smartphone(float a, float b, float c, int d)
{
	camara=a;
	pantalla=b;
	procesador=c;
	memoria=d;
}

void smartphone::fotografia()
{
	cout<<"\n\n\tTe has tomado una fotografia! :D ";
	Sleep(1500);
}

void smartphone::videos()
{
	cout<<"\n\n\tEl video que tomaste se guardo con exito! :D ";
	Sleep(1500);
}

void smartphone::llamadas()
{
	cout<<"\n\n\tHas hecho una llamada :D";
	Sleep(1500);
}
void smartphone::jugar()
{
	cout<<"\n\n\tHas abierto un juego :D";
	Sleep(1500);
}

void smartphone::datos()
{
	cout<<"\n\n\tLa camara es de " <<camara <<" megapixeles.";
	cout<<"\n\tLa pantalla es de " <<pantalla <<" pulgadas.";
	cout<<"\n\tEl procesador es de " <<procesador <<" GHz.";
	cout<<"\n\tLa memoria es de " <<memoria <<" GB.";
}
