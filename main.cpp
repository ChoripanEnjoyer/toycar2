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
    vector<Accesorio*> accesorios_cliente;
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
    int monto_total = 0;
    string marca_seleccionada;
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
                mostrarMarcas(precios, "AUTO");
                cout << "Seleccione la marca de auto que desea comprar:" << endl;

                cin >> marca_seleccionada;
                int cantidad_autos = 0;
                cout <<"cuantos autos "<<marca_seleccionada<<" quiere comprar: ";
                cin>> cantidad_autos;
                for (int i = 0; i < cantidad_autos; ++i) 
                {
                    Auto* nuevo_auto = new Auto(4, marca_seleccionada, false, 2022, 0, 4, 2);
            
                    cout << "¿Cuántas puertas quiere el auto " << i + 1 << "?: ";
                    int cantidad_puertas;
                    cin >> cantidad_puertas;
                    nuevo_auto->setPuertas(cantidad_puertas);
            
                    cout << "¿Cuántas luces quiere el auto " << i + 1 << "?: ";
                    int cantidad_luces;
                    cin >> cantidad_luces;
                    nuevo_auto->setLuces(cantidad_luces);
            
                    lista_vehiculos = almacenarVehiculo(lista_vehiculos, nuevo_auto, precios);
                    int monto_total_auto = calcularMontoTotal(precios, lista_vehiculos);
                    monto_total += monto_total_auto;
                }

                break;

            }

            case 2:
            {
                mostrarMarcas(precios, "MOTO");
                cout << "Seleccione la marca de moto que desea comprar: " << endl;

                cin >> marca_seleccionada;
                int cantidad_motos = 0;
                cout <<"cuantas motos "<<marca_seleccionada<<" quiere comprar: ";
                cin>> cantidad_motos;
                for (int i = 0; i < cantidad_motos; ++i) 
                {
                    Moto* nueva_moto = new Moto(2, marca_seleccionada, false, 2022, 0, 4,2);
            
                    cout << "¿Cuántos pedales quiere la moto " << i + 1 << "?: ";
                    int cantidad_pedales;
                    cin >> cantidad_pedales;
                    nueva_moto->setpedal(cantidad_pedales);
            
                    cout << "¿Cuántos espejos  quiere la moto" << i + 1 << "?: ";
                    int cantidad_espejos;
                    cin >> cantidad_espejos;
                    nueva_moto->setespejo(cantidad_espejos);
            
                    lista_vehiculos = almacenarVehiculo(lista_vehiculos, nueva_moto, precios);
                }
                int monto_total_moto = calcularMontoTotal(precios, lista_vehiculos);
                monto_total += monto_total_moto;
                break;
            }
            case 3:
            {
                mostrarMarcas(precios, "CAMION");
                cout << "Seleccione la marca de camion que desea comprar: " << endl;

                cin >> marca_seleccionada;
                int cantidad_camiones = 0;
                cout <<"cuantos camiones "<<marca_seleccionada<<" quiere comprar: ";
                cin>> cantidad_camiones;
                for (int i = 0; i < cantidad_camiones; ++i) 
                {
                    Camion* nuevo_camion = new Camion(6, marca_seleccionada, false, 2022, 0, 4,2);
            
                    cout << "¿Cuántas cajas quiere el camion " << i + 1 << "?: ";
                    int cantidad_cajas;
                    cin >> cantidad_cajas;
                    nuevo_camion->settolva(cantidad_cajas);
            
                    cout << "¿Cuántos ejes quiere el camion" << i + 1 << "?:  ";
                    int cantidad_ejes;
                    cin >> cantidad_ejes;
                    nuevo_camion->seteje(cantidad_cajas);
                    lista_vehiculos = almacenarVehiculo(lista_vehiculos, nuevo_camion, precios);
                }
                int monto_total_camion = calcularMontoTotal(precios, lista_vehiculos);
                monto_total += monto_total_camion;
                break;

            }
            case 4:
            {   cout << "el monto total  es: "<<monto_total<<endl;
                break;
            }
            default:
            {
                cout << "Opción no válida. Por favor, elija una opción válida." << endl;
                break;
            }
        }
    }

    monto_total = calcularMontoTotal(precios, lista_vehiculos);
    cout << "Lista de vehículos:" << endl;
    mostrarListaVehiculos(lista_vehiculos);
    cout << "El monto total es: " << monto_total << endl;
    
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
