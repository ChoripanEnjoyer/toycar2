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
    
    vector<Accesorio> accesorios = leerAccesoriosDesdeArchivo("precio_acc.txt");
    //mostrarAccesorios(accesorios);
    menu();
    return 0;
}

