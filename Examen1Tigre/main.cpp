#include <iostream>
#include <fstream>
#include <math.h>
#include <list>
#include <vector>
#include "Evaluador.h"
using namespace std;

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 1 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Devuelve el atributo *nombre* de *usuario*
string getNombre(Usuario* usuario)
{
    Usuario u = *usuario;
    //cout<<u.ncombre<<endl;
    return u.nombre;
}

//Escribe todos los atributos de *usuario* en un archivo con con nombre *nombre_archivo*
void escribir(string nombre_archivo, Usuario* usuario)
{
   /* nombre_archivo.push_back('.');
    nombre_archivo.push_back('t');
    nombre_archivo.push_back('x');
    nombre_archivo.push_back('t');*/
    Usuario u = *usuario;
   // cout<<nombre_archivo<<endl;
    ofstream archivo(nombre_archivo.c_str());
    archivo<<u.nombre<<" "<<u.edad<<endl;
    archivo.close();
}


//Lee los atributos de un *Usuario* desde un archivo con nombre *nombre_archivo* y luego lo devuelve
Usuario* leer(string nombre_archivo)
{
/*nombre_archivo.push_back('.');
nombre_archivo.push_back('t');
nombre_archivo.push_back('x');
nombre_archivo.push_back('t');
//cout<<nombre_archivo<<endl;*/

ifstream in(nombre_archivo.c_str());
    string nombre;
    int edad;

   in>>nombre;
    //cout<<str<<endl;
    in>>edad;
   // cout<<str<<endl;

   in.close();
   Usuario u(nombre,edad );
   Usuario* e = &u;
    return e;
}

//Devuelve cuantas veces existe *numero* en *numeros*
int contar(vector<int> numeros, int numero)
{
    int contador = 0;
    for(int i=0; i<numeros.size(); i++){
        if(numeros[i]==numero){
            contador+=1 ;
        }
    }
    return contador;
}

//Devuelve *true* si existe al menos un valor repetido en *cadenas*
bool existeRepetida(list<string> cadenas)
{
   cadenas.sort();
   int y =cadenas.size();
    cadenas.unique();
    int x =cadenas.size();
    if (x==y){
         return false;
    }
   return true;
}

//Devuelve el contenido de *letras* invertido
vector<char> invertir(vector<char> letras)
{

    vector<char> respuesta;
    int x = letras.size();
    for(int i = 0; i<x;i++){
    respuesta.push_back(letras.back());
    letras.pop_back();
    }
    return respuesta;
}

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 2 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Realizar las siguientes clases dado el diagrama adjunto

//Lugar
//Lugar() Constructor vacio
//vendeComida() Funcion abstracta

//Restaurante
//Restaurante() Inicializa atributos
//vendeComida() Devuelve true

//Monumento
//Monumento() Inicializa atributos
//vendeComida() Devuelve false

///////////////////////////////////////////////////////////////////
////////////////////////////// Main ///////////////////////////////
///////////////////////////////////////////////////////////////////
class Lugar
{
    public:
        string nombre;
        double latitud;
        double longitud;
        Lugar(){
        }
       virtual bool vendeComida(){
        return NULL;
       };
};

class Restaurante : public Lugar
{
    public:
    string horario;
    Restaurante(string nombre,double latitud,double longitud,string horario)    {
        this->horario = horario;
        this->latitud = latitud;
        this->longitud = longitud;
        this->nombre = nombre;
    }
    bool vendeComida(){
        return true;
    }
};
class Monumento : public Lugar
{
    public:
    Monumento(string nombre,double latitud,double longitud)  {
        this->latitud = latitud;
        this->longitud = longitud;
        this->nombre =nombre;
    }
    bool vendeComida(){
     return false;
    }
};
void evaluar();
void evaluar2();

int main ()
{
    //Funcion evaluadora parte 1
    cout<<"Evaluador parte 1"<<endl<<"================="<<endl;
    evaluar();


    //Evaluacion parte 2
    //Descomentar para evaluar
    cout<<"Evaluador parte 2"<<endl<<"================="<<endl;
    evaluar2();

    return 0;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////// Evaluador 2 /////////////////////////////
///////////////////////////////////////////////////////////////////////


void evaluar2()
{
    double nota = 0;

    cout<<"**Clase Restaurante**"<<endl;
    cout<<"Test constructor:\t\t";
    if(Restaurante("Burger Queen",5.2,6.2,"24/7").nombre == "Burger Queen"
       && Restaurante("Burger Queen",6.1,6.2,"24/7").latitud == 6.1
       && Restaurante("Burger Queen",5.2,6.6,"24/7").longitud == 6.6
       && Restaurante("Burger Queen",5.2,6.2,"lunes a viernes").horario == "lunes a viernes"

       && Restaurante("Mc Ronald",5.2,6.2,"24/7").nombre == "Mc Ronald"
       && Restaurante("Mc Ronald",10.1,6.2,"24/7").latitud == 10.1
       && Restaurante("Mc Ronald",5.2,8.6,"24/7").longitud == 8.6
       && Restaurante("Mc Ronald",5.2,6.2,"siempre").horario == "siempre"
       )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test vendeComida():\t\t";

    if(Restaurante("Burger Queen",5.2,6.2,"24/7").vendeComida()
       && Restaurante("Mc Ronalds",5.2,6.2,"24/7").vendeComida())
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    cout<<"**Clase Monumento**"<<endl;
    cout<<"Test constructor:\t\t";
    if(Monumento("Burger Queen",5.2,6.2).nombre == "Burger Queen"
       && Monumento("Burger Queen",6.1,6.2).latitud == 6.1
       && Monumento("Burger Queen",5.2,6.6).longitud == 6.6

       && Monumento("Mc Ronald",5.2,6.2).nombre == "Mc Ronald"
       && Monumento("Mc Ronald",10.1,6.2).latitud == 10.1
       && Monumento("Mc Ronald",5.2,8.6).longitud == 8.6
       )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test vendeComida():\t\t";

    if(!Monumento("Burger Queen",5.2,6.2).vendeComida()
       && !Monumento("Mc Ronalds",5.2,6.2).vendeComida())
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/8"<<endl;
}
