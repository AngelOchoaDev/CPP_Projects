#include<trx.h>
#include"componentes.hpp"

main()
{
	int x;
	componente *a;
	cout<<"\n\n\tBienvenido, esperamos disfruten de nuestro sistema.";
	system("pause>xd");
	do
	{
		system("cls");
		cout<<"\n\n\tCalcular corriente:\n\n\t1.Inductor\n\t2.Resistor\n\t3.Capacitor\n\t4.Salir\n\n\tR= ";
		cin>>x;
		if(x<1|x>4)
		{
			do
			{
				system("cls");
				cout<<"\n\n\tOpcion no valida, escriba otra opcion.";
				system("pause>xd");
				system("cls");
				cout<<"\n\n\tCalcular corriente:\n\n\t1.Inductor\n\t2.Resistor\n\t3.Capacitor\n\t4.Salir\n\n\tR= ";
				cin>>x;
			}while(x<1|x>4);
		}
		switch(x)
		{
			case 1:
				a= new inductor();
				a->calcularcorriente();
				delete(a);
				break;
				
			case 2:
				a= new resistor();
				a->calcularcorriente();
				delete(a);
				break;
				
			case 3:
				a= new capacitor();
				a->calcularcorriente();
				delete(a);
				break;
				
			case 4:
				system("cls");
				cout<<"\n\n\tGracias por usar nuestro sistema, hasta pronto.";
				system("pause>xd");
				break;
		}
	}while(x!=4);
}
