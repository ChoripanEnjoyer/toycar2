#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "Estructuras.h"
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
vector<precios_marcas> Leer_precios(const string& nombre_archivo)
{
    vector<precios_marcas> Precios_Marcas;
    ifstream archivo(nombre_archivo);
    string linea;

    if (archivo.is_open()) 
    {
        while (getline(archivo, linea)) // lee cadenas de caracteres hasta que se encuentra un delimitador (aca la coma ,)
        {
            istringstream ss(linea);
            string Tipo, nombre_marca;
            int precio;

            // Parsear los datos de la línea
            if (getline(ss, Tipo, ',') && getline(ss, nombre_marca, ',') && (ss >> precio)) 
            {
                precios_marcas precio_marcas = {Tipo, nombre_marca, precio};// Crea el objeto Accesorio y agrega al vector
                Precios_Marcas.push_back(precio_marcas); //es una función miembro de los vectores en C++, se utiliza para agregar un nuevo elemento al final del vector.
            }
        }
        archivo.close();
    } 
    else 
    {
        cerr << "No se pudo abrir el archivo: " << nombre_archivo << endl;
    }

    return Precios_Marcas;
    //{{"Tipo de veh", "Marca", valor},{"AUTO", "Hyunday", 16000},{"AUTO", "Susuki", 12000},}
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
    for (const auto& accesorio : accesorios)// esto me autoconfundio mucho auto permite que el compilador determine automáticamente el tipo de una variable basándose en el tipo de la expresión a la que se está asignando.
    {
        cout << setw(15) << accesorio.Tipo << setw(20) << accesorio.nombre_acc << setw(10) << accesorio.Valor << endl;
    }

    cout << "----------------------------------------------------" << endl;
}


void mostrarMarcas(const vector<precios_marcas>& precios, const string& tipo_vehiculo)
{
    cout << "Marcas y precios de " << tipo_vehiculo << ":" << endl;

    // Recorrer el vector de precios
    for (const auto& precio : precios)
    {
        // Verificar si el tipo de vehículo coincide
        if (precio.Tipo_vehiculo == tipo_vehiculo)
        {
            // Mostrar la marca y el precio
            cout << "Marca: " << precio.Marca_vehiculo << ", Precio: " << precio.Precio_marca << endl;
        }
    }
    cout << "--------------------------------" << endl;
}

