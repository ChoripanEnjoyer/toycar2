#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Estructuras.h"
#include "vehiculo.h"

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
                nuevo_vehiculo->setPrecio();
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
                nuevo_vehiculo->setPrecio();
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
                nuevo_vehiculo->setPrecio();
                break;
            }
        }
    }
    return lista_vehiculos;
}

int contarVehiculos(const vector<Vehiculo*>& lista_vehiculos,int cantidad_veh) 

{
    return lista_vehiculos.size()*cantidad_veh;
}
void mostrarListaVehiculos(const vector<Vehiculo*>& lista_vehiculos) {
    cout << "Lista de vehículos disponibles:" << endl;
    cout << "--------------------------------" << endl;
    int index = 1;
    for (const auto& vehiculo : lista_vehiculos) {
        cout << "Vehículo " << index << ":" << endl;
        cout << "Marca: " << vehiculo->get_marca() << endl;
        //cout << "Precio: $" << vehiculo->calcularPrecioTotal() << endl;
        cout << "--------------------------------" << endl;
        index++;
    }
}

int calcularMontoTotal(vector<precios_marcas>& precios, string tipo_vehiculo, string marca_seleccionada, int cant_vehi) 
{
    int precio_total = 0;

    if (tipo_vehiculo == "AUTO" || tipo_vehiculo == "MOTO" || tipo_vehiculo == "CAMION")
    {
        for (const auto& precio : precios)
        {
            if (precio.Tipo_vehiculo == tipo_vehiculo && precio.Marca_vehiculo == marca_seleccionada)
            {
                precio_total = precio.Precio_marca * cant_vehi; // Calcula el precio total de la operación
                break;
            }
        }
    }
    return precio_total;
}