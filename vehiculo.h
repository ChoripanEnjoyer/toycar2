#include <string>
#include <vector>
#include "Estructuras.h"
using namespace std;

class Vehiculo
{
    protected:
    int cantidad_ruedas;
    string marca;
    bool control_remoto;
    int year_fabricacion;
    int precio;
    public:
    Vehiculo(int crear_ruedas, string crear_mark, bool crear_control, int crear_ano_fab): cantidad_ruedas(crear_ruedas), marca(crear_mark), control_remoto(crear_control), year_fabricacion(crear_ano_fab),precio(0) {}
    ~Vehiculo();
    virtual Vehiculo* crearNuevoVehiculo();
    // Getters
    int get_cantidad_ruedas() const { return cantidad_ruedas; }
    string get_marca() const { return marca; }
    bool get_control_remoto() const { return control_remoto; }
    int get_year_fabricacion() const { return year_fabricacion; }
    int get_precio() const { return precio; }
    // sett para modificar precio segun marca vehiculo
    void set_cantidad_ruedas() const { cantidad_ruedas; }
    void set_precio(int nuevo_precio) { precio = nuevo_precio; }
};

class Auto: public Vehiculo
{
    protected:
    int Cantidad_puertas;
    int Cantidad_luces;
    public:
    Auto(int crear_ruedas, string crear_mark, bool crear_control, int crear_ano_fab,int precio, int crea_puerta, int crea_luz) : Vehiculo(crear_ruedas, crear_mark, crear_control, crear_ano_fab), Cantidad_puertas(crea_puerta), Cantidad_luces(crea_luz) {}
    Auto* crearNuevoVehiculo();

    ~Auto();
    // Getters 
    int get_cantidad_puertas() const { return Cantidad_puertas; }
    int get_cantidad_luces() const { return Cantidad_luces; }
};

class Moto: public Vehiculo
{
    protected:
    int cantidad_espejos;
    int cantidad_pedales;
    public:
    Moto(int crear_ruedas, string crear_mark, bool crear_control, int crear_ano_fab, int crea_espejo, int crea_pedal) : Vehiculo(crear_ruedas, crear_mark, crear_control, crear_ano_fab), cantidad_espejos(crea_espejo), cantidad_pedales(crea_pedal) {}
    Moto* crearNuevoVehiculo();
    void escribir_info(const Vehiculo& vehiculo);
    ~Moto();
    //Getters
    int getcantidad_espejos() const { return cantidad_espejos; }
    int getcantidad_pedales() const { return cantidad_pedales; }
    


};

class Camion: public Vehiculo
{
    int cantidad_ejes;
    int cantidad_tolvas;
    public:
    Camion(int crear_ruedas, string crear_mark, bool crear_control, int crear_ano_fab, int crea_eje, int crea_tolva) : Vehiculo(crear_ruedas, crear_mark, crear_control, crear_ano_fab),  cantidad_ejes(crea_eje), cantidad_tolvas(crea_tolva) {}
    Camion* crearNuevoVehiculo();
    void escribir_info(ofstream& fichero);
    ~Camion();
    //Getters
    int getcantidad_ejes() const { return cantidad_ejes; }
    int getcantidad_tolvas() const { return cantidad_tolvas; }

};
void mostrar_datos(const string& nombre_archivo);
int contarVehiculos(const vector<Vehiculo*>& lista_vehiculos);
vector<Vehiculo*> almacenarVehiculo(vector<Vehiculo*>& lista_vehiculos, Vehiculo* nuevo_vehiculo,vector<precios_marcas>& precios);


