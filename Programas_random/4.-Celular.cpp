#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<iostream>
#include "smartphone.hpp"

using namespace std;

main()
{
	float camara, pantalla, procesador;
	int memoria, ciclo=0, ciclo2=0, fotos=0;;
	smartphone a;
	cout<<"\n\n\tIngresa los megapixeles de la camara: ";
	cin>>camara;
	cout<<"\n\n\tIngresa las pulgadas de tu pantalla: ";
	cin>>pantalla;
	cout<<"\n\n\tIngresa los GHz de tu procesador: ";
	cin>>procesador;
	cout<<"\n\n\tIngresa la memoria de tu smartphone: ";
	cin>>memoria;
	smartphone b(camara, pantalla, procesador, memoria);
	a.datos();
	cout<<"\n";
	b.datos();
	system("pause>xd");
	system("cls");
	cout<<"\n\n\tSi quieres tomarte una foto presiona 1, sino, presiona cualquier\n\totro numero.";
	cout<<"\n\n\t R=";
	cin>>ciclo;
	if(ciclo==1)
	{
		system("cls");
		b.fotografia();
		fotos=fotos+1;
		do
		{
			system("cls");
			cout<<"\n\n\tSi quieres tomarte otra foto presiona 1, sino presiona otro numero.";
			cout<<"\n\n\tR=";
			cin>>ciclo2;
			if(ciclo2==1)
			{
				system("cls");
				b.fotografia();
				fotos=fotos+1;
			}
		}while(ciclo2==1);
	}
	system("cls");
	cout<<"\n\n\t Se han tomado " <<fotos <<" fotos. Hasta luego! :D";
	system("pause>xd");
}
