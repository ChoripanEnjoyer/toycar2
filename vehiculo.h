#include <string>
#include <vector>
using namespace std;

class Vehiculo
{
    protected:
    int cantidad_ruedas;
    string marca;
    bool control_remoto;
    int year_fabricacion;
    Vehiculo(int ruedas, string mark, bool control, int ano_fab);
    ~Vehiculo();
    virtual void pedir_datos();
    virtual void mostrar_datos();
    Vehiculo *sig;

};

// vector<Vehiculo*> leerPreciosDesdeArchivo(const string& nombre_archivo);
void leerPreciosDesdeArchivo(const string& nombre_archivo);
void solicitar_vehiculo_usuario();
void insertar_vehiculo_en_lista();
void escribirInfoVehiculos();




class Auto: public Vehiculo
{
    protected:
    int Cantidad_puertas;
    int Cantidad_luces;
    public:
    Auto(int ruedas, string mark, bool control, int ano_fab,int puertas, int luces);
    void pedir_datos();
    ~Auto();
};

class Moto: public Vehiculo
{
    protected:
    int cantidad_espejos;
    int cantidad_pedales;
    public:
    Moto(int ruedas, string mark, bool control, int ano_fab, int espejos, int pedales);
    void pedir_datos();
    ~Moto();

};

class Camion: public Vehiculo
{
    int cantidad_ejes;
    int cantidad_tolvas;
    public:
    Camion(int ruedas, string mark, bool control, int ano_fab, int ejes, int tolvas);
    void pedir_datos();
    ~Camion();
};



