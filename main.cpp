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
    cout <<"version branch main 2.3" <<endl;
    //se añade primera version de menu

    //iniciar vectores de accesorios
    vector<precios_marcas> precios = Leer_precios("precio_veh.txt");
    vector<Accesorio> accesorios = leerAccesoriosDesdeArchivo("precio_acc.txt");
    mostrarAccesorios(accesorios);

    //iniciar lista dinamica de cliente
    cliente* raiz_cliente=nullptr;
    raiz_cliente = cargar_LD_clientes(raiz_cliente);
    system("cls");

    //esto puede convertirse en funcion de cliente que retorne cliente_actual
    cout <<"Elegir opcion de inicio: "<<endl;
    cout<<"1. Introducir RUT de cliente."<<endl;
    cout<<"2. Introducir RUT por defecto (Rayo McQueen)."<<endl;
    cout<<"3. Salir."<<endl;
    int opcion1;
    cin >>opcion1;
    system("cls");

    cliente* cliente_actual=nullptr;
    string rut_dado;
    switch (opcion1)
        {
           case 1:
                cout<<"Introduzca RUT (sin puntos y con guion): "<<endl;
                cin>>rut_dado;
                cliente_actual= buscar_cliente(raiz_cliente, rut_dado);
                if (cliente_actual==nullptr)
                {
                    cout<<"Se detecta como cliente nuevo, introduzca su nombre: "<<endl;
                    //seguir aqui para registrar nuevo cliente
                    string nombre_actual;
                    cin.ignore(); //si no esta esto, getline agarra el /n del ultimo cin
                    getline(cin,nombre_actual);
                    system("pause");
                    raiz_cliente=LD_clientes(raiz_cliente, rut_dado, nombre_actual, 0, 0, 0, 0);
                    cliente_actual= buscar_cliente(raiz_cliente, rut_dado);
                }
                else
                {
                    cout<<"Cliente ya registrado: "<<endl;
                    cliente_actual->mostrar_cliente();
                }
                break;
           case 2:
                rut_dado= "14911022-m";
                cliente_actual= buscar_cliente(raiz_cliente, rut_dado);
                if (cliente_actual==nullptr)
                {
                    cout<<"Cliente por defecto no se encuentra, revisar clientes.txt"<<endl;
                }
                break;
           default:
                break;
        }


    //inicializando variables a usar en promedio de ventas
    string nom_actual;
    int cant_veh_actual, cant_acc_actual, desc_acc_actual, veh_totales, cant_client;

    cliente_actual->mostrar_cliente();
    system("pause");
    //aqui empieza el menu real
    while (true)
    {
        system("cls");
        cout<<"1. Comprar vehiculos."<<endl;
        cout<<"2. Comprar accesorios."<<endl;
        cout<<"3. Promedio de ventas."<<endl;
        cout<<"4. Cantidad de vehiculos comprados."<<endl; //boleta imagino, ponemos todos los reportes en promedio mejor
        cout<<"5. Salir."<<endl;

        int opcion2;
        cin>>opcion2;
        switch (opcion2)
        {
        case 1:
            cout<<"se elige comprar vehiculos"<<endl;
            break;
        case 2:
            cout<<"se elige comprar accesorios"<<endl;
            break;
        case 3:
            system("cls");
            cout<<"se elige mostrar promedio de ventas"<<endl;
            //asignando variables a comparar en funcion
            nom_actual=cliente_actual->nombre;
            cant_veh_actual=cliente_actual->cant_veh;
            cant_acc_actual=cliente_actual->cant_acc;
            desc_acc_actual=cliente_actual->desc_acc;
            //mayor cliente de vehiculos
            mayor_cant(raiz_cliente, nom_actual, cant_veh_actual);

            //mayor cliente de accesorios
            mayor_cant(raiz_cliente, nom_actual, cant_acc_actual, desc_acc_actual);

            //numero de autos vendidos total
            veh_totales=0;
            autos_vendidos(raiz_cliente, veh_totales);

            //promedio de ventas por cliente
            cant_client=0;
            autos_vendidos(raiz_cliente, veh_totales, cant_client);
            system("pause");
            break;
        case 4:
            system("cls");
            cout<<"se elige mostrar cantidad de vehiculos comprados"<<endl;
            cliente_actual->mostrar_cliente();
            //nota: modificar mostrar_clientes de acuerdo a lo mostrado en la tarea (por ej: CLIENTE:nombre)
            //mostrar calculo de total con descuento y total general despues de mostrar cliente, no necesitaria nueva funcion
            system("pause");
            break;
        case 5:
            cout<<"Saliendo"<<endl;
            system("pause");
            destroy_LD_clientes(raiz_cliente);
            return false;
            break;
        default:
            cout<<"input incorrecto"<<endl;
            break;
        }


    //esto es para iniciar los reportes y asi va comparando con variables constantes al void

    }



    //lo que estaba en branch main al unir ramas

    //quiza necesitemos añadir variable de precios para vehiculos
    //creo que es buena idea al iniciar comprar, crear (o cargar de los ya disponibles si rut ya existe)
    //un nodo llamado cliente actual e ir modificandolo mientras compra
    //vector<precios_marcas> precios = Leer_precios("precio_veh.txt");
    //vector<Accesorio> accesorios = leerAccesoriosDesdeArchivo("precio_acc.txt");
    //mostrarAccesorios(accesorios);


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

    //esto no lo toca porque el switch termina le prograna
    cout<<"cerrando"<<endl;
    system("pause");
    destroy_LD_clientes(raiz_cliente);
    return 0;
}
