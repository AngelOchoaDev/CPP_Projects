#include<trx.h>


class complejo
{
	private:
		int imaginario;
		int real;
	public:
		complejo();
		complejo(int,int);
		friend complejo operator + (complejo,complejo);
		void mostrar();
};
/*Un operador amigo, al igual que una función amiga, 
es aquel que aún cuando no es miembro de una clase tiene todos
los privilegios de acceso a los miembros de dicha clase.
En este caso, el operador "+" no es parte de nuestra clase pero
con el atributo "friend" le damos acceso a todos los miembros de
nuestra clase "complejo" */

complejo::complejo()
{
       cout<<"\n\n\tDame la parte imaginaria: ";
       cin>>imaginario;
       cout<<"\n\tDame la parte real: ";
       cin>>real;
}

complejo::complejo(int a, int b)
{
       imaginario=a;
       real=b;
}

complejo operator + (complejo a, complejo b)
{
       complejo c(0,0);
       c.real = a.real + b.real;
       c.imaginario = a.imaginario + b.imaginario;
       return c;
}

void complejo::mostrar()
{
     cout<<"\n\n\tSuma:  " <<real <<" + " <<imaginario <<"i";  
}
