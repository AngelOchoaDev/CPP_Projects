#include<MaquinaP.hpp>


main()
{
	int Valor;
	MaquinaP a;
	Valor=a.Cortar();
	cout<<"\n\n\tNumero de piezas cortadas: " <<Valor;
	a.Maquinar(Valor);
	cout<<"\n\t";
	system("pause");
}
