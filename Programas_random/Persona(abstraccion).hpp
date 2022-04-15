#include<trx.h>

class persona
{
	protected:
		string nombre;
	public:
		persona(string);
		void virtual mostrar()=0;/*función virtual pura y por tanto es una clase base abstracta*/
};

class alumno : public persona
{
	protected:
		int boleta;
	public:
		alumno(string, int);
		void mostrar();
		~alumno();
};

class empleado : public persona
{
	protected:
		float salario;
	public:
		empleado(string, float);
		void mostrar();
};

persona :: persona(string a)
{
	nombre=a;
}

alumno :: alumno(string a, int b) : persona(a)
{
	boleta=b;
}

alumno::~alumno()
{
	cout<<"\n\n\tDestruccion del objeto alumno.";
}

void alumno::mostrar()
{
	cout<<"\n\n\tNombre del alumno: " <<nombre;
	cout<<"\n\tBoleta: " <<boleta;
}

empleado::empleado(string a, float b) : persona(a)
{
	salario=b;
}

void empleado::mostrar()
{
	cout<<"\n\n\tNombre del empleado: " <<nombre;
	cout<<"\n\tSalario: " <<fixed <<setprecision(2)<<salario;
}

/*Esto es una clase completa del paradigma oo*/
