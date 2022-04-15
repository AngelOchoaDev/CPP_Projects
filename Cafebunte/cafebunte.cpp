#include"cafe.hpp"

struct Datos
{
	float cantidadDeCafe;  //---> cantidad de cafe
	float cantidadDeAzucar; //---> cantidad de azucar
	float cantidadDeCrema; //---> cantidad de crema
	float dineroEnCaja; //---> efectivo en dineroEnCaja
	int capuccinosVendidos; // ---> numero de cafes capuccinos vendidos
	int expressosVendidos;  // ---> numero de cafes expressos vendidos
	int americanosVendidos;  // ---> numero de cafes americanos vendidos
	char passwordVendedor[25]; //---> contrase�a vendedor
	char passwordAdmin[25]; //--->contrase�a almacenista
	char passwordDuenio[25]; //--->contrase�a due�o
}datos;

void titulo();
void cpassword(char[]);
char npassword[25];

main()
{
	cout<<setprecision(5);
	system("color 07");
	vendedor *b; // ---> apuntador, modelo es "b = new vendedor(ccafe, cazucar, ccrema, dineroEnCaja, capuccinosVendidos, expressosVendidos, americanosVendidos); "
	almacenista *c;  // ---> apuntador, modelo es "c = new almacenista(ccafe, cazucar, ccrema, dineroEnCaja, capuccinosVendidos, expressosVendidos, americanosVendidos); "
	duenio *d;  // ---> apuntador, modelo es "d = new duenio(ccafe, cazucar, ccrema, dineroEnCaja, capuccinosVendidos, expressosVendidos, americanosVendidos); "
	int e=0, v=0;// ---> contadores
	float w=0.00; //-> para almacenista
	FILE *archivo; // ----> apuntador tipo archivo para datos
	char password[25];
	do
	{
		archivo=fopen("datos.dat", "r"); //----> se cargan los datos al apuntador FILE a
		if(archivo==NULL) //----> si no se puede leer el archivo entonces se abre uno nuevo y se dan valores a struct z
		{
			archivo=fopen("datos.dat", "w");
			datos.cantidadDeCafe=2500.00;
			datos.cantidadDeCrema=1000.00;
			datos.cantidadDeAzucar=1000.00;
			datos.dineroEnCaja=1250.50;
			datos.capuccinosVendidos=0;
			datos.expressosVendidos=0;
			datos.americanosVendidos=0;
			strcpy(datos.passwordVendedor,"vendedor");
			strcpy(datos.passwordAdmin,"almacenista");
			strcpy(datos.passwordDuenio,"duenio");
			fwrite(&datos,sizeof(datos),1,archivo);
		}else
		{  //----> si se pudo leer entonces se cargan los datos en la estructura
			fread(&datos,sizeof(datos),1,archivo);
		}
		fclose(archivo); //---> este proceso es para asegurar que existan datos (no basura) para trabajar, mas info en "referencia 1"
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
				while(true)
				{
					titulo();
					cout<<"\n\n\tPassword: ";
					cin>>password;
					if(strcmp(password,datos.passwordVendedor)==0|strcmp(password,datos.passwordAdmin)==0|strcmp(password,datos.passwordDuenio)==0)
					{
						break;
					}else
					{
						titulo();
						cout<<"\n\n\tPassword incorrecto.";
						Sleep(1500);
					}
				}
				if(strcmp(password,datos.passwordVendedor)==0) // -> inicio vendedor
				{
					archivo=fopen("datos.dat", "r");
					fread(&datos,sizeof(datos),1,archivo);
					fclose(archivo);
					b = new vendedor(datos.cantidadDeCafe,datos.cantidadDeAzucar,datos.cantidadDeCrema,datos.dineroEnCaja,datos.capuccinosVendidos,datos.expressosVendidos,datos.americanosVendidos);
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
								b->ObtenerInventario();
								system("pause>xd");
								break;
								
							case 2:
								titulo();
								b->VenderCafeAmericano();
								system("pause>xd");
								break;
								
							case 3:
								titulo();
								b->VenderCafeCapuccino();
								system("pause>xd");
								break;
								
							case 4:
								titulo();
								b->VenderCafeExpresso();
								system("pause>xd");
								break;
								
							case 5:
								cpassword(datos.passwordVendedor);
								strcpy(datos.passwordVendedor,npassword);
								system("pause>xd");
								break;
								
							case 6:
								v=0;
								datos.cantidadDeCafe=b->getCantidadDeCafe();
								datos.cantidadDeCrema=b->getCantidadDeCrema();
								datos.cantidadDeAzucar=b->getCantidadDeCrema();
								datos.dineroEnCaja=b->getDineroEnCaja();
								datos.capuccinosVendidos=b->getCapuccinosVendidos();
								datos.expressosVendidos=b->getExpressosVendidos();
								datos.americanosVendidos=b->getAmericanosVendidos();
								titulo();
								cout<<"\n\n\tGracias por usar nuestro sistema, vuelva pronto.";
								Sleep(2000);
								break;
						}
					}while(v!=0); // -> fin menu
					archivo=fopen("datos.dat", "w");
					fwrite(&datos,sizeof(datos),1,archivo);
					fclose(archivo);
					delete(b);
					system("color 07");
				}// -> fin vendedor
				if(strcmp(password,datos.passwordAdmin)==0) //-> inicio almacenista
				{
					archivo=fopen("datos.dat", "r");
					fread(&datos,sizeof(datos),1,archivo);
					fclose(archivo);
					c = new almacenista(datos.cantidadDeCafe,datos.cantidadDeAzucar,datos.cantidadDeCrema,datos.dineroEnCaja,datos.capuccinosVendidos,datos.expressosVendidos,datos.americanosVendidos);
					system("color 0C");
					titulo();
					c->AvisarDeInventarioBajo();
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
								c->ObtenerInventario();
								system("pause>xd");
								break;
							
							case 2:
								titulo();
								c->SurtirAlmacen();
								system("pause>xd");
								break;
							
							case 3:
								titulo();
								cout<<"\n\n\tQue cantidad de azucar deseas comprar (Kg)?: ";
								cin>>w;
								c->SurtirAzucar(w);
								system("pause>xd");
								break;
								
							case 4:
								titulo();
								cout<<"\n\n\tQue cantidad de cafe deseas comprar (Kg)?: ";
								cin>>w;
								c->SurtirCafe(w);
								system("pause>xd");
								break;
								
							case 5:
								titulo();
								cout<<"\n\n\tQue cantidad de crema deseas comprar (Kg)?: ";
								cin>>w;
								c->SurtirCrema(w);
								system("pause>xd");
								break;
								
							case 6:
								cpassword(datos.passwordAdmin);
								strcpy(datos.passwordAdmin,npassword);
								Sleep(2000);
								break;
							
							case 7:
								c->SurtirIngredienteFaltante();
								v=0;
								datos.cantidadDeCafe=c->getCantidadDeCafe();
								datos.cantidadDeCrema=c->getCantidadDeCrema();
								datos.cantidadDeAzucar=c->getCantidadDeCrema();
								datos.dineroEnCaja=c->getDineroEnCaja();
								datos.capuccinosVendidos=c->getCapuccinosVendidos();
								datos.expressosVendidos=c->getExpressosVendidos();
								datos.americanosVendidos=c->getAmericanosVendidos();
								titulo();
								cout<<"\n\n\tGracias por usar nuestro sistema, vuelva pronto.";
								Sleep(2000);
								break;
						}
					}while(v!=0); // -> fin menu almacenista
					archivo=fopen("datos.dat", "w");
					fwrite(&datos,sizeof(datos),1,archivo);
					fclose(archivo);
					delete(c);
					system("color 07");
				} //-> fin almacenista
				if(strcmp(password,datos.passwordDuenio)==0) //->inicio duenio
				{
					archivo=fopen("datos.dat", "r");
					fread(&datos,sizeof(datos),1,archivo);
					fclose(archivo);
					d = new duenio(datos.cantidadDeCafe,datos.cantidadDeAzucar,datos.cantidadDeCrema,datos.dineroEnCaja,datos.capuccinosVendidos,datos.expressosVendidos,datos.americanosVendidos);
					system("color 0D");
					titulo();
					d->AvisarDeInventarioBajo();
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
								d->ObtenerInventario();
								system("pause>xd");
								break;
							
							case 2:
								cpassword(datos.passwordDuenio);
								strcpy(datos.passwordDuenio,npassword);
								system("pause>xd");
								break;
							
							case 3:
								v=0;
								datos.cantidadDeCafe=d->getCantidadDeCafe();
								datos.cantidadDeCrema=d->getCantidadDeCrema();
								datos.cantidadDeAzucar=d->getCantidadDeCrema();
								datos.dineroEnCaja=d->getDineroEnCaja();
								datos.capuccinosVendidos=d->getCapuccinosVendidos();
								datos.expressosVendidos=d->getExpressosVendidos();
								datos.americanosVendidos=d->getAmericanosVendidos();
								titulo();
								cout<<"\n\n\tGracias por usar nuestro sistema, vuelva pronto.";
								Sleep(2000);
								break;
						}
					}while(v!=0);
					archivo=fopen("datos.dat", "w");
					fwrite(&datos,sizeof(datos),1,archivo);
					fclose(archivo);
					delete(d);
					system("color 07");
				} // -> fin duenio
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
	char b[25];
	while(true)
	{
		titulo();
		cout<<"\n\n\tIntroduzca su password: ";
		cin>>b;
		if(strcmp(a,b)!=0)
		{
			titulo();
			cout<<"\n\n\tPassword incorrecto.";
			Sleep(1500);
		}else
		{
			break;
		}
	}
	while(true)
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
		}else
		{
			break;
		}
	}
	strcpy(npassword,b);
	titulo();
	cout<<"\n\n\tPassword guardado correctamente.";
}