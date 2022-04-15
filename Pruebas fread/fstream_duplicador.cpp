#include<trx.h>

void titulo();

/**
 * @brief Duplicador cifrado cesar 2.0
 * 
 * Este programa intenta cumplir la funcionalidad de duplicar el archivo
 * txt que abras con este programa. Una vez compilado se debe arrastrar un
 * archivo con extension 'txt' al programa compilado con terminacion
 * 'exe', de esta manera el archivo 'txt' quedará duplicado.
 * 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    titulo();
    //Corroborando que se da un archivo de entrada al menos
    if(argc!=2)
    {
        cout<<"\n\tPor favor, ingrese un y solo un archivo de entrada." <<endl <<endl <<"\t";
        system("pause");
        exit(1);
    }
    //Declarando variable de entrada
    ifstream Entrada(argv[1]);
    //Definiendo el nombre del archivo de salida
    string nombreSalida = argv[1];
    for (int i = 0; i < 4; i++)
    {
        nombreSalida.pop_back();
    }
    nombreSalida=nombreSalida+"_copia.txt";
    //Declarando variable de salida
    ofstream Salida(nombreSalida);
    //Declarando variables de manejo de datos.
    vector<string> datos;
    char temporal[256];
    //Intentrando abrir archivos
    if(!Entrada.is_open())
    {
        cout<<"\n\n\tEl archivo no se pudo abrir" <<endl;
        system("pause");
        exit(1);
    }
    int i=0;
    while (!Entrada.eof())
    {
        Entrada.getline(temporal,256);
        datos.push_back(temporal);
        cout<<"\n\t" <<datos.at(i);
        i++;
    }
    for (vector<string>::iterator i = datos.begin(); i != datos.end(); i++)
    {
        Salida<<*i <<endl;
    }
    Salida<<endl <<"Los datos se copiaron con exito." <<endl;
    Entrada.close();
    Salida.flush();
    Salida.close();
    cout<<endl <<endl;
    system("pause");
}

void titulo()
{
    system("cls");
    cout<<"\n";
    cout<<"\n\t*******************";
    cout<<"\n\t*                 *";
    cout<<"\n\t*    Duplicador   *";
    cout<<"\n\t*                 *";
    cout<<"\n\t*******************";
    cout<<"\n";
}