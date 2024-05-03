#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "accesorio.h"
using namespace std;


vector<Accesorio> leerAccesoriosDesdeArchivo(const string& nombre_archivo)
{
    vector<Accesorio> accesorios;
    ifstream archivo(nombre_archivo);
    string linea;

    if (archivo.is_open()) 
    {
        while (getline(archivo, linea)) // lee cadenas de caracteres hasta que se encuentra un delimitador (aca la coma ,)
        {
            istringstream ss(linea);//analiza una cadena de caracteres y separara en "tokens" 
            string tipo_vehiculo, nombre;
            int precio;

            // Parsear los datos de la línea
            if (getline(ss, tipo_vehiculo, ',') && getline(ss, nombre, ',') && (ss >> precio)) 
            {
                Accesorio accesorio = {tipo_vehiculo, nombre, precio};// Crea el objeto Accesorio y agrega al vector
                accesorios.push_back(accesorio); //es una función miembro de los vectores en C++, se utiliza para agregar un nuevo elemento al final del vector.
            }
        }
        archivo.close();
    } 
    else 
    {
        cerr << "No se pudo abrir el archivo: " << nombre_archivo << endl;
    }

    return accesorios;
}

void mostrarAccesorios(const vector<Accesorio>& accesorios) 
{

    if (accesorios.empty()) 
    {
        cout << "No hay accesorios para mostrar." << endl;
        return;
    }

    // Encabezado de la tabla de accesorios
    cout << "Accesorios:" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << setw(15) << "Tipo de vehículo" << setw(20) << "Nombre" << setw(10) << "Precio" << endl;
    cout << "----------------------------------------------------" << endl;

    // Itera sobre cada accesorio en el vector y muestra sus detalles
    for (const auto& accesorio : accesorios) 
    {
        cout << setw(15) << accesorio.Tipo << setw(20) << accesorio.nombre_acc << setw(10) << accesorio.Valor << endl;
    }

    cout << "----------------------------------------------------" << endl;
}
