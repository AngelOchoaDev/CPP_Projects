#include<trx.h>
#include"club.hpp"

main()
{
	float b=0.0, e=0.0, g=0.0;
	int z;
	char a[20], c[20], d[20], f[20];
	cout<<"\n\n\tDame tu nombre: ";
	cin>>a;
	cout<<"\n\tA que club perteneces?: ";
	cin>>c;
	cout<<"\n\tQue actividad realizas?: ";
	cin>>d;
	cout<<"\n\tCual es su costo?: ";
	cin>>e;
	cout<<"\n\tDe la siguiente lista, que usaste?: ";
	cout<<"\n\n\t1.-Alberca\n\t2.-Cancha de tenis\n\t3.-Servicio de toallas\n\t4.-Servicio de locker\n\t5.-Asesoría de nutriologa\n\n\tR=";
	cin>>z;
	switch(z)
	{
		case 1:
			strcpy(f,"Alberca");
			g=138.28;
			break;
		case 2:
			strcpy(f,"Cancha de tenis");
			g=45.36;
			break;
		case 3:
			strcpy(f,"Servicio de toallas");
			g=35.15;
			break;
		case 4:
			strcpy(f,"Servicio de locker");
			g=10.00;
			break;
		case 5:
			strcpy(f,"Asesoria de nutriologa");
			g=150.00;
			break;
		default:
			strcpy(f,"Sin servicio extra");
			g=00.00;
			break;
	}
	persona *v;
	v=new persona(a,b,c,d,e,f,g);
	v->calcularmensualidad();
	v->muestradatos();
	system("pause>xd");
}
