#include <iostream>

using namespace std;

class cliente
{
    public:
    string rut="";
    string nombre="";
    int desc_veh=0;
    int desc_acc=0;
    int cant_veh=0;
    int cant_acc=0;
    cliente* sig=nullptr;

    cliente(string crut, string cnombre, int d_v, int d_a, int c_v, int c_a);
    ~cliente();
   // void pedir_datos();
    void mostrar_cliente();


};

//declaracion de funciones de lista dinamica de clientes
cliente* LD_clientes(cliente* raiz_cliente, string crut, string cnombre, int d_v, int d_a, int c_v, int c_a);
void destroy_LD_clientes(cliente* raiz_cliente);
void mostrar_LD_clientes(cliente* raiz_cliente);
cliente* cargar_LD_clientes(cliente* raiz_cliente);

cliente* buscar_cliente(cliente* raiz_cliente, string rut_dado);
void mayor_cant(cliente* raiz_cliente, string nom_actual, int cant_veh_actual);
void mayor_cant(cliente* raiz_cliente, string nom_actual, int cant_acc_actual, int desc_acc_actual);
void autos_vendidos(cliente* raiz_cliente, int veh_totales);
void autos_vendidos(cliente* raiz_cliente, int veh_totales, int cant_client);