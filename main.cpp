#include <iostream>
#include "clientes.h"

using namespace std;

int main()
{
    cout <<"version clientes 1.2" <<endl;

    cliente* raiz_cliente=nullptr;

    
    cargar_LD_clientes(raiz_cliente);
    mostrar_LD_clientes(raiz_cliente);
    destroy_LD_clientes(raiz_cliente);

    return 0;
}