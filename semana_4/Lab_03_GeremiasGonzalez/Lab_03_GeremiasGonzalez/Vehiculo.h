#ifndef Vehiculo_h
#define Vehiculo_h

#include <string>

namespace UNA {


	class Vehiculo	{
	private:
		std::string placa;
		std::string marca;
		int anio;
		double Kilometraje;
		bool activo;

	public:
		Vehiculo(std::string placa, std::string marca, int anio, double kilometraje, bool activo);

		std::string getPlaca() const;
		std::string getMarca() const;
		int getAnio() const;
		double getKilometraje() const;
		bool getActivo() const;


		void registrarKilometros(double km);
		void desactivar();
		void reactivar();
		void mostrar() const;

	};


}



#endif