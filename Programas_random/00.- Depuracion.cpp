#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<iostream>

using namespace std; 

void lista(), ver(), agregar();

struct Multimetro{
	int Precio, nf;
}Flotante;

main()
{
	int nf=1234, Precio=456;
	FILE *a;
	a=fopen("DATA.txt", "w");
	Flotante.nf=nf;
	Flotante.Precio=Precio;
	fwrite(&Flotante, sizeof(Flotante), 1, a);
	fclose(a);
	a=fopen("DATA.txt", "r");
	fread(&Flotante, sizeof(Flotante), 1, a);
	fclose(a);
	cout<<"\n\n\t" <<Flotante.nf <<"\t\t" <<Flotante.Precio;
	getch();
}
