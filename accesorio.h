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

vector<Accesorio> leerAccesoriosDesdeArchivo(const string& nombre_archivo);

void mostrarAccesorios(const vector<Accesorio>& accesorios);


#endif