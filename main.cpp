//parte de branch cliente
#include <iostream>
#include "clientes.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//parte de branch main excluyendo las que estan en ambas
#include <iomanip>
#include "Estructuras.h"
#include "vehiculo.h"


using namespace std;

int main()
{
    cout <<"version branch main 2.2" <<endl;

    //lo que estaba en branch main al unir ramas

    //quiza necesitemos añadir variable de precios para vehiculos
    //creo que es buena idea al iniciar comprar, crear (o cargar de los ya disponibles si rut ya existe) 
    //un nodo llamado cliente actual e ir modificandolo mientras compra
    vector<precios_marcas> precios = Leer_precios("precio_veh.txt");
    vector<Accesorio> accesorios = leerAccesoriosDesdeArchivo("precio_acc.txt");
    mostrarAccesorios(accesorios);


    //lo que estaba en branch clientes al unir ramas

    //voy a añadir funciones para modificar linea o añadir nueva al archivo txt
    //pero el programa funciona sin esa funcion actualmente porque trabaja con la lista dinamica

    /*
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

    */
    return 0;
}
