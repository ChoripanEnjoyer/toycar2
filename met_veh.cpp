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
    return new Vehiculo(ruedas,marca,control,ano_fab);
}


Auto *Auto::crearNuevoVehiculo()
{
    int Puertas, Espejos;
    cout << "Ingrese la cantidad de puertas: ";
    cin >> Puertas;
    cout << "Ingrese la cantidad de espejos: ";
    cin >> Espejos;
    return new Auto(cantidad_ruedas, marca, control_remoto, year_fabricacion, Puertas, Espejos);
}


vector<Vehiculo*> almacenarVehiculo(vector<Vehiculo*>& lista_vehiculos, Vehiculo* nuevo_vehiculo) 
{
    lista_vehiculos.push_back(nuevo_vehiculo);
    return lista_vehiculos;
}

void menu()
{
    int opcion = 0;
    cout << "Bienvenido al sistema de venta de Toyscar." << endl;
    cout << "Que desea Hacer"<< endl;
    cout << "-----------------" << endl;
    cout << "1) Comprar Vehiculo."<<
            "2)Mostrar Vehiculos"<<
            "3) Eliminar Vehiculo."<<
            "4)cobrar venta."<<
            "5) salir."<< endl;
    cin >> opcion;
    while(opcion != 5)
    {
        if(opcion == 1)
        {
            int Opcion_veh;
            cout << "Que Vehiculo desea comprar"<< endl;
            cout << 
            "1)Auto."<<
            "2)Moto."<<
            "3) Camion."<<
            "4) <---Volver atras."<< endl;
            cin >> Opcion_veh;
            if(Opcion_veh == 1)
            {
                mostrarMarcas(precios,"AUTO");
                Auto *auto_nuevo = auto_nuevo->crearNuevoVehiculo();
                lista_vehiculos = almacenarVehiculo(lista_vehiculos,auto_nuevo);
                
            }else if (Opcion_veh == 2)
            {
                mostrarMarcas(precios,"MOTO");
                Moto *new_moto = new_moto->crearNuevoVehiculo();
                lista_vehiculos = almacenarVehiculo(lista_vehiculos, new_moto);
            }
            else if (Opcion_veh == 3)
            {
                mostrarMarcas(precios,"CAMION");
                Camion *new_camion = new_camion->crearNuevoVehiculo();
                lista_vehiculos = almacenarVehiculo(lista_vehiculos, new_camion);
            }
            
        }
    }
}