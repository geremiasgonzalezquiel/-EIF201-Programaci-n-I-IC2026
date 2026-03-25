#include "Vehiculo.h"
#include <iostream>

namespace UNA {


	UNA::Vehiculo::Vehiculo(std::string placa, std::string marca, int anio, double kilometraje, bool avtivo):placa(placa), marca(marca),
		anio(anio),Kilometraje(kilometraje), activo(true){}

	std::string Vehiculo::getPlaca() const { return placa; }
	std::string Vehiculo::getMarca() const { return marca; }
	int Vehiculo::getAnio() const { return anio; }
	double Vehiculo::getKilometraje() const { return Kilometraje; }
	bool Vehiculo::getActivo() const { return activo; }


	void UNA::Vehiculo::registrarKilometros(double km){
		if (!activo) {
			std::cout << "Error este vahiculo esta fuera de servicio" << placa << std::endl;
			return;
		}

		if (km <= 0) {
			std::cout << "error el numero de km tiene que ser mayor a cero";
			return;
		}

		Kilometraje += km;
		std::cout << "Total de Kilometraje sumado" << Kilometraje << std::endl;


	}

	void UNA::Vehiculo::desactivar(){
		if (!activo) {
			std::cout << "El vehiculo" << placa << "se encuentra fuera de servicio"<< std::endl;
			return;

		}
		activo = false;
		std::cout << "Vehiculo" << placa << "desactivado correctamente" << std::endl;

	}

	void UNA::Vehiculo::reactivar(){
		if (activo) {
			std::cout << "El vehiculo" << placa << "ya esta activo" << std::endl;
			return;

		}

		activo = true;
		std::cout << "Vehiculo" << placa << "Se reactivo correctamente" << std::endl;

	}

	void UNA::Vehiculo::mostrar() const{
		std::cout << "----------------" << std::endl;
		std::cout << "placa       :" << placa << std::endl;
		std::cout << "Marca       :" << marca << std::endl;
		std::cout << "Anio        :" << anio << std::endl;
		std::cout << "Kilimetraje :" << Kilometraje << std::endl;
		std::cout << "Estado      :" << (activo ? "activo": "fuera de servicio") << std::endl;
		std::cout << "------------------" << std::endl;


	}

}