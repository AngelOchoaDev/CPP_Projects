#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

///////////////clases/////////////////
class almacen
{
	protected:
		float ccafe; /* -> cantidad de cafe en almacen, manejar en gramos */
		float cazucar; /* -> cantidad de azucar en almacen, manejar en gramos */
		float ccrema; /* -> cantidad de crema en almacen, namejar en gramos */
		float caja; /* -> cantidad de dinero en caja, manejar en pesos */
		int ncapuccino; // ---> numero de cafes capuccinos vendidos
		int nexpresso;  // ---> numero de cafes expressos vendidos
		int namericano;  // ---> numero cafes de americanos vendidos
		
	public:
		almacen(float, float, float, float, int, int, int); /* -> constructor */
		float rcafe(); // --->devuelve la cantiad de cafe
		float rcrema(); // --->devuelve la cantiad de crema
		float razucar(); // -->devuelve la cantiad de azucar
		float rcaja();
		int rcapuccino(); // --->devuelve la cantidad de cafes capuccinos vendidos
		int rexpresso(); //--->devuelve la cantidad de cafes expressos vendidos
		int ramericano(); //--->devuelve la cantidad de cafes americanos vendidos
		virtual void inventario()=0; // -> checar inventario (virtual, cambia para vendedor y almacenista)
};

class vendedor : public almacen
{
	private:
		float pcapuccino; // -> precio cafe capuccino
		float pamericano; // -> precio cafe americano
		float pexpresso; // -> precio cafe expresso
	public:
		vendedor(float, float, float, float, int, int, int); // -> constructor
		~vendedor(); // -> destructor
		void inventario(); // -> checar inventario (inventario más dinero de caja)
		void ventac(); // -> venta de cafe capuccino
		void ventaa(); // -> venta cafe americano
		void ventae(); // -> venta cafe expresso
};

class almacenista : public almacen
{
	private:
		float pcafe; // -> precio del cafe a nosotros (por Kg)
		float pazucar; // -> precio del azucar a nosotros (por Kg)
		float pcrema; // -> precio de la crema a nosotros (por Kg)
	public:
		almacenista(float, float, float, float, int, int, int); // -> constructor
		~almacenista(); // -> destructor
		void inventario(); // -> checar inventario
		void llenaralmacen(); // -> llenar cafe, azucar y crema
		void llenarazucar(float); // -> llenar azucar
		void llenarcafe(float); // -> llenar cafe
		void llenarcrema(float); // -> llenar crema
		void InventarioBajo(); // -> Llenar ingrediente faltante
		void aviso(); // -> aviso por si falta algun material en especifico
};

class duenio : public almacen
{
	public:
		duenio(float, float, float, float, int, int, int); // --> constructor
		~duenio(); //--> destructor
		void inventario(); // --> checar inventario
		void aviso();
};
///////////////////constructores//////////////////////////////////////////

almacen::almacen(float a, float b, float c, float d, int e, int f, int g)
{
	ccafe=a;
	cazucar=b;
	ccrema=c;
	caja=d;
	ncapuccino=e;
	nexpresso=f;
	namericano=g;
	system("cls");
	cout<<"\n\n\tLa sesion se inicio correctamente.";
	Sleep(1250);
}

vendedor::vendedor(float a, float b, float c, float d, int e, int f, int g) : almacen(a,b,c,d,e,f,g)
{
	pcapuccino=35.00;
	pamericano=30.00;
	pexpresso=32.50;
}

almacenista::almacenista(float a, float b, float c, float d, int e, int f, int g) : almacen(a,b,c,d,e,f,g)
{
	pcafe=200.00;
	pcrema=54.9;
	pazucar=14.00;
}

duenio::duenio(float a, float b, float c, float d, int e, int f, int g) : almacen(a,b,c,d,e,f,g)
{
	// constructor vacío //
}

/////////////destructores////////////////////

vendedor::~vendedor()
{
	system("cls");
	cout<<"\n\n\tLa sesion se cerro correctamente.";
}

almacenista::~almacenista()
{
	system("cls");
	cout<<"\n\n\tLa sesion se cerro correctamente.";
}

duenio::~duenio()
{
	system("cls");
	cout<<"\n\n\tLa sesion se cerro correctamente.";
}

//////////////funciones almacen (funciones generales)////////////////

float almacen::rcaja()
{
	return caja;	
}

float almacen::rcafe()
{
	return ccafe;
}

float almacen::rcrema()
{
	return ccrema;
}

float almacen::razucar()
{
	return cazucar;
}

int almacen::rcapuccino()
{
	return ncapuccino;
}

int almacen::rexpresso()
{
	return nexpresso;
}

int almacen::ramericano()
{
	return namericano;
}
//////////////////////funciones vendedor//////////////////////

void vendedor::inventario()
{
	cout<<"\n\n\tCafe: " <<setprecision(5) <<(ccafe/1000) <<" Kg.";
	cout<<"\n\tAzucar: " <<setprecision(5) <<(cazucar/1000) <<" Kg.";
	cout<<"\n\tCafe: " <<setprecision(5) <<(ccrema/1000) <<" Kg.";
	cout<<"\n\tCaja: " <<setprecision(6) <<caja <<" pesos.";
}

void vendedor::ventac()
{
	if( ccafe<=9.50 | ccrema<=4.25 | cazucar<=5.01 )
	{
		system("cls");
		cout<<"\n\n\tNo se puede realizar venta, ingredientes insuficientes.";
	}else{
		caja=caja+pcapuccino;
		ccafe=ccafe-9.00;
		ccrema=ccrema-4.25;
		cazucar=cazucar-5.01;
		ncapuccino=ncapuccino+1;
		system("cls");
		cout<<"\n\n\tVenta realizada con exito.";
	}
	
}

void vendedor::ventaa()
{
	if( ccafe<=9.09 | cazucar<=5.01 )
	{
		system("cls");
		cout<<"\n\n\tNo se puede realizar venta, ingredientes insuficientes.";
	}else{
		caja=caja+(vendedor::pamericano);
		ccafe=ccafe-9.00;
		cazucar=cazucar-5.01;
		namericano=namericano+1;
		system("cls");
		cout<<"\n\n\tVenta realizada con exito.";
	}
}

void vendedor::ventae()
{
	if(ccafe<=18.18)
	{
		system("cls");
		cout<<"\n\n\tNo se puede realizar venta, ingredientes insuficientes.";
	}else{
		caja=caja+pexpresso;
		ccafe=ccafe-18.00;
		nexpresso=nexpresso+1;
		system("cls");
		cout<<"\n\n\tVenta realizada con exito.";
	}
	
}

//////////////funciones almacenista//////////////////7

void almacenista::inventario()
{
	cout<<"\n\n\tPrecios actuales:";
	cout<<"\n\n\tCafe: $" <<setprecision(2) <<pcafe <<" Azucar: $" <<pazucar <<" Crema: $" <<pcrema;
	cout<<"\n\n\tCantidad actual en inventario:";
	cout<<"\n\tCafe: " <<setprecision(5) <<(ccafe/1000) <<" Kg.";
	cout<<"\n\tAzucar: " <<setprecision(5) <<(cazucar/1000) <<" Kg.";
	cout<<"\n\tCafe: " <<setprecision(5) <<(ccrema/1000) <<" Kg.";
}

void almacenista::llenaralmacen()
{
	cout<<"\n\n\t Se llenará el almacen a su maxima capacidad.";
	caja=caja-(((10000.00-ccafe)*pcafe)+((5000.00-cazucar)*pazucar)+((5000.00-ccrema)*pcrema));
	ccafe=10000.00;
	cazucar=5000.00;
	ccrema=5000.00;
}

void almacenista::llenarazucar(float a)
{
	caja=caja-(a*pazucar);
	cazucar=cazucar+(a*1000);
	system("cls");
	cout<<"\n\n\tCantidad adquirida correctamente.";
}

void almacenista::llenarcafe(float b)
{
	caja=caja-(b*pcafe);
	ccafe=ccafe+(b*1000);
	system("cls");
	cout<<"\n\n\tCantidad adquirida correctamente.";
}

void almacenista::llenarcrema(float c)
{
	caja=caja-(c*pcrema);
	ccrema=ccrema+(c*1000);
	system("cls");
	cout<<"\n\n\tCantidad adquirida correctamente.";
}

void almacenista::aviso()
{
	if(ccafe<=1000.00)
	{
		cout<<"\n\n\tLa cantidad de cafe es muy baja, favor de llenar el stock de cafe.";
	}
	if(ccrema<=500.00)
	{
		cout<<"\n\n\tLa cantidad de crema es muy baja, favor de llenar el stock de crema.";
	}
	if(cazucar<=500.00)
	{
		cout<<"\n\n\tLa cantidad de cafe es muy baja, favor de llenar el stock de cafe.";
	}
}

void almacenista::InventarioBajo()
{
	int x;
	marca:
		if(ccafe<=1000.00)
		{
			
			cout<<"\n\n\tLa cantidad de cafe es demasiado baja.";
			cout<<"\n\n\tPrecio del cafe: " <<pcafe;
			cout<<"\n\tCantidad de cafe actual: " <<setprecision(5) <<(ccafe/1000) <<" Kg.";
			cout<<"\n\tCantidad (Kg) que desea ingresar?: ";
			cin>>x;
			ccafe=ccafe+(x*1000);
			caja=caja-(x*pcafe);
			goto marca;
		}
		if(cazucar<=1000.00)
		{
			cout<<"\n\n\tLa cantidad de azucar es demasiado baja.";
			cout<<"\n\n\tPrecio del azucar: " <<pazucar;
			cout<<"\n\tCantidad de azucar actual: " <<setprecision(5) <<(cazucar/1000) <<" Kg.";
			cout<<"\n\tCantidad (Kg) que desea ingresar?: ";
			cin>>x;
			cazucar=cazucar+(x*1000);
			caja=caja-(x*pazucar);
			goto marca;
		}
		if(ccrema<=1000.00)
		{
			cout<<"\n\n\tLa cantidad de crema es demasiado baja.";
			cout<<"\n\n\tPrecio de la crema: " <<pcrema;
			cout<<"\n\tCantidad de crema actual: " <<setprecision(5) <<(ccrema/1000) <<" Kg.";
			cout<<"\n\tCantidad (Kg) que desea ingresar?: ";
			cin>>x;
			ccrema=ccrema+(x*1000);
			caja=caja-(x*pcrema);
			goto marca;
		}
		system("cls");
		cout<<"\n\n\tGracias por vuestra paciencia.";		
}

////////////////////funciones duenio////////////////////////7

void duenio::inventario()
{
	cout<<"\n\tCaja: " <<setprecision(2) <<caja <<" pesos.";
	cout<<"\n\n\tCafe: " <<setprecision(5) <<(ccafe/1000) <<" Kg.";
	cout<<"\n\tAzucar: " <<setprecision(5) <<(cazucar/1000) <<" Kg.";
	cout<<"\n\tCafe: " <<setprecision(5) <<(ccrema/1000) <<" Kg.";
	cout<<"\n\n\tSe han vendido:\n";
	cout<<"\n\tCafes Capuccino: " <<ncapuccino;
	cout<<"\n\tCafes Expresso:  " <<nexpresso;
	cout<<"\n\tCafes Americano: " <<namericano;
}

void duenio::aviso()
{
	if(ccafe<=1000.00)
	{
		cout<<"\n\n\tLa cantidad de cafe es muy baja, favor de llenar el stock de cafe.";
	}
	if(ccrema<=500.00)
	{
		cout<<"\n\n\tLa cantidad de crema es muy baja, favor de llenar el stock de crema.";
	}
	if(cazucar<=500.00)
	{
		cout<<"\n\n\tLa cantidad de cafe es muy baja, favor de llenar el stock de cafe.";
	}
}
