
#include <iostream>
#include "clientes.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cout <<"version clientes 1.5" <<endl;

    cliente* raiz_cliente=nullptr;
    raiz_cliente = cargar_LD_clientes(raiz_cliente);

    mostrar_LD_clientes(raiz_cliente);

    cout<<"raiz actual: "<<endl;
    raiz_cliente->mostrar_cliente();

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
    int cant_veh_actual=cliente_actual->cant_veh;

    int cant_acc_actual=cliente_actual->cant_acc;
    int desc_acc_actual=cliente_actual->desc_acc;

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
