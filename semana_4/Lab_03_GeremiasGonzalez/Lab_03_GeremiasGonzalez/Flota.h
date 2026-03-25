#ifndef Flota_h
#define Flota_h

#include "Vehiculo.h"
#include <string>

namespace UNA {

    class Flota {
    private:
        Vehiculo** vehiculos;
        int cantidad;
        int capacidad;

        void redimensionar();

    public:
        Flota();
        ~Flota();

        void agregar(Vehiculo* nuevo);
        Vehiculo* buscarPorPlaca(std::string placa);
        void mostrarPorMarca(std::string marca);
        bool eliminar(std::string placa);
        int contarActivos() const;
        void mostrarTodos() const;
    };

}

#endif