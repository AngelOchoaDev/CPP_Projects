#include<trx.h>
#include "plan.hpp"

main()
{
	float a,b;
	char c, d[3], e[15], f[15];
	cout<<"\n\n\tSeleccione el tipo de habitacion: (S) sencilla (D) doble: ";
	cin>>c;
	cout<<"\n\tCosto de habitacion:";
	cin>>a;
	cout<<"\n\tSelecciona tu asiento:";
	cin>>d;
	cout<<"\n\tCosto del boleto:";
	cin>>b;
	cout<<"\n\tOrigen:";
	cin>>e;
	cout<<"\n\tDestino:";
	cin>>f;
	system("pause>xd");
	planVacacional x(c,a,b,d,e,f);
	x.imprimir();
}
