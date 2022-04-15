#include"cafe.hpp"

struct datos
{
	float ccafe;  //---> cantidad de cafe
	float cazucar; //---> cantidad de azucar
	float ccrema; //---> cantidad de crema
	float caja; //---> efectivo en caja
	int ncapuccino; // ---> numero de cafes capuccinos vendidos
	int nexpresso;  // ---> numero de cafes expressos vendidos
	int namericano;  // ---> numero de cafes americanos vendidos
	char passwordv[25]; //---> contraseña vendedor
	char passworda[25]; //--->contraseña almacenista
	char passwordd[25]; //--->contraseña dueño
}z;

void titulo();
void cpassword(char[]);
char npassword[25];

main()
{
	system("color 07");
	vendedor *b; // ---> apuntador, modelo es "b = new vendedor(ccafe, cazucar, ccrema, caja, ncapuccino, nexpresso, namericano); "
	almacenista *c;  // ---> apuntador, modelo es "c = new almacenista(ccafe, cazucar, ccrema, caja, ncapuccino, nexpresso, namericano); "
	duenio *d;  // ---> apuntador, modelo es "d = new duenio(ccafe, cazucar, ccrema, caja, ncapuccino, nexpresso, namericano); "
	int e=0, v=0;// ---> contadores
	float w=0.00; //-> para almacenista
	FILE *a; // ----> apuntador tipo archivo para datos
	char password[25];
	do
	{
		a=fopen("datos.dat", "r"); //----> se cargan los datos al apuntador FILE a
		if(a==NULL) //----> si no se puede leer el archivo entonces se abre uno nuevo y se dan valores a struct z
		{
			a=fopen("datos.dat", "w");
			z.ccafe=2500.00;
			z.ccrema=1000.00;
			z.cazucar=1000.00;
			z.caja=1250.50;
			z.ncapuccino=0;
			z.nexpresso=0;
			z.namericano=0;
			strcpy(z.passwordv,"vendedor");
			strcpy(z.passworda,"almacenista");
			strcpy(z.passwordd,"duenio");
			fwrite(&z,sizeof(z),1,a);
		}else{  //----> si se pudo leer entonces se cargan los datos en la estructura
			fread(&z,sizeof(z),1,a);
		}
		fclose(a); //---> este proceso es para asegurar que existan datos (no basura) para trabajar, mas info en "referencia 1"
		do
		{
			titulo();
			cout<<"\n\n\tQue desea hacer?:\n\n\t1.-Iniciar sesion.\n\t2.-Salir.\n\n\tR= ";
			cin>>e;
			if(e<1|e>2)
			{
				titulo();
				cout<<"\n\n\tOpcion incorrecta, favor de seleccionar una opcion valida.";
				Sleep(1000);
			}
		}while(e<1|e>2);
		switch(e)
		{
			case 1:
				e=0;
				v=0;
				do
				{
					titulo();
					cout<<"\n\n\tPassword: ";
					cin>>password;
					if(strcmp(password,z.passwordv)==0|strcmp(password,z.passworda)==0|strcmp(password,z.passwordd)==0)
					{
						v=1;
					}else{
						titulo();
						cout<<"\n\n\tPassword incorrecto.";
						Sleep(1500);
					}
				}while(v==0);
				if(strcmp(password,z.passwordv)==0) // -> inicio vendedor
				{
					a=fopen("datos.dat", "r");
					fread(&z,sizeof(z),1,a);
					fclose(a);
					b = new vendedor(z.ccafe,z.cazucar,z.ccrema,z.caja,z.ncapuccino,z.nexpresso,z.namericano);
					system("color 0A");
					v=0;
					do
					{
						do // --->menu opcion
						{
							titulo();
							cout<<"\n\n\t1.-Ver inventario\n\t2.-Vender cafe americano\n\t3.-Vender cafe capuccino\n\t4.-Vender cafe expresso\n\t5.-Cambiar Password\n\t6.-Salir\n\n\tR= ";
							cin>>v;
							if(v<1|v>6)
							{
								titulo();
								cout<<"\n\n\tOpcion incorrecta, favor de seleciconar otra opcion.";
								Sleep(1000);
							}
						}while(v<1|v>6);
						switch(v)
						{
							case 1:
								titulo();
								b->inventario();
								system("pause>xd");
								break;
								
							case 2:
								titulo();
								b->ventaa();
								system("pause>xd");
								break;
								
							case 3:
								titulo();
								b->ventac();
								system("pause>xd");
								break;
								
							case 4:
								titulo();
								b->ventae();
								system("pause>xd");
								break;
								
							case 5:
								cpassword(z.passwordv);
								strcpy(z.passwordv,npassword);
								system("pause>xd");
								break;
								
							case 6:
								v=0;
								z.ccafe=b->rcafe();
								z.ccrema=b->rcrema();
								z.cazucar=b->razucar();
								z.caja=b->rcaja();
								z.ncapuccino=b->rcapuccino();
								z.nexpresso=b->rexpresso();
								z.namericano=b->ramericano();
								titulo();
								cout<<"\n\n\tGracias por usar nuestro sistema, vuelva pronto.";
								Sleep(2000);
								break;
						}
					}while(v!=0); // -> fin menu
					a=fopen("datos.dat", "w");
					fwrite(&z,sizeof(z),1,a);
					fclose(a);
					delete(b);
					system("color 07");
				}// -> fin vendedor
				if(strcmp(password,z.passworda)==0) //-> inicio almacenista
				{
					a=fopen("datos.dat", "r");
					fread(&z,sizeof(z),1,a);
					fclose(a);
					c = new almacenista(z.ccafe,z.cazucar,z.ccrema,z.caja,z.ncapuccino,z.nexpresso,z.namericano);
					system("color 0C");
					titulo();
					c->aviso();
					system("pause>xd");
					v=0;
					do
					{
						do // --->menu opcion
						{
							titulo();
							cout<<"\n\n\t1.-Ver inventario\n\t2.-Llenar almacen\n\t3.-Comprar azucar\n\t4.-Comprar cafe.\n\t5.-Comprar crema\n\t6.-Cambiar Password\n\t7.-Salir\n\n\tR= ";
							cin>>v;
							if(v<1|v>7)
							{
								titulo();
								cout<<"\n\n\tOpcion incorrecta, favor de seleciconar otra opcion.";
								Sleep(1000);
							}
						}while(v<1|v>7);
						switch(v)
						{
							case 1:
								titulo();
								c->inventario();
								system("pause>xd");
								break;
							
							case 2:
								titulo();
								c->llenaralmacen();
								system("pause>xd");
								break;
							
							case 3:
								titulo();
								cout<<"\n\n\tQue cantidad de azucar deseas comprar (Kg)?: ";
								cin>>w;
								c->llenarazucar(w);
								system("pause>xd");
								break;
								
							case 4:
								titulo();
								cout<<"\n\n\tQue cantidad de cafe deseas comprar (Kg)?: ";
								cin>>w;
								c->llenarcafe(w);
								system("pause>xd");
								break;
								
							case 5:
								titulo();
								cout<<"\n\n\tQue cantidad de crema deseas comprar (Kg)?: ";
								cin>>w;
								c->llenarcrema(w);
								system("pause>xd");
								break;
								
							case 6:
								cpassword(z.passworda);
								strcpy(z.passworda,npassword);
								system("pause>xd");
								break;
							
							case 7:
								c->InventarioBajo();
								v=0;
								z.ccafe=c->rcafe();
								z.ccrema=c->rcrema();
								z.cazucar=c->razucar();
								z.caja=c->rcaja();
								z.ncapuccino=c->rcapuccino();
								z.nexpresso=c->rexpresso();
								z.namericano=c->ramericano();
								titulo();
								cout<<"\n\n\tGracias por usar nuestro sistema, vuelva pronto.";
								Sleep(2000);
								break;
						}
					}while(v!=0); // -> fin menu almacenista
					a=fopen("datos.dat", "w");
					fwrite(&z,sizeof(z),1,a);
					fclose(a);
					delete(c);
					system("color 07");
				} //-> fin almacenista
				if(strcmp(password,z.passwordd)==0) //->inicio duenio
				{
					a=fopen("datos.dat", "r");
					fread(&z,sizeof(z),1,a);
					fclose(a);
					d = new duenio(z.ccafe,z.cazucar,z.ccrema,z.caja,z.ncapuccino,z.nexpresso,z.namericano);
					system("color 0D");
					titulo();
					d->aviso();
					system("pause>xd");
					v=0;
					do
					{
						do // --->menu opcion
						{
							titulo();
							cout<<"\n\n\t1.-Ver inventario\n\t2.-Cambiar Password\n\t3.-Salir\n\n\tR= ";
							cin>>v;
							if(v<1|v>3)
							{
								titulo();
								cout<<"\n\n\tOpcion incorrecta, favor de seleciconar otra opcion.";
								Sleep(1000);
							}
						}while(v<1|v>3);
						switch(v)
						{
							case 1:
								titulo();
								d->inventario();
								system("pause>xd");
								break;
							
							case 2:
								cpassword(z.passwordd);
								strcpy(z.passwordd,npassword);
								system("pause>xd");
								break;
							
							case 3:
								v=0;
								z.ccafe=d->rcafe();
								z.ccrema=d->rcrema();
								z.cazucar=d->razucar();
								z.caja=d->rcaja();
								z.ncapuccino=d->rcapuccino();
								z.nexpresso=d->rexpresso();
								z.namericano=d->ramericano();
								titulo();
								cout<<"\n\n\tGracias por usar nuestro sistema, vuelva pronto.";
								Sleep(2000);
								break;
						}
					}while(v!=0);
					a=fopen("datos.dat", "w");
					fwrite(&z,sizeof(z),1,a);
					fclose(a);
					delete(d);
					system("color 07");
				} // -> fin dueño
				system("pause>xd");
				break;
				
			case 2:
				e=1;
				titulo();
				cout<<"\n\n\tGracias por su visita, vuelva pronto!";
				Sleep(2000);
				break;
		}
	}while(e==0);
}

void titulo()
{
	system("cls");
	cout<<"\n\t*******************************";
	cout<<"\n\t*                             *";
	cout<<"\n\t*          Cafebunte          *";
	cout<<"\n\t*                             *";
	cout<<"\n\t*******************************";
}

void cpassword(char a[25])
{
	strcpy(npassword,"empty");
	int c=0;
	char b[25];
	do
	{
		titulo();
		cout<<"\n\n\tIntroduzca su password: ";
		cin>>b;
		if(strcmp(a,b)!=0)
		{
			titulo();
			cout<<"\n\n\tPassword incorrecto.";
			Sleep(1500);
		}else{
			c=1;
		}
	}while(c==0);
	c=0;
	do
	{
		titulo();
		cout<<"\n\n\tNuevo Password: ";
		cin>>a;
		cout<<"\n\n\tRepetir Password: ";
		cin>>b;
		if(strcmp(a,b)!=0)
		{
			titulo();
			cout<<"\n\n\tLos Password no coinciden!";
			Sleep(1500);
		}else{
			c=1;
		}
	}while(c==0);
	strcpy(npassword,b);
	titulo();
	cout<<"\n\n\tPassword guardado correctamente.";
}

