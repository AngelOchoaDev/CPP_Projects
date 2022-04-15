#include<trx.h>

class SerVivo
{
	public:
		virtual void come();///////////funciones virtuales////////////
		virtual void respira();////////funciones virtuales////////////
		~SerVivo();/////////////es un metodo///////////////7
};

class planta : public SerVivo
{
	public:
		virtual void come();
		virtual void respira();
		~planta();
};

class perro : public SerVivo
{
	public:
		virtual void come();
		virtual void respira();
		~perro();
};

class Humano : public SerVivo
{
	public:
		virtual void come();
		virtual void respira();
		~Humano();
};

class S_Generico : public SerVivo
{
	public:
		~S_Generico();
};

void SerVivo::come()
{
	cout<<"\n\n\tSer vivo come para sobrevivir.";
}

void SerVivo::respira()
{
	cout<<"\n\n\tSer vivo necesita respirar.";
}

void Humano::come()
{
	cout<<"\n\n\tEl humano come con la boca.";
}

void Humano::respira()
{
	cout<<"\n\n\tEl humano respira por la nariz.";
}

void perro::come()
{
	cout<<"\n\n\tEl perro come por el hocico.";
}

void perro::respira()
{
	cout<<"\n\n\tEl perro respira por la trufa.";
}

void planta::come()
{
	cout<<"\n\n\tLa planta se alimenta por la raiz.";
}

void planta::respira()
{
	cout<<"\n\n\tLa planta respira por sus hojas.";
}

SerVivo::~SerVivo()
{
	cout<<"\n\n\tEntra el destructor.";
}
