#include "cliente.h"
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
    cout <<" hola"<< endl;
    cout <<"version clientes 1.5" <<endl;

    cliente* raiz_cliente=nullptr;
    raiz_cliente = cargar_LD_clientes(raiz_cliente);

    mostrar_LD_clientes(raiz_cliente);

    cout<<"raiz actual: "<<endl;
    raiz_cliente->mostrar_cliente();
    vector<precios_marcas> precios = Leer_precios("precio_veh.txt");
    vector<Accesorio> Accesorios = leerAccesoriosDesdeArchivo("acc.txt");
    vector<Vehiculo*> lista_vehiculos;
    //cliente actual
    cout<<"--checking rut--"<<endl;
    string rut_dado= "20551982-m";
    cliente* cliente_actual= buscar_cliente(raiz_cliente, rut_dado);
    if (cliente_actual==nullptr)
    {
        cout<<"NO SE ENCUENTRA CLIENTE DADO"<<endl;
        //seguir aqui en caso de ser nuevo cliente
    }

    string nom_actual= cliente_actual->nombre;
    int opcion = 0;
    int cant_veh_actual=cliente_actual->cant_veh;

    int cant_acc_actual=cliente_actual->cant_acc;
    int desc_acc_actual=cliente_actual->desc_acc;
    int cantidad_veh = 0;
    cout << "Bienvenido al sistema de venta de Toyscar." << endl;

    while (opcion != 4) 
    {
        cout << "¿Qué desea hacer?" << endl;
        cout << "-----------------" << endl;
        cout << "1) Comprar Auto." << endl;
        cout << "2) Comprar Moto." << endl;
        cout << "3) Comprar Camión." << endl;
        cout << "4) Cobrar venta." << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) 
        {
            case 1:
            {
                cout << "Seleccione la marca de auto que desea comprar:" << endl;
                mostrarMarcas(precios, "AUTO");
                
                string marca_seleccionada;
                cout << "Ingrese la marca seleccionada: ";
                cin >> marca_seleccionada;
                int cantidad_autos = 0;
                Auto* nuevo_auto = new Auto(4, marca_seleccionada, false, 2022, 0, 4,2, Accesorios);
                cout <<"cuantos autos"<<marca_seleccionada<<"quiere comprar: ";
                cin>> cantidad_autos;
                cantidad_veh += cantidad_autos;
                cant_veh_actual = cantidad_veh;
                
                lista_vehiculos = almacenarVehiculo(lista_vehiculos, nuevo_auto, precios);
                calcularMontoTotal(precios, "AUTO",marca_seleccionada,cant_veh);

            
                break;
            }

            case 2:
                mostrarMarcas(precios, "MOTO");

                break;
            case 3:

                mostrarMarcas(precios, "CAMION");

                break;
            case 4:

                break;
            default:
                cout << "Opción no válida. Por favor, elija una opción válida." << endl;
                break;
        }
    }


    //mayor cliente de vehiculos
    mayor_cant(raiz_cliente, nom_actual, cant_veh_actual);

    //mayor cliente de accesorios
    cout<<cant_acc_actual<<endl;
    mayor_cant(raiz_cliente, nom_actual, cant_acc_actual, desc_acc_actual);

    //numero de autos vendidos total
    int veh_totales=0;
    autos_vendidos(raiz_cliente, veh_totales);

    //promedio de ventas por cliente
    int cant_client=0;
    autos_vendidos(raiz_cliente, veh_totales, cant_client);

    //destruir arbol
    destroy_LD_clientes(raiz_cliente);

    return 0;
}
