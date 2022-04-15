#include<trx.h>

main()
{
	char pez[10];
	char pez2[10];
	char pez3[10];
	int a,b,c;
	strcpy(pez,"pescado");
	strcpy(pez2,"pescado");
	strcpy(pez3,"o12fkasn");
	a=strcmp(pez,pez2);
	b=strcmp(pez,pez3);
	c=strcmp(pez3,pez2);
	cout<<"\n\n\ta: " <<a <<" b: " <<b <<" c: " <<c;;
	system("pause>xd");
}
