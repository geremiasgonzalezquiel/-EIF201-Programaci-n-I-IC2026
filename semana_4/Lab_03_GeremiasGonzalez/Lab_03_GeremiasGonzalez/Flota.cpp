#include "Flota.h"
#include <iostream>

namespace UNA {

    Flota::Flota() : cantidad(0), capacidad(3) {
        vehiculos = new Vehiculo * [capacidad];
    }

    Flota::~Flota() {
        for (int i = 0; i < cantidad; i++) {
            delete vehiculos[i];
        }
        delete[] vehiculos;
    }

    void Flota::redimensionar() {
        int nuevaCapacidad = capacidad * 2;
        Vehiculo** nuevo = new Vehiculo * [nuevaCapacidad];
        for (int i = 0; i < cantidad; i++) {
            nuevo[i] = vehiculos[i];
        }
        delete[] vehiculos;
        vehiculos = nuevo;
        capacidad = nuevaCapacidad;
        std::cout << "[Sistema] Arreglo redimensionado. Nueva capacidad: " << capacidad << std::endl;
    }

    void Flota::agregar(Vehiculo* nuevo) {
        if (cantidad == capacidad) {
            redimensionar();
        }
        vehiculos[cantidad++] = nuevo;
        std::cout << "Vehiculo " << nuevo->getPlaca() << " agregado a la flota." << std::endl;
    }

    Vehiculo* Flota::buscarPorPlaca(std::string placa) {
        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getPlaca() == placa) {
                return vehiculos[i];
            }
        }
        return nullptr;
    }

    void Flota::mostrarPorMarca(std::string marca) {
        int encontrados = 0;
        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getMarca() == marca) {
                vehiculos[i]->mostrar();
                encontrados++;
            }
        }
        if (encontrados == 0) {
            std::cout << "No hay vehiculos de la marca \"" << marca << "\" en la flota." << std::endl;
        }
        else {
            std::cout << "Total de vehiculos encontrados de la marca \"" << marca << "\": " << encontrados << std::endl;
        }
    }

    bool Flota::eliminar(std::string placa) {
        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getPlaca() == placa) {
                if (vehiculos[i]->getActivo()) {
                    std::cout << "Error: El vehiculo " << placa
                        << " aun esta activo. Primero debe desactivarse antes de darlo de baja." << std::endl;
                    return false;
                }

                
                delete vehiculos[i];

              
                for (int j = i; j < cantidad - 1; j++) {
                    vehiculos[j] = vehiculos[j + 1];
                }
                vehiculos[cantidad - 1] = nullptr;
                cantidad--;

                std::cout << "Vehiculo " << placa << " eliminado de la flota." << std::endl;
                return true;
            }
        }
        std::cout << "Vehiculo con placa \"" << placa << "\" no encontrado." << std::endl;
        return false;
    }

    int Flota::contarActivos() const {
        int activos = 0;
        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getActivo()) activos++;
        }
        return activos;
    }

    void Flota::mostrarTodos() const {
        if (cantidad == 0) {
            std::cout << "La flota esta vacia. No hay vehiculos registrados." << std::endl;
            return;
        }
        std::cout << "=== FLOTA COMPLETA (" << cantidad << " vehiculo(s)) ===" << std::endl;
        for (int i = 0; i < cantidad; i++) {
            vehiculos[i]->mostrar();
        }
    }

}