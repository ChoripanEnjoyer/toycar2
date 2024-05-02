#include <iostream>

using namespace std;

class cliente 
{
    public:
    string rut, nombre;
    int desc_veh, desc_acc, cant_veh, cant_acc;
    cliente* sig;

    cliente(string rut, string nombre, int d_v, int d_a, int c_v, int c_a);
    ~cliente();

   // void pedir_datos();
    void mostrar_cliente();
};

