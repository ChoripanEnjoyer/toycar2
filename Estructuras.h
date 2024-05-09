#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

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
void mostrarMarcas(const vector<precios_marcas>& precios, const string& tipo_vehiculo);


#endif