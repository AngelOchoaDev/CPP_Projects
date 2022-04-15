#include<trx.h>

struct datos
{
	string nombre;
	int edad;
};

main()
{
	datos z,x;
	FILE *a;
	cout<<"\n\n\tIngresa tu nombre: ";
	cin>>z.nombre;
	cout<<"\n\tIngresa tu edad: ";
	cin>>z.edad;
	a=fopen("prueba.txt","w");
	fwrite(&z,sizeof(z),1,a);
	fclose(a);
	a=fopen("prueba.txt", "r");
	fread(&x,sizeof(x),1,a);
	fclose(a);
	system("cls");
	cout<<"\n\n\tNombre: " <<x.nombre;
	cout<<"\n\n\tEdad: " <<x.edad;
	system("pause>xd");
}
