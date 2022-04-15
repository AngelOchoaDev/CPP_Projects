#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<time.h>
//////////////////////fin de librerias////////
using namespace std;
////////condiciones de uso de las librerias//////

///////////clases////////////////////
class Automovil
{
	/////catacteristicas////
	int Llantas;
	float Motor;
	int Cilindros;
	char Color[10];
	char Transmision;
	char Direccion;
	////////////////////////
	public:
	/////Metodos o funciones/////
	void IntroduceDatos()
	{
		cout<<"\n\tIntroduce el numero de llantas: ";
		cin>>Llantas;
		cout<<"\n\tIntroduce el tipo de Motor: ";
		cin>>Motor;
		cout<<"\n\tIntroduce el numero de cilindros de tu motor: ";
		cin>>Cilindros;
		cout<<"\n\tIntroduce el color de tu auto: ";
		cin>>Color;
		cout<<"\n\tIntroduce el tipo de Transmision: ";
		cin>>Transmision;
		cout<<"\n\tIntroduce el tipo de Direccion: ";
		cin>>Direccion;
	}
	
	void Avanzar()
	{
		cout<<"\n\tTu auto puede correr hasta 300 Km/h";
		cout<<"\n\tPor su Motor de " <<Motor <<"." <<endl;
	}
	
	void Frenar()
	{
		cout<<"\n\tTu auto tiene frenos tipo ABS.";
		cout<<"\n\tAparte de tener una direccion " <<((Direccion == 'H')? "hidraulica" : "mecanica") <<"." <<endl; /////IMPORTANTE///////
	}
	
	void Transportar()
	{
		cout<<"\n\tPueden viajar hasta 5 personas." <<endl;
	}
};
/////////////////////fin de clases////////////////

//////////////////////programa principal//////////
int main()
{
	Automovil Mio; //////////////un nuevo objeto de tipo Autoovil que se llama mio////////
	
	Mio.IntroduceDatos();
	Mio.Avanzar();
	Mio.Frenar();
	Mio.Transportar();
	system("Pause>xd");
	return 0;
}
