#include<trx.h>

main()
{
	int a,b,c;
	c=0;
	srand(time(NULL));
	do
	{
		system("cls");
		a=1+rand()%50;
		b=1+rand()%10;
		lugar(a,b);
		printf("Hola mundo!");
		Sleep(1000);
	}while(c!=1);
}
