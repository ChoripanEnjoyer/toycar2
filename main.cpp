#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "Estructuras.h"
#include "vehiculo.h"

using namespace std;

int main()
{
    vector<precios_marcas> precios = Leer_precios("precio_veh.txt");
    vector<Accesorio> accesorios = leerAccesoriosDesdeArchivo("precio_acc.txt");
    //mostrarAccesorios(accesorios);

    return 0;
}

