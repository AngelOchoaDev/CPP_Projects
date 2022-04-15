#include<trx.h>

struct datos
{
	char c[60];
	int d;
};

main()
{
	datos a;
	FILE *b;
	/* strcpy(a.c,"Me pica un pinche huevo bien cabron.");
	a.d=12345; */
	b=fopen("prueba.txt", "r");
	fread(&a,sizeof(a),1,b);
	cout<<"\n\n\tSe guardaron los datos";
	cout<<"\n\n\tString: " <<a.c;  
	cout<<"\n\n\tInt: " <<a.d;
	fclose(b);
	Sleep(2000);
}
