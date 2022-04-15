#include<trx.h>

class persona
{
	protected:
		char nombre[20];
		int edad;
		
	public:
		persona(char[], int);
};

class alumno : public persona
{
	protected:
		int boleta;
		
	public:
		alumno(char[], int, int);
};

class regular : public alumno
{
	private:
		char carrera[20];
		int numeroMaterias;
		
	public:
		regular(char[], int, int);
		void mostrarDatos();
};
//////////////////////clases - constructores///////////////7

persona::persona(char a[], int b)
{
	strcpy(nombre,a);
	edad=b;
}

alumno::alumno(char a[], int b, int c) : persona(a,b)
{
	boleta=c;
}

regular::regular(char a[], int b, int c) : alumno(a,b,c)
{
	cout<<"\n\n\tIngresa tu carrera: ";
	cin>>carrera;
	cout<<"\n\tIngresa tu numero actual de materias: ";
	cin>>numeroMaterias;
}

void regular::mostrarDatos()
{
	cout<<"\n\n\tNombre del alumno: " <<nombre;
	cout<<"\n\tEdad: " <<edad;
	cout<<"\n\tBoleta: " <<boleta;
	cout<<"\n\tCarrera: " <<carrera;
	cout<<"\n\tNumero de materias: " <<numeroMaterias;
	cout<<"\n\n\t";
	system("pause>xd");
}
