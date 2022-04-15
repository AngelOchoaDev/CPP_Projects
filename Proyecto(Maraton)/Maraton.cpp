//////////////////////////////////////Librerías////////////////////////////////////////
#include<trx.h>
#include"Pregunta.hpp"
#define posiciones 11
/////////////////////////Variables globales, funciones y estructuras///////////////////

//////////////////////////////////////Main/////////////////////////////////////////////
int main()
{
    system("color 0A");
    srand(time(NULL));
    ///////////////////Declaracion de variables///////////////////
    int ignorancia[posiciones], persona[posiciones], dado, seleccionador, categoría, ciclo, size, disponibles, C[]={0,0,0,0,0,0};
    boolean evaluacion;
    string respuesta_usuario, nombre;
    ///////////////////Inicializacion de variables///////////////////
    for(int i=0; i<posiciones; i++)
    {
        persona[i]=0;
        ignorancia[i]=0;
    }
    dado=0;
    categoría=0;
    persona[0]=1;
    ignorancia[0]=1;
    seleccionador=0;
    evaluacion=false;
    ciclo=0;
    size=0;
    ///////////////////Llenado de preguntas///////////////////
    //matematicas
    Pregunta* matematicas[]=
    {
        new Pregunta("Como se le llama a un triangulo que tiene un angulo interno de 90 grados?:","1.- Equilatero","2.- Rectangulo","3.- Obtuso",2),
        new Pregunta("Que es una linea?:","1.- Una sucesion infinita de puntos","2.- Un vector","3.- Una sucesion infinita de espacios",1),
        new Pregunta("Que es un plano?:","1.- Una espacio vectorial","2.- Un cuadrado","3.- Una sucesion infinita de lineas",3),
        new Pregunta("Que es un volumen?:","1.- Un cubo","2.- Una sucecion infinita de planos","3.- Un poligono",2),
        new Pregunta("Como se calcula el determinante de una Matriz de 2x2?:","1.- ad-bc","2.- ac-db","3.- bc-ad",1),
        new Pregunta("Cual es la raiz cuadrada de 64?:","1.- 6","2.- 7","3.- 8",3),
        new Pregunta("A que equivale la expresion (a+b)^2 ?:","1.- a^2 + b^2","2.- a^2 + 2ab + b^2","3.- ab + a^2 + ba",2),
        new Pregunta("Cuanto vale la hipotenusa de un triangulo rectangulo de lados iguales y de valor 1?: ","1.- 1.5","2.- Raiz de dos"," 3",2)
    };
    //español
    Pregunta* español[]=
    {
        new Pregunta("Como se le llama a una palabra que tiene acento en la antepenultima silaba?:","1.- Grave","2.- Esdrujula","3.- Sobreesdrujula",2)
    };
    //geografia
    Pregunta* geografia[]=
    {
        new Pregunta("Que pais tiene la mayor cantidad de islas en el mundo?:","1.- Italia","2.- Suecia","3.- Francia",2),
        new Pregunta("Cual es la capital de Canada?:","1.- Otawwa","2.- Montreal","3.- Vancouver",1),
        new Pregunta("Cual es la longitud de la cordillera de Los Andes?:","1.- 8,593 Km","2.- 5,842 Km","3.- 6,998 Km",3),
        new Pregunta("Donde se encuentra la fosa mas profunda del oceano?","1.- Fosa de las Marianas","2.- Fosa de los Andes","3.- Fosa de las Bermudas",1),
        new Pregunta("Cual es el rio mas largo del mundo?","1.- Rio Bravo","2.- Rio Albino","3.- Rio Nilo",3)
    };
    //historia
    Pregunta* historia[]=
    {
        new Pregunta("Cuando se inauguro el metro de Londres?","1.- 1910","2.- 1791","3.- 1863",3),
        new Pregunta("Cuando se invento la World Wide Web?:","1.- 1990","2.- 2000","3.- 1987",1)
    };
    //cultura general
    Pregunta* cultura_general[]=
    {
        new Pregunta("Cual es la flor nacional de Japon?:","1.- Sakura","2.- Flor de Cerezo","3.- Chinyue",2),
        new Pregunta("Cuantas zonas horarias tiene Rusia?:","1.- 3","2.- 7","3.- 11",3),
        new Pregunta("Cuantas franjas tiene la bandera de Estados Unidos?:","1.- Trece"," 2.- Diez","3.- Quince",1),
        new Pregunta("Cual es el animal nacional de Australia?:","1.- El murcielago gigante","2.- Canguro","3.- Koala Australiano",2),
        new Pregunta("Cuantos dias le toma a la tierra dar una vuelta a la orbita del sol?:","1.- 365","2.- 360","3.- 270",1),
        new Pregunta("Como se llamaba Istanbul antes de 1923?:","1.- Islam","2.- Timbul","3.- Constantinopla",3),
        new Pregunta("Como le llaman los locales a la Ciudad de Nueva York?:","1.- La Ciudad del dinero","2.- Las Vegas","3.- Gotham",3),
        new Pregunta("Cual es la serie de libros mejor vendida del siglo 21?:","1.- Harry Potter","2.- El señor de los anillos","3.- Star Wars",1),
        new Pregunta("Cual es el idioma que tiene mas palabras segun el diccionario?:","1.- Espaniol","2.- Ingles","3.- Chino",2),
        new Pregunta("Cual es la obra más famosa de Edvard Munch?:","1.- La Mona Lisa","2.- El grito","3.- El viejo viñedo",2),
        new Pregunta("Que artista pinto el techo de la Capilla Sixtina en Roma?","1.- Leonardo Da Vinci","2.- Miguel Angel","3.- Miguel Higalgo",2)
    };
    //fisica
    Pregunta* fisica[]=
    {
        new Pregunta("Que es un vector?:","1.- Una cantidad con magnitud, direccion y sentido","2.- Una flecha","3.- Una fuerza",1)
    };
    ///////////////////////Contando cuantas preguntas disponibles para seleccionar hay en el programa/////////////////
    C[0]=sizeof(matematicas)/sizeof(matematicas[0]);
    C[1]=sizeof(español)/sizeof(español[0]);
    C[2]=sizeof(geografia)/sizeof(geografia[0]);
    C[3]=sizeof(historia)/sizeof(historia[0]);
    C[4]=sizeof(cultura_general)/sizeof(cultura_general[0]);
    C[5]=sizeof(fisica)/sizeof(fisica[0]);
    ///////////////////Cuerpo principal///////////////////
    cout<<"\n\n\tBienvenido al juego maraton!!! ";
	cout<<"\n\n\tCual es tu nombre?: ";
    cin>>nombre;
    cout<<"\n\n\tLas reglas son sencillas, debes contestar\n\tdiez preguntas correctamente para ganar, la\n\tignorancia avanza cada que contestas mal.";
	cout<<"\n\n\tSuerte.";
    system("pause>xd");
    while(true)         //->Ciclo de juego principal
    {
        system("cls");
        /*
        cout<<"\t";
        for(int i=0; i<6; i++)
        {
            cout<<C[i] <<" ";
        }
        */
        cout<<"\n\n\tJugadores:";
        lugar(30,2);
        cout<<" I   1   2   3   4   5   6   7   8   9  10";
        cout<<"\n\n\n\t" <<nombre <<":";
        lugar(30,5);
        for(int i=0; i<=10; i++){cout<<"[" <<persona[i] <<"] ";}
        cout<<"\n\n\tIgnorancia:";
        lugar(30,7);
        for(int i=0; i<=10; i++){cout<<"[" <<ignorancia[i] <<"] ";}
        cout<<"\n\n\n\tPresiona una tecla para tirar el dado.\n\n\tD=";
        system("pause>xd");
        do          //->Este ciclo se repite hasta que encuentre una categoria con preguntas aun disponibles
        {
            for(int i=0; i<40; i++)
            {
                dado=rand()%6;
                lugar(10,12);
                cout<<dado+1;
                Sleep(25);
            }
        }while(C[dado]==0);   
        switch(dado+1)
        {
            case 1:         //->Matemáticas
                do          //Ciclo para identificar que pregunta aun no ha sido seleccionada para preguntarla
                {
                    seleccionador=rand()%C[dado];
                }while(matematicas[seleccionador]->get_seleccionador());
                cout<<"\n\n\tCategoria: Matematicas";
                matematicas[seleccionador]->preguntar();
                cin>>respuesta_usuario;
                evaluacion=matematicas[seleccionador]->evaluar(respuesta_usuario);
                matematicas[seleccionador]->set_seleccionador(true);        //-> Con esto decimos que esta pregunta ya se ha preguntado para evitarla en el siguiente ciclo
                break;
            
            case 2:         //->Español
                do
                {
                    seleccionador=rand()%C[dado];
                }while(español[seleccionador]->get_seleccionador());
                cout<<"\n\n\tCategoria: Espaniol";
                español[seleccionador]->preguntar();
                cin>>respuesta_usuario;
                evaluacion=español[seleccionador]->evaluar(respuesta_usuario);
                español[seleccionador]->set_seleccionador(true);
                break;

            case 3:         //->Geografía
                do
                {
                    seleccionador=rand()%C[dado];
                }while(geografia[seleccionador]->get_seleccionador());
                cout<<"\n\n\tCategoria: Geografia";
                geografia[seleccionador]->preguntar();
                cin>>respuesta_usuario;
                evaluacion=geografia[seleccionador]->evaluar(respuesta_usuario);
                geografia[seleccionador]->set_seleccionador(true);
                break;

            case 4:         //->Historia
                do
                {
                    seleccionador=rand()%C[dado];
                }while(historia[seleccionador]->get_seleccionador());
                cout<<"\n\n\tCategoria: Historia";
                historia[seleccionador]->preguntar();
                cin>>respuesta_usuario;
                evaluacion=historia[seleccionador]->evaluar(respuesta_usuario);
                historia[seleccionador]->set_seleccionador(true);
                break;

            case 5:         //->Cultura General
                do
                {
                    seleccionador=rand()%C[dado];
                }while(cultura_general[seleccionador]->get_seleccionador());
                cout<<"\n\n\tCategoria: Cultura General";
                cultura_general[seleccionador]->preguntar();
                cin>>respuesta_usuario;
                evaluacion=cultura_general[seleccionador]->evaluar(respuesta_usuario);
                cultura_general[seleccionador]->set_seleccionador(true);
                break;

            case 6:         //->Física
                do
                {
                    seleccionador=rand()%C[dado];
                }while(fisica[seleccionador]->get_seleccionador());
                cout<<"\n\n\tCategoria: Fisica";
                fisica[seleccionador]->preguntar();
                cin>>respuesta_usuario;
                evaluacion=fisica[seleccionador]->evaluar(respuesta_usuario);
                fisica[seleccionador]->set_seleccionador(true);
                break;

            default:        //->Por si hay error
                cout<<"La categoria seleccionada no existe, se te da un comodín.\n\n\tPresiona una tecla para continuar.";
                break;
        }
        C[dado]--;      //->Con esto marcamos que la categoría seleccionada ya tiene una pregunta menos disponible
        //Asignando calificaciones al jugador adecuado
        ciclo=0;
        if(evaluacion==true)
        {
            while(true)
            {
                if(persona[ciclo]==1)
                {
                    persona[ciclo]=0;
                    persona[ciclo+1]=1;
                    break;
                }
                ciclo++;
            }
        }
        else
        {
            while(true)
            {
                if(ignorancia[ciclo]==1)
                {
                    ignorancia[ciclo]=0;
                    ignorancia[ciclo+1]=1;
                    break;
                }
                ciclo++;
            }
        }
        //Evaluando si algun jugador ya ha ganado
        system("pause>xd");
        if(persona[10]==1)
        {
            system("cls");
            lugar(30,10);
            cout<<"Has ganado!!! Gracias por jugar :)";
            FILE *archivo;
            archivo=fopen("Para el ganador.dat","w");
            fprintf(archivo,"https://www.youtube.com/watch?v=dQw4w9WgXcQ");
            fclose(archivo);
            lugar(30,11);
            cout<<"Ahora abre el bloc de notas que se acaba de crear ;)";
            Sleep(1500);
            break;
        }
        else if(ignorancia[10]==1)
        {
            system("cls");
            lugar(30,10);
            cout<<"Has perdido pero puedes intentalo de nuevo !!! Gracias por jugar :)";
            Sleep(2000);
            break;
        }
    }
    cout<<"\n\n\n\t\tPresiona cualquier tecla para salir.";
    system("pause>xd");
    //////////////////fin/////////////////
    return 0;
}