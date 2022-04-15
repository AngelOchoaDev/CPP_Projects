#include<trx.h>
////////////////////clases//////////////////////////
class club
{
	protected:
		char sucursal[20];
	public:
		club(char[]);
};

class actividad
{
	protected:
		char nombre[20];
		float costo;
	public:
		actividad(char[], float);
};

class adicional
{
	protected:
		char nombre[20];
		float costo;
	public:
		adicional(char[], float);
};

class persona : public club, public adicional, public actividad
{
	protected:
		char nombre[20];
		float mensualidad;
	public:
		persona(char[], float, char[], char[], float, char[], float);/*persona, persona, club, actividad, actividad, adicional, adicional*/
		float calcularmensualidad();
		void muestradatos();
};
/////////////////constructores////////////////////////
persona::persona(char a[20], float b, char c[20], char d[20], float e, char f[20], float g): club(c), actividad(d,e), adicional(f,g)
{
	strcpy(nombre, a);
	mensualidad=b;
}

club::club(char a[20])
{
	strcpy(sucursal,a);
}

actividad::actividad(char a[20], float b)
{
	strcpy(nombre,a);
	costo=b;
}

adicional::adicional(char a[20], float b)
{
	strcpy(nombre,a);
	costo=b;
}
////////////////////////////////funciones persona/////////////////////////
float persona::calcularmensualidad()
{
	mensualidad = actividad::costo + adicional::costo;
}

void persona::muestradatos()
{
	system("cls");
	cout<<"\n\n\tNombre: " <<nombre;
	cout<<"\n\tCosto actividad: " <<actividad::costo <<" - " <<actividad::nombre;
	cout<<"\n\tCosto adicional: " <<adicional::costo <<" - " <<adicional::nombre;
	cout<<"\n\tMensualidad: " <<mensualidad;
}
