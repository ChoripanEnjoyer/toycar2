#include <iostream>
#include "clientes.h"


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