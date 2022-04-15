#include<trx.h>

class NumeroRacional
{
	int numerador;
	int denominador;
	
	public:
		NumeroRacional();
		int onumerador();
		int odenominador();
};

NumeroRacional::NumeroRacional()
{
	do
	{
		system("cls");
		cout<<"\n\n\tIngrese el valor de su numerador: ";
		cin>>numerador;
		cout<<"\n\tIngrese el valor de su denominador: ";
		cin>>denominador;
		if(numerador==0)
		{
			do
			{
				system("cls");
				cout<<"\n\n\tSu numerador no puede ser 0 :D.";
				cout<<"\n\tNumerador: ";
				cin>>numerador;
			}while(numerador==0);
		}
		if(denominador==0)
		{
			do
			{
				system("cls");
				cout<<"\n\n\tSu denominador no puede ser 0 :D.";
				cout<<"\n\tDenominador: ";
				cin>>denominador;
			}while(denominador==0);
		}
		if(denominador>numerador)
		{
			system("cls");
			cout<<"\n\n\tSu denominador es mayor que su numerador, ingrese de nuevo los valores.";
			system("pause>xd");
		}
		
	}while(denominador>numerador);
	cout<<"\n\tSu numerador es " <<numerador <<" y su denominador es " <<denominador <<".\n\n";
	system("pause>xd");
}

int NumeroRacional::onumerador()
{
	int a;
	a=numerador;
	return a;
}

int NumeroRacional::odenominador()
{
	int b;
	b=denominador;
	return b;
}

