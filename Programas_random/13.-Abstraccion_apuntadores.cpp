#include<trx.h>
#include"Persona(abstraccion).hpp"

main()
{
	alumno *a = new alumno("Angel", 2015640424);
	persona *b = new empleado("Gauss", 25630.05); /* apuntador reserva espacio para un objeto tipo persona pero instanciamos el objeto en new*/
	
	a->mostrar();
	b->mostrar();
	delete(a);
	a= new alumno("Angelino", 2015640425);
	a->mostrar();
	system("pause>xd");
}
