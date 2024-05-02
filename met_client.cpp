#include <iostream>
#include <fstream>
#include <sstream>
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

//lista dinamica clientes
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

void destroy_LD_clientes(cliente *raiz_cliente)
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
        return;

    if (raiz_cliente != nullptr) {
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

        if (tokens.size() != 5) 
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
    return raiz_cliente;
}