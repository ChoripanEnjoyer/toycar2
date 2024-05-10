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
    int cantidad;
};

struct precios_marcas
{
    string Tipo_vehiculo;
    string Marca_vehiculo;
    int Precio_marca;
};

vector<Accesorio> leerAccesoriosDesdeArchivo(const string& nombre_archivo);
vector<precios_marcas> Leer_precios(const string& nombre_archivo);
void mostrarAccesorios(const vector<Accesorio>& lista_accesorios);
void mostrarMarcas(const vector<precios_marcas>& precios, const string& tipo_vehiculo);
vector<Accesorio> almacenarAccesorios(vector<Accesorio>& lista_accesorios, const vector<Accesorio>& accesorios_cliente);
void mostrarAccesorioscompra(const vector<Accesorio>& accesorios);



#endif