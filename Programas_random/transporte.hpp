#include<trx.h>
////////////////////////////////clases///////////////////////////////////7
class transporte
{
	protected:
		char tipo[15];
		
	public:
		transporte(char[]);
};

class terrestre: public transporte
{
	protected:
		float velocimetro;
	
	public:
		terrestre(char[], float);
};

class automovil: public terrestre
{
	private:
		char nombre[15];
		float capacidad;
	
	public:
		automovil(char[],float);
		void mostrar();
};
////////////////////constructores/////////////////////
transporte::transporte(char a[])
{
	system("cls");
	strcpy(tipo,a);
	cout<<"\n\n\tSe asignaron valores a transporte.";
	system("pause>xd");
}

terrestre::terrestre(char a[], float b): transporte(a)
{
	system("cls");
	velocimetro=b;
	cout<<"\n\n\tSe asignaron valores a transporte.";
	system("pause>xd");
}

automovil::automovil(char a[],float b): terrestre(a,b)
{
	system("cls");
	cout<<"\n\n\tNombre del auto?: ";
	cin>>nombre;
	cout<<"\n\n\tCapacidad de gasolina?: ";
	cin>>capacidad;
	cout<<"\n\n\tDatos guardados correctamente!";
	system("pause>xd");
}
/////////////////////mostrar//////////////////
void automovil::mostrar()
{
	system("cls");
	cout<<"\n\n\tTipo de transporte: " <<tipo <<".";
	cout<<"\n\tCapacidad de velocimetro: " << velocimetro <<".";
	cout<<"\n\tNombre del automovil: " <<nombre <<".";
	cout<<"\n\tCapacidad de gasolina: " <<capacidad <<".";
	system("pause>xd");
}
