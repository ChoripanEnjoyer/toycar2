#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "accesorio.h"
using namespace std;

int main()
{
    string archivo = "precio_acc.txt";
    vector<Accesorio> accesorios = leerAccesoriosDesdeArchivo(archivo);
    mostrarAccesorios(accesorios);

    return 0;
}