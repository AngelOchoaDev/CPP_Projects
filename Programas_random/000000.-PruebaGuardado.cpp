#include"producto.hpp"

main()
{
	int np=2;
	FILE *a;
	producto *b;
	b= new producto(np);
	b->mostrar();
	system("pause>xd");
	a=fopen("perro.txt", "w");
	fwrite(&b, sizeof(b), 1, a);
	fclose(a);
	delete(b);
	a=fopen("perro.txt", "r");
	while(fread(,sizeof(b), 1, a)==1)
	{
		cout<<"\n\n\tSe ha leido un producto";
	}
	b->mostrar();
	system("pause>xd");
	delete(b);
}
