#include <string>
#include <vector>

using namespace std;

class Vehiculo
{
    public:
    int cantidad_ruedas;
    string marca;
    bool control_remoto;
    int year_fabricacion;
    Vehiculo(int ruedas, string mark, bool control, int ano_fab);
    ~Vehiculo();
    void pedir_datos();
    void mostrar_datos();
    Vehiculo *sig;

};



