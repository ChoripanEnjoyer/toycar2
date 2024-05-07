#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "vehiculo.h"
using namespace std;

Vehiculo::Vehiculo(int crear_ruedas, string crear_mark, bool crear_control, int crear_ano_fab)
{
    this-> cantidad_ruedas= crear_ruedas;
    this-> marca = crear_mark;
    this-> control_remoto = crear_control;
    this-> year_fabricacion = crear_ano_fab;
    this-> sig = nullptr;
}

Vehiculo::~Vehiculo()
{
    cout<<"Saliendo de vehiculo"<<endl;
}

void Vehiculo::pedir_datos()
{
    cout<<"Ingrese la cantidad de ruedas: ";
    cin>>this-> cantidad_ruedas;
    cout<<"Ingrese La marca del vehiculo: ";
    cin>>this-> marca;
    cout<<"Ingrese si tiene control remoto (0/1): ";
    cin>>this-> control_remoto;
    cout<<"ingrese el año: ";
    cin>>this-> year_fabricacion;
}

void Vehiculo::mostrar_datos()
{
    cout<<"Ruedas: "<<this->cantidad_ruedas<<endl;
    cout<<"Marca: "<<this->marca<<endl;
    cout << (this->control_remoto ? "tiene control" : "no tiene control") << endl;// es una expresión ternaria que evalúa si control_remoto es true o false y dependiendo de eso devuelve un valor u otro.
}

Auto::Auto(int crear_ruedas, string crear_mark, bool crear_control, int crear_ano_fab, int crea_rueda, int crea_luz):Vehiculo(crear_ruedas, crear_mark, crear_control, crear_ano_fab)
{

    this-> cantidad_ruedas= crear_ruedas;
    this-> marca = crear_mark;
    this-> control_remoto = crear_control;
    this-> year_fabricacion = crear_ano_fab;
    this-> Cantidad_puertas = crea_rueda;
    this-> Cantidad_luces = crea_luz;
    this-> sig = nullptr;

}
void Auto::pedir_datos()
{
    cout<<"Ingrese la cantidad de puertas: ";
    cin>>this-> Cantidad_puertas;
    cout<<"Ingrese la cantidad de luces: ";
    cin>>this-> Cantidad_luces;
}

Moto::Moto(int crear_ruedas, string crear_mark, bool crear_control, int crear_ano_fab, int crea_espejo, int crea_pedal):Vehiculo(crear_ruedas, crear_mark, crear_control, crear_ano_fab)
{

    this-> cantidad_ruedas= crear_ruedas;
    this-> marca = crear_mark;
    this-> control_remoto = crear_control;
    this-> year_fabricacion = crear_ano_fab;
    this-> cantidad_espejos = crea_espejo;
    this-> cantidad_pedales = crea_pedal;
    this-> sig = nullptr;

}
void Moto::pedir_datos()
{
    cout<<"Ingrese la cantidad de espejos: ";
    cin>>this-> cantidad_espejos;
    cout<<"Ingrese la cantidad de pedales: ";
    cin>>this-> cantidad_pedales;
}

Camion::Camion(int crear_ruedas, string crear_mark, bool crear_control, int crear_ano_fab, int crea_eje, int crea_tolva):Vehiculo(crear_ruedas, crear_mark, crear_control, crear_ano_fab)
{

    this-> cantidad_ruedas= crear_ruedas;
    this-> marca = crear_mark;
    this-> control_remoto = crear_control;
    this-> year_fabricacion = crear_ano_fab;
    this-> cantidad_ejes = crea_eje;
    this-> cantidad_tolvas = crea_tolva;
    this-> sig = nullptr;

}
void Camion::pedir_datos()
{
    cout<<"Ingrese la cantidad de espejos: ";
    cin>>this-> cantidad_ejes;
    cout<<"Ingrese la cantidad de pedales: ";
    cin>>this-> cantidad_tolvas;
}
