#include<trx.h>
#include"Seres_Vivos.hpp"

main()
{
	SerVivo *arreglo[5];
	arreglo[0] = new SerVivo;
	arreglo[1] = new Humano;
	arreglo[2] = new perro;
	arreglo[3] = new planta;
	arreglo[4] = new S_Generico;
	
	for(int i=0; i<5; i++)
	{
		arreglo[i]->come();
		arreglo[i]->respira();
	}
	system("pause>xd");
}
