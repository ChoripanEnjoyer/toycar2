#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "Estructuras.h"
#include "vehiculo.h"

using namespace std;

int main()
{
    
    vector<precios_marcas> precios = Leer_precios("precio_veh.txt");
    //mostrarAccesorios(accesorios);
    vector<Vehiculo*> lista_vehiculos;
    int opcion = 0;
    cout << "Bienvenido al sistema de venta de Toyscar." << endl;
    cout << "Que desea Hacer"<< endl;
    cout << "-----------------" << endl;
    cout << "1) Comprar Vehiculo."<<endl<<
            "2)Mostrar Vehiculos"<<endl<<
            "3) Eliminar Vehiculo."<<endl<<
            "4)cobrar venta."<<endl<<
            "5) salir."<< endl;
    while(opcion != 5)
    {
        cin >> opcion;
        if(opcion == 1)
        {
            int Opcion_veh;
            cout << "Que Vehiculo desea comprar"<< endl;
            cout << 
            "1)Auto."<<endl<<
            "2)Moto."<<endl<<
            "3) Camion."<<endl<<
            "4) <---Volver atras."<< endl;
            cin >> Opcion_veh;
            if(Opcion_veh == 1)
            {
                mostrarMarcas(precios,"AUTO");
                Vehiculo *auto_nuevo = new Auto(0, "NN", false, 0000, 0, 0,0);
                auto_nuevo->crearNuevoVehiculo();
                lista_vehiculos = almacenarVehiculo(lista_vehiculos,auto_nuevo,precios);
                
            }else if (Opcion_veh == 2)
            {
                mostrarMarcas(precios,"MOTO");
                Moto *new_moto = new_moto->crearNuevoVehiculo();
                lista_vehiculos = almacenarVehiculo(lista_vehiculos, new_moto, precios);
            }
            else if (Opcion_veh == 3)
            {
                mostrarMarcas(precios,"CAMION");
                Camion *new_camion = new_camion->crearNuevoVehiculo();
                lista_vehiculos = almacenarVehiculo(lista_vehiculos, new_camion, precios);
            }
            
        }
    }
    return 0;
}

