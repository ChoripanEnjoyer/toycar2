#ifndef ACCESORIO_H
#define ACCESORIO_H

#include <vector>
#include <string>

using namespace std;

struct Accesorio
{
    string Tipo;
    string nombre_acc;
    int Valor;
};

struct precios_marcas
{
    string Tipo_vehiculo;
    string Marca_vehiculo;
    int Precio_marca;
};

vector<Accesorio> leerAccesoriosDesdeArchivo(const string& nombre_archivo);
vector<precios_marcas> Leer_precios(const string& nombre_archivo);

void mostrarAccesorios(const vector<Accesorio>& accesorios);


#endif
