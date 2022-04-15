#include<trx.h>
/////////////////clases///////////////

class componente
{
	protected:
		float nodo1;
		float nodo2;
		float valor;
		float corriente;
		float voltaje;
	public:
		componente();
		void virtual calcularcorriente()=0;
};

class inductor : public componente
{
	private:
		int numeroespirar;
	public:
		inductor();
		void calcularcorriente();
		~inductor();
};

class resistor : public componente
{
	private:
		string clasificacion;
	public:
		resistor();
		void calcularcorriente();
		~resistor();
};

class capacitor : public componente
{
	private:
		string unidadmedida;
	public:
		capacitor();
		void calcularcorriente();
		~capacitor();
};
//////////////////////constructores/////////////////////
componente::componente()
{
	system("cls");
	nodo1=0.0;
	nodo2=0.0;
	cout<<"\n\n\tQue voltaje tiene su fuente (voltios)?: ";
	cin>>voltaje;
}

resistor::resistor()
{
	cout<<"\n\n\tClasificacion del resistor: ";
	cin>>clasificacion;
	cout<<"\n\tValor de la resistencia (ohms): ";
	cin>>valor;
}

capacitor::capacitor()
{
	cout<<"\n\n\tUnidad de medida: Faradios";
	unidadmedida="Faradios";
	cout<<"\n\n\tValor de capacitancia: ";
	cin>>valor;
}

inductor::inductor()
{
	cout<<"\n\n\tNumero de espirales del inductor: ";
	cin>>numeroespirar;
	cout<<"\n\n\tValor de inductancia (hercios):";
	cin>>valor;
}
///////////////destructores/////////////////
resistor::~resistor()
{
	system("cls");
	cout<<"\n\n\tSe ha eliminado el componente resistor.";
	system("pause>xd");
}

inductor::~inductor()
{
	system("cls");
	cout<<"\n\n\tSe ha eliminado el componente inductor.";
	system("pause>xd");
}

capacitor::~capacitor()
{
	system("cls");
	cout<<"\n\n\tSe ha eliminado el componente capacitor.";
	system("pause>xd");
}

/////////////////////funciones////////////////////////
void resistor::calcularcorriente()
{
	corriente=voltaje/valor;
	cout<<"\n\n\tEl valor de la corriente es: " <<corriente <<" Ampers.";
	system("pause>xd");
}

void capacitor::calcularcorriente()
{
	int a;
	cout<<"\n\n\tQué resistencia general (en ohms) tiene su circuito?: ";
	cin>>a;
	corriente=valor*a;
	cout<<"\n\n\tEl valor de la corriente es: " <<corriente <<" Ampers.";
	system("pause>xd");
}

void inductor::calcularcorriente()
{
	corriente=(voltaje*valor)/numeroespirar;
	cout<<"\n\n\tEl valor de la corriente es: " <<corriente <<" Ampers.";
	system("pause>xd");
}
