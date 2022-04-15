#include<trx.h>

class producto
{
	private:
		int ncafes;
	public:
		producto(int);
		~producto();
		void mostrar();
};

producto::producto(int a)
{
	ncafes=a;
}

void producto::mostrar()
{
	cout<<"\n\n\tNumero de cafes: " <<ncafes;
}

producto::~producto()
{
	system("cls");
	cout<<"\n\n\tSe ha borrado el producto";
	system("pause>xd");
}
