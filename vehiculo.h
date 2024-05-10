#include <string>
#include <iostream>
#include <vector>
#include "Estructuras.h"
using namespace std;

 
class Vehiculo {
protected:
    int cantidad_ruedas;
    string marca;
    bool control_remoto;
    int year_fabricacion;
    int precio;

public:
    Vehiculo(int ruedas, string marca, bool control, int ano_fab, int precio): cantidad_ruedas(ruedas), marca(marca), control_remoto(control), year_fabricacion(ano_fab), precio(precio) {}

    virtual ~Vehiculo() {}

    string get_marca() const { return marca; }
    int get_precio() const { return precio; }
    void setMarca() const { marca; }
    void setPrecio() const { precio; }
};

class Auto : public Vehiculo {
protected:
    int cantidad_puertas;
    int cantidad_luces;
    vector<Accesorio> accesorios;

public:
    Auto(int ruedas, string marca, bool control, int ano_fab, int precio, int puertas, int luces, const vector<Accesorio>& accs) : Vehiculo(ruedas, marca, control, ano_fab, precio), cantidad_puertas(puertas), cantidad_luces(luces), accesorios(accs) {}

    virtual ~Auto() {}


};

class Moto : public Vehiculo {
protected:
    int cantidad_pedales;
    int cantidad_espejos;
    vector<Accesorio> accesorios;

public:
    Moto(int ruedas,string marca, bool control, int ano_fab, int precio, int pedales, int espejos)
        : Vehiculo(ruedas, marca, control, ano_fab, precio), cantidad_pedales(pedales), cantidad_espejos(espejos) {}

    virtual ~Moto() {}

};

class Camion : public Vehiculo {
protected:
    int cantidad_Tolvas; // Tolva o Caja
    int cantidad_ejes;
    vector<Accesorio> accesorios;
public:
    Camion(int ruedas,string marca, bool control, int ano_fab, int precio,int caja, int ejes): Vehiculo(ruedas, marca, control, ano_fab, precio), cantidad_Tolvas(caja), cantidad_ejes(ejes) {}

    virtual ~Camion() {}

};
void mostrar_datos(const string& nombre_archivo);
int contarVehiculos(const vector<Vehiculo*>& lista_vehiculos);
vector<Vehiculo*> almacenarVehiculo(vector<Vehiculo*>& lista_vehiculos, Vehiculo* nuevo_vehiculo,vector<precios_marcas>& precios);
void mostrarListaVehiculos(const vector<Vehiculo*>& lista_vehiculos);
int calcularMontoTotal(vector<precios_marcas>& precios, string tipo_vehiculo, string marca_seleccionada, int cant_vehi);
