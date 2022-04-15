#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<iostream>

using namespace std; 

void lista(), ver(), agregar();

struct Multimetro{
	char Funciones[10][20];
	char Tipo[20];
	char Modelo[10];
	char Marca[20];
	int Precio, nf;
	char Precision[15];
} Producto[20], Flotante;

// Capture caracteristicas de un  multimetro y que forme parte de un catalogo de materiales que existen
// en el labotratorio de electrónica, usando estructuras y archivos.

main()
{
	int a, b;
	b=0;
	cout<<"\n\n\tHola, bienvenido.";
	cout<<"\n\n\tHoy veremos varias opciones en las cuales usted, usuario, \n\tpodra ver o agregar productos segun su conveniencia.";
	getch();
	do
	{
		system("cls");
		cout<<"\n\n\tMultimetros UPIITA:\n";
		cout<<"\n\t1.-Ver Lista de productos.";
		cout<<"\n\t2.-Ver un producto.";
		cout<<"\n\t3.-Agregar un producto.";
		cout<<"\n\t4.-Salir.";
		cout<<"\n\n\tOpcion: ";
		cin>>a;
		switch(a)
		{
			case 1:
				system("cls");
				lista();
				break;
				
			case 2:
				system("cls");
				ver();
				break;
			
			case 3:
				system("cls");
				agregar();
				break;
			
			case 4:
				system("cls");
				cout<<"\n\n\tGracias por usar nuestro sistema, hasta pronto. nwn";
				getch();
				b=1;
				break;
			
			default:
				system("cls");
				cout<<"\n\n\tUsted ha usado una opcion no disponible.";
				getch();
				break;
		}
	}while(b==0);
}

void lista()
{
	int np=0;
	FILE *a;
	a=fopen("UPIITA.txt", "r");
	if(a==NULL)
	{
		cout<<"\n\n\tNo existe registro alguno, favor de agregar un producto.";
		getch();
	}
	else
	{
		cout<<"\n\n\tLista de productos:\n";
		while(!feof(a))
		{
			while(fread(&Flotante, sizeof(Flotante), 1, a)==1)
			{
				strcpy(Producto[np].Marca, Flotante.Marca);
				strcpy(Producto[np].Modelo, Flotante.Modelo);
				strcpy(Producto[np].Tipo, Flotante.Tipo);
				strcpy(Producto[np].Precision, Flotante.Precision);
				for(int s=0; s++; s<Flotante.nf)
				{
					strcpy(Producto[np].Funciones[s], Flotante.Funciones[s]);
				}
				Producto[np].Precio=Flotante.Precio;
				Producto[np].nf=Flotante.nf;
				cout<<"\n\t" <<np+1 <<".- " <<Producto[np].Marca <<" - " <<Producto[np].Modelo;
				np++;
			}
		}
	}
	fclose(a);
	cout<<"\n\n\t";
	getch();
}

void ver()
{
	int np=0, op=0, i=0, nf=0;
	FILE *a;
	a=fopen("UPIITA.txt", "r");
	if(a==NULL)
	{
		cout<<"\n\n\tNo existe registro anterior, favor de agregar un producto.";
		getch();
	}
	else
	{
		cout<<"\n\n\tLista de productos:\n";
		while(!feof(a))
		{
			while(fread(&Flotante, sizeof(Flotante), 1, a)==1)
			{
				strcpy(Producto[np].Marca, Flotante.Marca);
				strcpy(Producto[np].Modelo, Flotante.Modelo);
				strcpy(Producto[np].Tipo, Flotante.Tipo);
				strcpy(Producto[np].Precision, Flotante.Precision);
				Producto[np].Precio=Flotante.Precio;
				Producto[np].nf=Flotante.nf;
				do
				{
					strcpy(Producto[np].Funciones[i], Flotante.Funciones[i]);
					i++;
				}while(i<Flotante.nf);
				cout<<"\n\t" <<np+1 <<".- " <<Producto[np].Marca <<" - " <<Producto[np].Modelo;
				np++;
			}
		}
		cout<<"\n\n\tQue producto desea ver a detalle?: ";
		cin>>op;
		if(op<1|op>np)
		{
			do
			{
				system("cls");
				cout<<"\n\n\tOpcion invalida, no existe tal producto.";
				system("cls");
				cout<<"\n\n\tQue producto desea ver a detalle?\n";
				for(int v=0; v++; v<(np+1))
				{
					cout<<"\n\t" <<v <<".- " <<Producto[v].Marca <<" - " <<Producto[v].Modelo;
				}
				cout<<"\n\n\tR= ";
				cin>>op;
			}while(op<1|op>np);
		}
		op--;
		nf=Producto[op].nf;
		system("cls");
		cout<<"\n\n\tProducto " <<op+1 <<":\n";
		cout<<"\n\tMarca: " <<Producto[op].Marca;
		cout<<"\n\tModelo: " <<Producto[op].Modelo;
		cout<<"\n\tTipo: " <<Producto[op].Tipo;
		cout<<"\n\tPrecision: " <<Producto[op].Precision;
		cout<<"\n\tFunciones/caracteristicas:";
		int q=0;
		do
		{
			cout<<"\n\t\t-" <<Producto[op].Funciones[q];
			q++;
		}while(q<nf);
		cout<<"\n\tPrecio: " <<Producto[op].Precio;
		fclose(a);
		cout<<"\n\n\t";
		system("pause");
	}
}

void agregar()
{
	int pp=0;
	int nf=0;
	int np=0;
	FILE *a;
	a=fopen("UPIITA.txt", "r");
	if(a==NULL)
	{
		cout<<"\n\n\tNo existe registro anterior, se creara uno nuevo.";
		getch();
	}
	else
	{
		while(!feof(a))
		{
			while(fread(&Flotante, sizeof(Flotante), 1, a)==1)
			{
				strcpy(Producto[np].Marca, Flotante.Marca);
				strcpy(Producto[np].Modelo, Flotante.Modelo);
				strcpy(Producto[np].Tipo, Flotante.Tipo);
				strcpy(Producto[np].Precision, Flotante.Precision);
				for(int u=0; u++; u<Flotante.nf)
				{
					strcpy(Producto[np].Funciones[u], Flotante.Funciones[u]);
				}
				Producto[np].Precio=Flotante.Precio;
				Producto[np].nf=Flotante.nf;
				np=np+1;
			}
		}
	}
	fclose(a);
	cout<<"\n\n\tProducto " <<np+1 <<":\n";
	cout<<"\n\tMarca: ";
	cin>>Flotante.Marca;
	fflush(stdin);
	cout<<"\n\tModelo: ";
	cin>>Flotante.Modelo;
	fflush(stdin);
	cout<<"\n\tTipo: ";
	cin>>Flotante.Tipo;
	fflush(stdin);
	cout<<"\n\tPrecision: ";
	cin>>Flotante.Precision;
	fflush(stdin);
	cout<<"\n\tPrecio: ";
	cin>>Flotante.Precio;
	fflush(stdin);
	cout<<"\n\tFunciones/Caracteristicas: ";
	cout<<"\n\t\t-Funcion Basica: ";
	cin>>Flotante.Funciones[nf];
	fflush(stdin);
	nf++;
	do
	{
		system("cls");
		cout<<"\n\n\tDesea agregar otra funcion/caracteristica?:";
		cout<<"\n\n\t1.-Si.\n\t2.-No.\n\n\tR= ";
		cin>>pp;
		fflush(stdin);
		if(pp<1|pp>2)
		{
			system("cls");
			cout<<"\n\n\tOpcion incorrecta. Desea agregar otra funcion/caracteristica?:";
			cout<<"\n\n\t1.-Si.\n\t2.-No.\n\n\tR= ";
			cin>>pp;
			fflush(stdin);
		}while(pp<1|pp>2);
		if(pp==1)
		{
			system("cls");
			cout<<"\n\n\tFuncion/caracteristica " <<nf+1 <<":";
			cin>>Flotante.Funciones[nf];
			fflush(stdin);
			nf++;
		}
	}while(pp!=2);
	Flotante.nf=nf;
	fflush(stdin);
	system("cls");
	//fin de recabado de datos e inicio de cambio de valores////
	strcpy(Producto[np].Marca, Flotante.Marca);
	strcpy(Producto[np].Modelo, Flotante.Modelo);
	strcpy(Producto[np].Tipo, Flotante.Tipo);
	strcpy(Producto[np].Precision, Flotante.Precision);
	Producto[np].Precio=Flotante.Precio;
	Producto[np].nf=Flotante.nf;
	int e=0;
	do
	{
		strcpy(Producto[np].Funciones[e], Flotante.Funciones[e]);
		e++;
	}while(e<Producto[np].nf);
	//fin de cambio de valores//
	np=np+1;
	a=fopen("UPIITA.txt", "w");
	int y=0, t=0;
	do
	{
		strcpy(Flotante.Marca,Producto[y].Marca);
		strcpy(Flotante.Modelo,Producto[y].Modelo);
		strcpy(Flotante.Tipo,Producto[y].Tipo);
		strcpy(Flotante.Precision,Producto[y].Precision);
		Flotante.Precio=Producto[y].Precio;
		Flotante.nf=Producto[y].nf;
		t=0;
		do
		{
			strcpy(Flotante.Funciones[t], Producto[np-1].Funciones[t]);
			t++;
		}while(t<Flotante.nf);
		fwrite(&Flotante, sizeof(Flotante), 1, a);
		y++;
	}while(y<np);
	fclose(a);
	cout<<"\n\n\tProducto guardado con Exito!";
	getch();
}
//end//
