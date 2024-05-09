#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "vehiculo.h"
#include "Estructuras.h"
using namespace std;

vector<precios_marcas> precios = Leer_precios("precio_veh.txt");
vector<Vehiculo*> lista_vehiculos;


Vehiculo::~Vehiculo()
{
    cout<<"Saliendo de vehiculo"<<endl;
};

Vehiculo *Vehiculo::crearNuevoVehiculo()
{
    int ruedas, ano_fab;
    string marca;
    bool control;

    cout << "Ingrese la cantidad de ruedas: ";
    cin >> ruedas;
    cout << "Ingrese la marca del vehículo: ";
    cin >> marca;
    cout << "Ingrese si tiene control remoto (0/1): ";
    cin >> control;
    cout << "Ingrese el año de fabricación: ";
    cin >> ano_fab;

    return new Vehiculo(ruedas, marca, control, ano_fab);
}


Auto *Auto::crearNuevoVehiculo()
{
    int Puertas, Espejos;
    cout << "Ingrese la cantidad de puertas: ";
    cin >> Puertas;
    cout << "Ingrese la cantidad de espejos: ";
    cin >> Espejos;
    return new Auto(cantidad_ruedas, marca, control_remoto, year_fabricacion, Puertas, Espejos,precio);
}


vector<Vehiculo*> almacenarVehiculo(vector<Vehiculo*>& lista_vehiculos, Vehiculo* nuevo_vehiculo,vector<precios_marcas>& precios) 
{
    lista_vehiculos.push_back(nuevo_vehiculo);
    //sacamos el valor ahoora
    string marca = nuevo_vehiculo->get_marca();
    string tipo_vehiculo;
    if( tipo_vehiculo=="AUTO")
    {
        for(const auto& precio : precios )
        {
            if(precio.Tipo_vehiculo == tipo_vehiculo && precio.Marca_vehiculo == marca)
            {
                nuevo_vehiculo->set_precio(precio.Precio_marca);
                break;
            }
        }
    }
    else if( tipo_vehiculo == "MOTO")
    {
        for(const auto& precio : precios )
        {
            if(precio.Tipo_vehiculo == tipo_vehiculo && precio.Marca_vehiculo == marca)
            {
                nuevo_vehiculo->set_precio(precio.Precio_marca);
                break;
            }
        }
    }
    else if( tipo_vehiculo == "CAMION")
    {
        for(const auto& precio : precios )
        {
            if(precio.Tipo_vehiculo == tipo_vehiculo && precio.Marca_vehiculo == marca)
            {
                nuevo_vehiculo->set_precio(precio.Precio_marca);
                break;
            }
        }
    }
    return lista_vehiculos;
}
int contarVehiculos(const vector<Vehiculo*>& lista_vehiculos) {
    return lista_vehiculos.size();
}
