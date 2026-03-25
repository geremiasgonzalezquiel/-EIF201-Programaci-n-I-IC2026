#include <iostream>
#include <string>
#include "Flota.h"
#include "Vehiculo.h"

using namespace UNA;

int main() {
    Flota flota;
    int opcion;

    do {
        std::cout << "===== FlotaExpress =====" << std::endl;
        std::cout << "1. Registrar vehiculo" << std::endl;
        std::cout << "2. Buscar vehiculo por placa" << std::endl;
        std::cout << "3. Mostrar vehiculos por marca" << std::endl;
        std::cout << "4. Registrar kilometros" << std::endl;
        std::cout << "5. Desactivar vehiculo" << std::endl;
        std::cout << "6. Reactivar vehiculo" << std::endl;
        std::cout << "7. Eliminar vehiculo" << std::endl;
        std::cout << "8. Mostrar flota completa" << std::endl;
        std::cout << "9. Mostrar vehiculos activos" << std::endl;
        std::cout << "10. Salir" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        if (opcion == 1) {
            std::string placa, marca;
            int anio;
            double km;

            std::cout << "Placa: ";
            std::getline(std::cin, placa);
            std::cout << "Marca: ";
            std::getline(std::cin, marca);
            std::cout << "Anio: ";
            std::cin >> anio;
            std::cin.ignore();
            std::cout << "Kilometraje inicial: ";
            std::cin >> km;
            std::cin.ignore();

            Vehiculo* v = new Vehiculo(placa, marca, anio, km,true);
            flota.agregar(v);

        }
        else if (opcion == 2) {
            std::string placa;
            std::cout << "Placa: ";
            std::getline(std::cin, placa);
            Vehiculo* v = flota.buscarPorPlaca(placa);
            if (v != nullptr) {
                v->mostrar();
            }
            else {
                std::cout << "Vehiculo no encontrado." << std::endl;
            }

        }
        else if (opcion == 3) {
            std::string marca;
            std::cout << "Marca: ";
            std::getline(std::cin, marca);
            flota.mostrarPorMarca(marca);

        }
        else if (opcion == 4) {
            std::string placa;
            double km;
            std::cout << "Placa: ";
            std::getline(std::cin, placa);
            Vehiculo* v = flota.buscarPorPlaca(placa);
            if (v != nullptr) {
                std::cout << "Kilometros a agregar: ";
                std::cin >> km;
                std::cin.ignore();
                v->registrarKilometros(km);
            }
            else {
                std::cout << "Vehiculo no encontrado." << std::endl;
            }

        }
        else if (opcion == 5) {
            std::string placa;
            std::cout << "Placa: ";
            std::getline(std::cin, placa);
            Vehiculo* v = flota.buscarPorPlaca(placa);
            if (v != nullptr) {
                v->desactivar();
            }
            else {
                std::cout << "Vehiculo no encontrado." << std::endl;
            }

        }
        else if (opcion == 6) {
            std::string placa;
            std::cout << "Placa: ";
            std::getline(std::cin, placa);
            Vehiculo* v = flota.buscarPorPlaca(placa);
            if (v != nullptr) {
                v->reactivar();
            }
            else {
                std::cout << "Vehiculo no encontrado." << std::endl;
            }

        }
        else if (opcion == 7) {
            std::string placa;
            std::cout << "Placa: ";
            std::getline(std::cin, placa);
            flota.eliminar(placa);

        }
        else if (opcion == 8) {
            flota.mostrarTodos();

        }
        else if (opcion == 9) {
            std::cout << "Vehiculos activos: " << flota.contarActivos() << std::endl;

        }
        else if (opcion == 10) {
            std::cout << "Hasta luego." << std::endl;

        }
        else {
            std::cout << "Opcion invalida." << std::endl;
        }

    } while (opcion != 10);

    return 0;
}