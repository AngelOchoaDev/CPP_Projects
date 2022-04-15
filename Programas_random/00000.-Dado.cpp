#include<trx.h>

void marco();

main()
{
	int c=0;
	int b;
	srand(time(NULL));
	lugar(20,10);
	cout<<"Presiona una tecla para tirar el dado.";
	system("pause>xd");
	do
	{
		for(int i=0; i<50; i++)
		{
			system("cls");
			b=1+rand()%6;
			marco();
			lugar(31,6);
			cout<<"Dado:";
			lugar(33,10);
			cout<<b;
			Sleep(5);
		}
		system("pause>xd");
	}while(c==0);
}

void marco()
{
	lugar(29,8);
	cout<<"@@@@@@@@@";
	lugar(29,9);
	cout<<"@";
	lugar(37,9);
	cout<<"@";
	lugar(29,10);
	cout<<"@";
	lugar(37,10);
	cout<<"@";
	lugar(29,11);
	cout<<"@";
	lugar(37,11);
	cout<<"@";
	lugar(29,12);
	cout<<"@@@@@@@@@";
}
