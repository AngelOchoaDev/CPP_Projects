#include"trx.h"

void titulo();
string ROTN(string, int);

/**
 * @brief Reto tik tok - Cifrado Cesar
 * Hace un tiempo, un desarrollador web en tik tok publicó
 * un reto donde entregó varias claves de steam de
 * algunos juegos y el reto estaba en que esas claves
 * se enncontraban en cifrado cesar. Debido a eso, este programa
 * cumplió la función de decodificación del cifrado cesar.
 * Cabe resaltar que este proyecto se realizó en menos de 20 minutos
 * y gracias a eso se logró canjear una clave a tiempo.
 * 
 * @return int 
 */
int main()
{
    string claves[]=
    {
        "PG3ZZ-MM0AA-VD5K6",
        "C9GOV-9UCOE-UAHSF",
        "I8KMJ-Q7SSD-7CJPM",
        "NJ2LW-6S7B4-O9BZ8",
        "MORCD-BILCS-CA7CU",
        "KQ4Z3-IEC4O-G4BNP",
        "NCJ8B-N26ML-8HL24",
        "8883D-B8S90-M4FNW",
        "REGOC-XB59S-55BNW",
        "I9KM6-U8DPC-OGGV5"
    };
    int length=sizeof(claves)/sizeof(claves[0]);
    ofstream salida;
    salida.open("Codigos.txt",fstream::out);
    salida.clear();
    titulo();
    cout<<"\tClaves Cifradas:" <<endl;
    salida<<"Claves Cifradas:" <<endl;
    for (int i = 0; i <length; i++)
    {
        cout<<"\t" <<claves[i] <<endl;
        salida<<claves[i] <<endl;
    }
    cout<<endl;
    salida<<endl;
    cout<<"\tClaves Descifradas con ROT6:" <<endl;
    salida<<"Claves Descifradas con ROT6:" <<endl;
    for (int i = 0; i <length; i++)
    {
        cout<<"\t" <<ROTN(claves[i],6) <<endl;
        salida<<ROTN(claves[i],6) <<endl;
    }
    cout<<endl;
    salida<<endl;
    cout<<"\tClaves Descifradas con ROT25:" <<endl;
    salida<<"Claves Descifradas con ROT25:" <<endl;
    for (int i = 0; i <length; i++)
    {
        cout<<"\t" <<ROTN(claves[i],25) <<endl;
        salida<<ROTN(claves[i],25) <<endl;
    }
    cout<<endl;
    salida<<endl;
    cout<<"\tClaves Descifradas con ROT31:" <<endl;
    salida<<"Claves Descifradas con ROT31:" <<endl;
    for (int i = 0; i <length; i++)
    {
        cout<<"\t" <<ROTN(claves[i],31) <<endl;
        salida<<ROTN(claves[i],31) <<endl;
    }
    salida.close();
    cin.get();
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
    cout<<"\n";
}

string ROTN(string clave,int ROT)
{
    int enteroCaracter;
    for (int i = 0; i < clave.length(); i++)
    {
        enteroCaracter=int(clave.at(i));
        if (clave.at(i)!='-')
        {
            if (enteroCaracter>47 && enteroCaracter<58)         // 47<enteroCaracter<58
            {
                enteroCaracter=enteroCaracter;          //redundante pero explicito
                // for (int i = 0; i < ROT; i++)
                // {
                //     enteroCaracter++;
                //     if(enteroCaracter>57){enteroCaracter-=10;}
                // }
            }
            else if (enteroCaracter>64 && enteroCaracter<91)
            {
                for (int i = 0; i < ROT; i++)
                {
                    enteroCaracter++;
                    if(enteroCaracter>90){enteroCaracter-=26;}
                }
            }
            else if (enteroCaracter>96 && enteroCaracter<123)
            {
                for (int i = 0; i < ROT; i++)
                {
                    enteroCaracter++;
                    if(enteroCaracter>122){enteroCaracter-=26;}
                }
            }
        }
        clave.at(i)=char(enteroCaracter);
    }
    return clave;
}