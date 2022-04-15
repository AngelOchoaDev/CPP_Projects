#include<trx.h>

class Persona
{
	protected:
		char Nombre[30];
		int Edad;
	
	public:
		Persona();
};

class Empleado:Persona
{
	private:
		float HoraExtra;
		float CostoHora;
	
	public:
		Empleado();
		void MostrarDatos();
};

class Director:Persona
{
	private:
		float Bono;
	
	public:
		Director();
		void MostrarDatos();
};

Persona::Persona()
{
	system("cls");
	cout<<"\n\n\tPersona:";
	cout<<"\n\n\tNombre: ";
	cin>>Nombre;
	cout<<"\n\tEdad: ";
	cin>>Edad;
	cout<<"\n\n\tDatos guardados correctamente!";
	system("pause>xd");
}

Empleado::Empleado()
{
	system("cls");
	cout<<"\n\n\tEmpleado: " <<Nombre;
	cout<<"\n\tEdad: " <<Edad;
	cout<<"\n\n\tCuantas horas extra?:";
	cin>>HoraExtra;
	cout<<"\n\tEl costo de hora extra?";
	cin>>CostoHora;
	cout<<"\n\n\tDatos guardados correctamente!";
	system("pause>xd");
}

void Empleado::MostrarDatos()
{
	cout<<"\n\n\tEn seguida se muestran los datos del empleado.";
	cout<<"\n\n\tNombre: " <<Nombre;
	cout<<"\n\tEdad: " <<Edad;
	cout<<"\n\tHoras Extra: " <<HoraExtra;
	cout<<"\n\tCosto de hora extra: " <<CostoHora;
	cout<<"\n\tTotal ganado de horas extra: " <<CostoHora*HoraExtra;
	system("pause>xd");
}

Director::Director()
{
	system("cls");
	Bono=25350.32;
	cout<<"\n\n\tNombre del director?: ";
	cin>>Nombre;
	cout<<"\n\tEdad del director?: ";
	cin>>Edad;
	cout<<"\n\n\tDatos guardados correctamente!";
	system("pause>xd");
}

void Director::MostrarDatos()
{
	cout<<"\n\n\tEn seguida se muestran los datos del director.";
	cout<<"\n\n\tNombre: " <<Nombre;
	cout<<"\n\tEdad: " <<Edad;
	cout<<"\n\tBono: " <<Bono;
	system("Pause>xd");
}
