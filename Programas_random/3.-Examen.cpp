#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<time.h>

using namespace std;

struct licencia
{
	char nombre[25];
	char curp[30];
	char rfc[15];
	char matricula[7];
	char marca[10];
	char modelo[10];
	int anio;

}a;

void registro();
void imprimir_datos();

main()
{
	cout<<"\n\n\tBienvenido al sistema de registro de conductores responsables";
	cout<<"\n\n\tFavor de ingresar sus datos para generar su licencia de conducir.";
	system("pause>xd");
	registro();
	system("cls");
	cout<<"\n\n\tSus datos se han guardado, si quiere ver su licencia presione Enter.";
	system("pause>xd");
	imprimir_datos();
	system("cls");
	cout<<"\n\n\tGracias por usar nuestro sistema, hasta pronto.";
	system("pause>xd");
}

void registro()
{
	system("cls");
	cout<<"\n\n\tFavor de ingresar su nombre: ";
	cin>>a.nombre;
	fflush(stdin);
	cout<<"\n\tFavor de ingresar su curp: ";
	cin>>a.curp;
	fflush(stdin);
	cout<<"\n\tFavor de ingresar su rfc: ";
	cin>>a.rfc;
	fflush(stdin);
	cout<<"\n\tFavor de ingresar su matricula: ";
	cin>>a.matricula;
	fflush(stdin);
	cout<<"\n\tFavor de ingresar la marca de su automovil: ";
	cin>>a.marca;
	fflush(stdin);
	cout<<"\n\tFavor de ingresar el modelo de su auto: ";
	cin>>a.modelo;
	fflush(stdin);
	cout<<"\n\tFavor de ingresar el anio de su auto: ";
	cin>>a.anio;
	fflush(stdin);
	system("cls");
	cout<<"\n\n\tGracias por su cooperacion, en un momento se procesa su solicitud.";
	Sleep(2500);
}

void imprimir_datos()
{
	cout<<"\n\n\tA continuacion se desplegaran su Licencia de Conducir:";
	cout<<"\n\n\tNombre: " <<a.nombre;
	cout<<"\n\tCurp: " <<a.curp;
	cout<<"\n\tRfc: " <<a.rfc;
	cout<<"\n\tMatricula del auto: " <<a.matricula;
	cout<<"\n\tMarca del auto: " <<a.marca;
	cout<<"\n\tModelo del auto: " <<a.modelo;
	cout<<"\n\tAnio del auto: " <<a.anio;
	system("pause>xd");
}
