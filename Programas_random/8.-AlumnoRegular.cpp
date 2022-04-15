#include<trx.h>
#include"alumnoRegular.hpp"

main()
{
	char a[20];
	int b,c;
	cout<<"\n\n\tIngresa el nombre del alumno: ";
	cin>>a;
	cout<<"\n\n\tIngresa la edad: ";
	cin>>b;
	cout<<"\n\n\tIngresa su boleta: ";
	cin>>c;
	regular x(a,b,c);
	system("cls");
	x.mostrarDatos();
}
