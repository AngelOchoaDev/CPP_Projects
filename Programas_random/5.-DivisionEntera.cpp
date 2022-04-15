#include<trx.h>
#include "NumeroRacional.hpp"

int mcd(int, int);
void imprimir(int, int, int);

main()
{
	int x, y, d;
	NumeroRacional a;
	x=a.onumerador();
	y=a.odenominador();
	d=mcd(x,y);
	system("pause>xd");
	imprimir(x,y,d);
	system("pause>xd");
}

int mcd(int x, int y)
{
	int c;
	cout<<"\n\n\tSe procedera a obtener el mcd de sus valores.";
	do
	{
		c=x%y;
		x=y;
		y=c;
	}while(y!=0);
	return x;
}

void imprimir(int x, int y, int d)
{
	system("cls");
	cout<<"\n\n\tValor 1: " <<x <<"\n\tValor 2: " <<y <<"\n\tmcd= " <<d <<"\n\n";
}
