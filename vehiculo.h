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
    virtual void setMarca(int new_marca)
    {
        marca = new_marca;
    }
    virtual void setPrecio(int new_precio) 
    {
        precio = new_precio;
    }
};

class Auto : public Vehiculo {
protected:
    int cantidad_puertas;
    int cantidad_luces;
    vector<Accesorio> accesorios;

public:
    Auto(int ruedas, string marca, bool control, int ano_fab, int precio, int puertas, int luces) : Vehiculo(ruedas, marca, control, ano_fab, precio), cantidad_puertas(puertas), cantidad_luces(luces){}

    virtual ~Auto() {}
        // Getters 
    int get_cantidad_puertas() const { return cantidad_ruedas; }
    int get_cantidad_luces() const { return cantidad_luces; }
    void setPuertas(int puertas) 
    {
        cantidad_puertas = puertas;
    }

    void setLuces(int luces) 
    {
        cantidad_luces = luces;
    }
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
    //Getters
    int getcantidad_espejos() const { return cantidad_espejos; }
    int getcantidad_pedales() const { return cantidad_pedales; }
    void setpedal(int pedales) 
    {
        cantidad_pedales = pedales;
    }

    void setespejo(int espejos) 
    {
        cantidad_espejos = espejos;
    }
};

class Camion : public Vehiculo {
protected:
    int cantidad_Tolvas; // Tolva o Caja
    int cantidad_ejes;
    vector<Accesorio> accesorios;
public:
    Camion(int ruedas,string marca, bool control, int ano_fab, int precio,int caja, int ejes): Vehiculo(ruedas, marca, control, ano_fab, precio), cantidad_Tolvas(caja), cantidad_ejes(ejes) {}

    virtual ~Camion() {}
    //Getters
    int getcantidad_ejes() const { return cantidad_ejes; }
    int getcantidad_tolvas() const { return cantidad_Tolvas; }
    void seteje(int caja) 
    {
        cantidad_Tolvas = caja;
    }

    void settolva(int ejes) 
    {
        cantidad_ejes = ejes;
    }
};
void mostrar_datos(const string& nombre_archivo);
int contarVehiculos(const vector<Vehiculo*>& lista_vehiculos);
vector<Vehiculo*> almacenarVehiculo(vector<Vehiculo*>& lista_vehiculos, Vehiculo* nuevo_vehiculo,vector<precios_marcas>& precios);
void mostrarListaVehiculos(const vector<Vehiculo*>& lista_vehiculos);
int calcularMontoTotal(const vector<precios_marcas>& precios, const vector<Vehiculo*>& lista_vehiculos);
int calcularMontoTotalAccesorios(const vector<Accesorio>& lista_accesorios);

