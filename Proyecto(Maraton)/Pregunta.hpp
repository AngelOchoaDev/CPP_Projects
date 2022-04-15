///////////////////////Declaración de la clase///////////////////////
class Pregunta
{
    private:
        string pregunta;          //-> La pregunta a responder
        string respuesta_1;       //-> La primera posible respuesta
        string respuesta_2;       //-> La segunda posible respuesta
        string respuesta_3;       //-> La tercera posible respuesta
        int identificador;        //-> El identificador de la respuesta correcta
        boolean seleccionador;    //-> Booleano para saber si esta pregunta ya se preguntó anteriormente  

    public:
        Pregunta(string, string, string, string, int);      //->Constructor
        ~Pregunta();                                        //->Destructor

        string get_pregunta();
        string get_respuesta_1();
        string get_respuesta_2();
        string get_respuesta_3();
        int get_identificador();
        boolean get_seleccionador();

        void set_pregunta(string);
        void set_respuesta_1(string);
        void set_respuesta_2(string);
        void set_respuesta_3(string);
        void set_identificador(int);
        void set_seleccionador(boolean);

        void mostrar_datos();
        void preguntar();
        boolean evaluar(string);
        
};
////////////////////////Constructores//////////////////////////
Pregunta::Pregunta(string pregunta, string respuesta_1, string respuesta_2, string respuesta_3, int identificador)
{
    this->pregunta=pregunta;
    this->respuesta_1=respuesta_1;
    this->respuesta_2=respuesta_2;
    this->respuesta_3=respuesta_3;
    this->identificador=identificador;
    this->seleccionador=false;
}

///////////////////////Destructores///////////////////////////
Pregunta::~Pregunta(){}

//////////////////////Funciones Set///////////////////////////
void Pregunta::set_pregunta(string pregunta){this->pregunta=pregunta;}
void Pregunta::set_respuesta_1(string respuesta_1){this->respuesta_1=respuesta_1;}
void Pregunta::set_respuesta_2(string respuesta_2){this->respuesta_2=respuesta_2;}
void Pregunta::set_respuesta_3(string respuesta_3){this->respuesta_3=respuesta_3;}
void Pregunta::set_identificador(int identificador){this->identificador=identificador;}
void Pregunta::set_seleccionador(boolean seleccionador){this->seleccionador=seleccionador;}

//////////////////////Funciones Get///////////////////////////
string Pregunta::get_pregunta(){return this->pregunta;}
string Pregunta::get_respuesta_1(){return this->respuesta_1;}
string Pregunta::get_respuesta_2(){return this->respuesta_2;}
string Pregunta::get_respuesta_3(){return this->respuesta_3;}
int Pregunta::get_identificador(){return this->identificador;}
boolean Pregunta::get_seleccionador(){return this->seleccionador;}

/////////////////////Funciones en general////////////////////
void Pregunta::mostrar_datos()
{
    cout<<"\n";
    cout<<"=============================================================================";
    cout<<"Pregunta: "<<this->pregunta <<endl;
    cout<<"Respuesta_1: "<<this->respuesta_1 <<endl;
    cout<<"Respuesta_2 "<<this->respuesta_2 <<endl;
    cout<<"Respuesta_3 "<<this->respuesta_3 <<endl;
    cout<<"Identificador: "<<this->identificador <<endl;
    cout<<"=============================================================================";
    cout<<"\n";
}

void Pregunta::preguntar()
{
    cout<<"\n";
    cout<<"\n\t" <<this->pregunta;
    cout<<"\n";
    cout<<"\n\t" <<this->respuesta_1;
    cout<<"\n\t" <<this->respuesta_2;
    cout<<"\n\t" <<this->respuesta_3;
    cout<<"\n\n\tR= ";
}

boolean Pregunta::evaluar(string respuesta_usuario)
{
    int evaluador;
    try
    {
        evaluador=stol(respuesta_usuario, nullptr, 10);
    }
    catch(const exception& e)
    {
        evaluador=4;        //->Debido a error de input del usuario se marca la respuesta como incorrecta
    }
    if(this->identificador==evaluador)
    {
        cout<<"\n\n\tCorrecto!!! Ganas un punto :)";
        return true;
    }
    else
    {
        cout<<"\n\n\tIncorrecto, la ignorancia gana un punto :(";
        return false;
    }
}