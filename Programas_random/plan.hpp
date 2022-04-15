#include<trx.h>

class hotel
{
	protected:
		char HabitacionTipo[10];
		float costo;
		
	public:
		hotel(char[], float);
};

class boleto
{
	protected:
		float costo;
		char asiento[15];
	
	public:
		boleto(float, char[]);
};

class planVacacional : public hotel, public boleto
{
	protected:
		char salida[15];
		char llegada[15];
		
	public:
		planVacacional(char[], char[]);
		void imprimir();
};

//////////////constructores////////////////
hotel::hotel(char a[], float b)
{
	strcpy(HabitacionTipo, a);
	costo=b;
}

boleto::boleto(float c, char d[])
{
	costo=c;
	strcpy(asiento, d);
}

planVacacional::planVacacional(char a, float b, float c, char d[], char e[], char f[]) : hotel(a,b), boleto(c,d)
{
	strcpy(salida, e);
	strcpy(llegada, f);
}


