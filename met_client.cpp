#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "clientes.h"
using namespace std;

cliente::cliente(string crut, string cnombre, int d_v, int d_a, int c_v, int c_a)
{
    this->rut=crut;
    this->nombre=cnombre;
    this->desc_veh=d_v;
    this->desc_acc=d_a;
    this->cant_veh=c_v;
    this->cant_acc=c_a;
    this->sig=nullptr;
}

cliente::~cliente()
{
    cout<<nombre<<" ELIMINADO"<<endl;
}

void cliente::mostrar_cliente()
{
    cout<<"RUT: "<<this->rut<<endl;
    cout<<"Nombre: "<<this->nombre<<endl;
    cout<<"Total de compras de vehiculos: "<<this->desc_veh<<endl;
    cout<<"Total de compras de accesorios: "<<this->desc_acc<<endl;
    cout<<"Numero de vehiculos comprados: "<<this->cant_veh<<endl;
    cout<<"Numero de accesorios comprados: "<<this->cant_acc<<endl;
}

//lista dinamica clientes, se puede llamar de nuevo para añadir al cliente actual
cliente* LD_clientes(cliente* raiz_cliente, string crut, string cnombre, int d_v, int d_a, int c_v, int c_a)
{
    if (raiz_cliente == nullptr) {
        raiz_cliente = new cliente(crut, cnombre, d_v, d_a, c_v, c_a);
        cout<<"nuevo nodo"<<endl;
        return raiz_cliente;
    }
    else {
        raiz_cliente->sig = LD_clientes(raiz_cliente->sig, crut, cnombre, d_v, d_a, c_v, c_a);
        cout<<"se añade siguiente"<<endl;
    }
    return raiz_cliente;
}

void destroy_LD_clientes(cliente* raiz_cliente)
{
  if(raiz_cliente!=nullptr)
  {
    destroy_LD_clientes(raiz_cliente->sig);
    delete raiz_cliente;
  }
}

void mostrar_LD_clientes(cliente* raiz_cliente)
{
    if (raiz_cliente == nullptr)
    {
        return;
    }
    if (raiz_cliente != nullptr)
    {
        raiz_cliente->mostrar_cliente(); // Access derived class-specific method
    }
    mostrar_LD_clientes(raiz_cliente->sig);
}

//cargar lista de clientes
cliente* cargar_LD_clientes(cliente* raiz_cliente)
{
    string archivo1 = "clientes.txt";
    ifstream archivo(archivo1.c_str());
    if (!archivo)
    {
        cerr << "Error: Could not open file." << endl;
        return nullptr;
    }

    string linea;
    while (getline(archivo, linea))
    {
        cout << linea << endl;

        stringstream ss(linea);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() != 6)
        {
            cerr << "Error: Invalid number of columns in the input file." << endl;
            continue;
        }
        string crut = tokens[0];
        string cnombre = tokens[1];
        int d_v = atoi(tokens[2].c_str());
        int d_a = atoi(tokens[3].c_str());
        int c_v = atoi(tokens[4].c_str());
        int c_a = atoi(tokens[5].c_str());

        raiz_cliente= LD_clientes(raiz_cliente, crut, cnombre, d_v, d_a, c_v, c_a);

        tokens.clear();
    }
    archivo.close();
    return raiz_cliente;
}


cliente* buscar_cliente(cliente* raiz_cliente, string rut_dado)
{
    if (raiz_cliente==nullptr)
    {
        return nullptr;
    }
    cliente* punt_busc=nullptr;
    if (rut_dado == raiz_cliente->rut)
    {
        cout<<"rut ya registrado: "<<endl;
        punt_busc=raiz_cliente;
        punt_busc->mostrar_cliente(); // Access derived class-specific method
        return punt_busc;
    }
    return buscar_cliente(raiz_cliente->sig, rut_dado);
}

void mayor_cant(cliente* raiz_cliente, string nom_actual, int cant_veh_actual)
{
    if (raiz_cliente==nullptr)
    {
        cout<<"raiz nula"<<endl;
        return;
    }
    if (cant_veh_actual <= raiz_cliente->cant_veh)
    {
        nom_actual=raiz_cliente->nombre;
        cant_veh_actual=raiz_cliente->cant_veh;
    }
    if (raiz_cliente->sig==nullptr)
    {
        cout<<nom_actual <<" ha comprado mas vehiculos con un total de: "<<cant_veh_actual<<" vehiculos."<<endl;
        return;
    }
    mayor_cant(raiz_cliente->sig, nom_actual, cant_veh_actual);
}

//polimorfismo sobrecarga de funciones para sacar mayor de acc y para autos vendidos, este ultimo usa la misma variable
void mayor_cant(cliente* raiz_cliente, string nom_actual, int cant_acc_actual, int desc_acc_actual)
{
    if (raiz_cliente==nullptr)
    {
        cout<<"raiz nula"<<endl;
        return;
    }
    if (cant_acc_actual <= raiz_cliente->cant_acc)
    {
        nom_actual=raiz_cliente->nombre;
        cant_acc_actual=raiz_cliente->cant_acc;
        desc_acc_actual=raiz_cliente->desc_acc;
    }
    if (raiz_cliente->sig==nullptr)
    {
        cout<<nom_actual <<" ha comprado mas accesorios con un total de "<<desc_acc_actual<<" pesos gastados en "<<cant_acc_actual<<" accesorios"<<endl;
        return;
    }

    mayor_cant(raiz_cliente->sig, nom_actual, cant_acc_actual, desc_acc_actual);
}

void autos_vendidos(cliente* raiz_cliente, int veh_totales)
{
    if (raiz_cliente==nullptr)
    {
        cout<<"raiz nula"<<endl;
        return;
    }
    if (raiz_cliente->cant_veh>0)
    {
        veh_totales+=raiz_cliente->cant_veh;
    }
    if (raiz_cliente->sig==nullptr)
    {
        cout<<"La cantidad total de vehiculos vendidos es de: "<<veh_totales<<endl;
        return;
    }
    autos_vendidos(raiz_cliente->sig, veh_totales);
}

void autos_vendidos(cliente* raiz_cliente, int veh_totales, int cant_client)
{
    if (raiz_cliente==nullptr)
    {
        cout<<"raiz nula"<<endl;
        return;
    }
    if (raiz_cliente->cant_veh>0)
    {
        veh_totales+=raiz_cliente->desc_veh;
        cant_client+=1;
    }
    if (raiz_cliente->sig==nullptr)
    {
       // cout<<cant_client<<endl;
       // cout<<veh_totales<<endl;
        int prom_veh=veh_totales/cant_client;
        cout<<"Los clientes en promedio gastan "<<prom_veh<<" en vehiculos"<<endl;
        return;
    }
    autos_vendidos(raiz_cliente->sig, veh_totales, cant_client);
}


