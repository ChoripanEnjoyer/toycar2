#include <iostream>

using namespace std;

class cliente 
{
    public:
    string rut, nombre;
    int desc_veh, desc_acc, cant_veh, cant_acc;
    cliente* sig;

    cliente(string crut, string cnombre, int d_v, int d_a, int c_v, int c_a);
    ~cliente();
   // void pedir_datos();
    void mostrar_cliente();
};

//declaracion de funciones de lista dinamica de clientes
cliente* LD_clientes(cliente* raiz_cliente, string crut, string cnombre, int d_v, int d_a, int c_v, int c_a);
void destroy_LD_clientes(cliente* raiz_cliente);
void mostrar_LD_clientes(cliente* raiz_cliente);
cliente* cargar_LD_clientes();
