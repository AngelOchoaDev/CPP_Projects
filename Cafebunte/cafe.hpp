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
		float 	cantidadDeCafe; 			// -> cantidad de cafe en almacen, manejar en gramos
		float 	cantidadDeAzucar; 			// -> cantidad de azucar en almacen, manejar en gramos
		float 	cantidadDeCrema; 			// -> cantidad de crema en almacen, namejar en gramos
		float 	dineroEnCaja; 				// -> cantidad de dinero en caja, manejar en pesos
		int 	capuccinosVendidos; 		// -> numero de cafes capuccinos vendidos
		int 	expressosVendidos;  		// -> numero de cafes expressos vendidos
		int 	americanosVendidos;  		// -> numero cafes de americanos vendidos
		
	public:
		almacen(float, float, float, float, int, int, int); 		/* -> constructor */
		float getCantidadDeCafe(){return cantidadDeCafe;}; 			// --->devuelve la cantidad de cafe
		float getCantidadDeCrema(){return cantidadDeCrema;}; 		// --->devuelve la cantidad de crema
		float getCantidadDeAzucar(){return cantidadDeAzucar;}; 		// -->devuelve la cantidad de azucar
		float getDineroEnCaja(){return dineroEnCaja;};				// -->devuelve el dinero en caja
		int getCapuccinosVendidos(){return capuccinosVendidos;}; 	// --->devuelve la cantidad de cafes capuccinos vendidos
		int getExpressosVendidos(){return expressosVendidos;}; 		//--->devuelve la cantidad de cafes expressos vendidos
		int getAmericanosVendidos(){return americanosVendidos;}; 	//--->devuelve la cantidad de cafes americanos vendidos
		virtual void ObtenerInventario()=0; 						// -> checar inventario (virtual, cambia para vendedor y almacenista)
};

class vendedor : public almacen
{
	private:
		float precioCafeCapuccino; // -> precio cafe capuccino
		float precioCafeAmericano; // -> precio cafe americano
		float precioCafeExpresso; // -> precio cafe expresso
	public:
		vendedor(float, float, float, float, int, int, int); // -> constructor
		~vendedor(); // -> destructor
		void ObtenerInventario(); // -> checar inventario (inventario mas dinero de caja)
		void VenderCafeCapuccino(); // -> venta de cafe capuccino
		void VenderCafeAmericano(); // -> venta cafe americano
		void VenderCafeExpresso(); // -> venta cafe expresso
};

class almacenista : public almacen
{
	private:
		float precioDeCafe; // -> precio del cafe a nosotros (por Kg)
		float precioDeAzucar; // -> precio del azucar a nosotros (por Kg)
		float precioDeCrema; // -> precio de la crema a nosotros (por Kg)
	public:
		almacenista(float, float, float, float, int, int, int); // -> constructor
		~almacenista(); // -> destructor
		void ObtenerInventario(); // -> checar inventario
		void SurtirAlmacen(); // -> llenar cafe, azucar y crema
		void SurtirAzucar(float); // -> llenar azucar
		void SurtirCafe(float); // -> llenar cafe
		void SurtirCrema(float); // -> llenar crema
		void SurtirIngredienteFaltante(); // -> Llenar ingrediente faltante
		void AvisarDeInventarioBajo(); // -> aviso por si falta algun material en especifico
};

class duenio : public almacen
{
	public:
		duenio(float, float, float, float, int, int, int); // --> constructor
		~duenio(); //--> destructor
		void ObtenerInventario(); // --> checar inventario
		void AvisarDeInventarioBajo();
};
///////////////////constructores//////////////////////////////////////////

almacen::almacen(float a, float b, float c, float d, int e, int f, int g)
{
	cantidadDeCafe=a;
	cantidadDeAzucar=b;
	cantidadDeCrema=c;
	dineroEnCaja=d;
	capuccinosVendidos=e;
	expressosVendidos=f;
	americanosVendidos=g;
	system("cls");
	cout<<"\n\n\tLa sesion se inicio correctamente.";
	Sleep(1250);
}

vendedor::vendedor(float a, float b, float c, float d, int e, int f, int g) : almacen(a,b,c,d,e,f,g) //se llama al superconstructor
{
	precioCafeCapuccino=35.00;
	precioCafeAmericano=30.00;
	precioCafeExpresso=32.50;
}

almacenista::almacenista(float a, float b, float c, float d, int e, int f, int g) : almacen(a,b,c,d,e,f,g) //se llama al superconstructor
{
	precioDeCafe=57.00; 		//El precio de cafe para compra de insumos
	precioDeCrema=80.00;		//El precio de crema para compra de insumos
	precioDeAzucar=25.00;		//El precio de azucar para compra de insumos
}

duenio::duenio(float a, float b, float c, float d, int e, int f, int g) : almacen(a,b,c,d,e,f,g)
{
	// constructor vacio //
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

//////////////////////funciones vendedor//////////////////////

/**
 * @brief Despliega el inventario del almacen
 */
void vendedor::ObtenerInventario()
{
	cout<<"\n\n\tCafe:\t\t" <<getCantidadDeCafe()/1000 		<<" Kg.";
	cout<<"\n\tAzucar:\t\t" <<getCantidadDeAzucar()/1000 	<<" Kg.";
	cout<<"\n\tCrema:\t\t"  <<getCantidadDeCrema()/1000 	<<" Kg.";
	cout<<"\n\tCaja:\t\t" 	<<getDineroEnCaja()				<<" pesos.";
}

/**
 * @brief Realiza la venta de un cafe capuccino, descontando
 * del almacen los insumos usados y sumando a caja el ingreso
 * por la venta del cafe.
 */
void vendedor::VenderCafeCapuccino()
{
	if( cantidadDeCafe<=9.50 || cantidadDeCrema<=4.25 || cantidadDeAzucar<=5.01 )	//Aqui se definen los tresholds
	{
		system("cls");
		cout<<"\n\n\tNo se puede realizar venta, ingredientes insuficientes.";
	}else
	{
		//Calculos realizados en gramos
		cantidadDeCafe-=9.00;
		cantidadDeCrema-=4.25;
		cantidadDeAzucar-=5.01;
		capuccinosVendidos++;
		dineroEnCaja+=precioCafeCapuccino;
		system("cls");
		cout<<"\n\n\tVenta realizada con exito.";
	}
}

/**
 * @brief Realiza la venta de un cafe americano, descontando
 * del almacen los insumos usados y sumando a caja el ingreso
 * por la venta del cafe.
 */
void vendedor::VenderCafeAmericano()
{
	if( cantidadDeCafe<=9.09 | cantidadDeAzucar<=5.01 )
	{
		system("cls");
		cout<<"\n\n\tNo se puede realizar venta, ingredientes insuficientes.";
	}else
	{
		dineroEnCaja+=(vendedor::precioCafeAmericano); //ejemplo acceso por namespace
		cantidadDeCafe-=9.00;
		cantidadDeAzucar-=5.01;
		americanosVendidos++;
		system("cls");
		cout<<"\n\n\tVenta realizada con exito.";
	}
}

/**
 * @brief Realiza la venta de un cafe expresso, descontando
 * del almacen los insumos usados y sumando a caja el ingreso
 * por la venta del cafe.
 */
void vendedor::VenderCafeExpresso()
{
	if(cantidadDeCafe<=18.18)
	{
		system("cls");
		cout<<"\n\n\tNo se puede realizar venta, ingredientes insuficientes.";
	}else
	{
		dineroEnCaja+=precioCafeExpresso;
		cantidadDeCafe-=18.00;
		expressosVendidos++;
		system("cls");
		cout<<"\n\n\tVenta realizada con exito.";
	}
	
}

//////////////funciones almacenista//////////////////7

/**
 * @brief Despliega la informacion del inventario del almacen.
 */
void almacenista::ObtenerInventario()
{
	cout<<"\n\n\tPrecios actuales:";
	cout<<"\n\n\tCafe: $"  		<<precioDeCafe <<", Azucar: $" <<precioDeAzucar <<", Crema: $" <<precioDeCrema;
	cout<<"\n\n\tCantidad actual en inventario:";
	cout<<"\n\tCafe:\t\t"  		<<(cantidadDeCafe/1000) <<" Kg.";
	cout<<"\n\tAzucar:\t\t"  	<<(cantidadDeAzucar/1000) <<" Kg.";
	cout<<"\n\tCrema:\t\t"		<<(cantidadDeCrema/1000) <<" Kg.";
}

/**
 * @brief Surte el almacen. Para ello, se descuenta la caja
 * el dinero necesario para comprar los insumos faltantes
 * para llenar el almacen.
 */
void almacenista::SurtirAlmacen()
{
	cout<<"\n\n\t Se llenara el almacen a su maxima capacidad.";
	dineroEnCaja-=(((10000.00-cantidadDeCafe)/1000*precioDeCafe)+((5000.00-cantidadDeAzucar)/1000*precioDeAzucar)+((5000.00-cantidadDeCrema)/1000*precioDeCrema));
	cantidadDeCafe=10000.00;
	cantidadDeAzucar=5000.00;
	cantidadDeCrema=5000.00;
}

/**
 * @brief Surte la cantidad de azucar especificada
 * 
 * @param a Azucar en kilogramos
 */
void almacenista::SurtirAzucar(float a)
{
	dineroEnCaja-=(a*precioDeAzucar);
	cantidadDeAzucar+=(a*1000);
	system("cls");
	cout<<"\n\n\tCantidad adquirida correctamente.";
}

/**
 * @brief Surte la cantidad de cafe especificado
 * 
 * @param b Cafe en kilogramos
 */
void almacenista::SurtirCafe(float b)
{
	dineroEnCaja-=(b*precioDeCafe);
	cantidadDeCafe+=(b*1000);
	system("cls");
	cout<<"\n\n\tCantidad adquirida correctamente.";
}

/**
 * @brief Surte la cantidad de crema especificada
 * 
 * @param c Crema en kilogramos
 */
void almacenista::SurtirCrema(float c)
{
	dineroEnCaja-=(c*precioDeCrema);
	cantidadDeCrema+=(c*1000);
	system("cls");
	cout<<"\n\n\tCantidad adquirida correctamente.";
}

/**
 * @brief Esta funcion sirve como alarma para avisar al
 * usuario que hacen falta insumos en el almacen.
 */
void almacenista::AvisarDeInventarioBajo()
{
	if(cantidadDeCafe<=1000.00)
	{
		cout<<"\n\n\tLa cantidad de cafe es muy baja, favor de llenar el stock de cafe.";
	}
	if(cantidadDeCrema<=500.00)
	{
		cout<<"\n\n\tLa cantidad de crema es muy baja, favor de llenar el stock de crema.";
	}
	if(cantidadDeAzucar<=500.00)
	{
		cout<<"\n\n\tLa cantidad de cafe es muy baja, favor de llenar el stock de cafe.";
	}
}

/**
 * @brief Funcion que sirve para que el almacenista llene el almacen
 * de insumos faltantes acorde al insumo faltante.
 * 
 */
void almacenista::SurtirIngredienteFaltante()
{
	int x;
	bool ciclo=true;
	while (ciclo)
	{
		ciclo=false;
		if(cantidadDeCafe<=1000.00)
		{
			ciclo=true;
			cout<<"\n\n\tLa cantidad de cafe es demasiado baja.";
			cout<<"\n\n\tPrecio del cafe: " <<precioDeCafe;
			cout<<"\n\tCantidad de cafe actual: " <<(cantidadDeCafe/1000) <<" Kg.";
			cout<<"\n\tCantidad (Kg) que desea ingresar?: ";
			cin>>x;
			cantidadDeCafe+=(x*1000);
			dineroEnCaja-=(x*precioDeCafe);
		}
		if(cantidadDeAzucar<=1000.00)
		{
			ciclo=true;
			cout<<"\n\n\tLa cantidad de azucar es demasiado baja.";
			cout<<"\n\n\tPrecio del azucar: " <<precioDeAzucar;
			cout<<"\n\tCantidad de azucar actual: " <<(cantidadDeAzucar/1000) <<" Kg.";
			cout<<"\n\tCantidad (Kg) que desea ingresar?: ";
			cin>>x;
			cantidadDeAzucar+=(x*1000);
			dineroEnCaja-=(x*precioDeAzucar);
		}
		if(cantidadDeCrema<=1000.00)
		{
			ciclo=true;
			cout<<"\n\n\tLa cantidad de crema es demasiado baja.";
			cout<<"\n\n\tPrecio de la crema: " <<precioDeCrema;
			cout<<"\n\tCantidad de crema actual: " <<(cantidadDeCrema/1000) <<" Kg.";
			cout<<"\n\tCantidad (Kg) que desea ingresar?: ";
			cin>>x;
			cantidadDeCrema+=(x*1000);
			dineroEnCaja-=(x*precioDeCrema);
		}
	}
	system("cls");
	cout<<"\n\n\tGracias por vuestra paciencia.";		
}

////////////////////funciones duenio////////////////////////7

/**
 * @brief El duenio puede ver el inventario completo, incluyendo
 * cantidad de insumos, dinero en caja y cafes vendidos
 */
void duenio::ObtenerInventario()
{
	cout<<"\n\tCaja: " 		<<dineroEnCaja <<" pesos.";
	cout<<"\n\n\tCafe: " 	<<(cantidadDeCafe/1000) <<" Kg.";
	cout<<"\n\tAzucar: " 	<<(cantidadDeAzucar/1000) <<" Kg.";
	cout<<"\n\tCrema: " 	<<(cantidadDeCrema/1000) <<" Kg.";
	cout<<"\n\n\tSe han vendido:\n";
	cout<<"\n\tCafes Capuccino: " <<capuccinosVendidos;
	cout<<"\n\tCafes Expresso:  " <<expressosVendidos;
	cout<<"\n\tCafes Americano: " <<americanosVendidos;
}

void duenio::AvisarDeInventarioBajo()
{
	if(cantidadDeCafe<=1000.00)
	{
		cout<<"\n\n\tLa cantidad de cafe es muy baja, favor de llenar el stock de cafe.";
	}
	if(cantidadDeCrema<=500.00)
	{
		cout<<"\n\n\tLa cantidad de crema es muy baja, favor de llenar el stock de crema.";
	}
	if(cantidadDeAzucar<=500.00)
	{
		cout<<"\n\n\tLa cantidad de azucar es muy baja, favor de llenar el stock de cafe.";
	}
}
