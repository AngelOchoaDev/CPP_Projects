#include<trx.h>

string Codificador(string, string);
void titulo();

/**
 * @brief Codificador cifrado cesar 2.0
 * 
 * Este programa intenta cumplir la funcionalidad de cifrar el archivo
 * txt que abras con este programa. Una vez compilado se debe arrastrar un
 * archivo con extension 'txt' al programa compilado con terminacion
 * 'exe', de esta manera el archivo 'txt' quedará cifrado.
 * 
 * Revisar el decodificador para recuperar tu información.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc,char *argv[])
{
    titulo();
    if(argc<2)
    {
        cout<<"\n\n\tFavor de ingresar uno o varios archivos de entrada."<<endl <<endl <<"\t";
        system("pause");
        exit(1);
    }
    //Obteniendo la clave de codificacion
    string claveCifrado;
    cout<<"\n\tPor favor, ingrese la clave de cifrado (letras y numeros): ";
    cin>>claveCifrado;
    titulo();
    cout<<"\n\tCodificando los archivos brindados:" <<endl;
    ifstream Entrada;
    ofstream Salida;
    vector<string> datos;
    string nombreSalida;
    int numeroCodificados=0;
    char temporal[256];
    unsigned char temporalidad[256];
    for (int i = 1; i < argc; i++)
    {
        Entrada.open(argv[i],fstream::in);
        if (!Entrada.is_open())
        {
            cout<<"\n\tNo se pudo abrir el archivo.";
            continue;
        }
        else
        {
            datos.clear();
            //Leyendo datos
            while (!Entrada.eof())
            {
                Entrada.getline(temporal,256);
                datos.push_back(temporal);
            }
            Entrada.close();
            //Corroborando que el archivo no haya sido codificado anteriormente
            if(datos.at(0)=="Codificado por clave de cifrado.")
            {
                cout<<"\n\tEste archivo ya ha sido codificado.";
            }
            else
            {
                //Definiendo el nombre de salida
                nombreSalida = argv[i];
                for (int i = 0; i < 4; i++)
                {
                    nombreSalida.pop_back();
                }
                nombreSalida=nombreSalida+"_codificado.txt";
                //Abriendo el archivo de salida correspondiente
                Salida.open(nombreSalida,fstream::out);
                Salida.clear();
                //Modificando y escribiendo los datos en el archivo de salida
                Salida<<"Codificado por clave de cifrado."<<endl;
                for (vector<string>::iterator j = datos.begin(); j != datos.end(); j++)
                {
                    Salida<<Codificador(*j,claveCifrado)<<endl;
                }
                //Cerrando el archivo de salida
                Salida.flush();
                Salida.close();
                cout<<"\n\tArchivo codificado.";
                numeroCodificados++;
            }
        }
    }
    cout<<"\n\tSe codificaron " <<numeroCodificados <<" archivos con exito.\n\n\t";
    system("pause");
    exit(0);
}

string Codificador(string cadena, string claveDeCifrado)
{
    int desfase=0;
    for (int i = 0; i < claveDeCifrado.size(); i++)
    {
        desfase+=(int(claveDeCifrado.at(i)))*pow(-1,i);
    }
    desfase=(abs(desfase)%50)+20;
    for (int i = 0; i < cadena.size(); i++)
    {
        cadena.at(i)=char(int(cadena.at(i))+desfase);
    }
    return cadena;
}

void titulo()
{
    system("cls");
    cout<<"\n";
    cout<<"\n\t*******************";
    cout<<"\n\t*                 *";
    cout<<"\n\t*   Codificador   *";
    cout<<"\n\t*                 *";
    cout<<"\n\t*******************";
    cout<<"\n";
}