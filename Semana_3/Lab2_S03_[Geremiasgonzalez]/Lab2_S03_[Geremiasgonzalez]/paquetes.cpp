#include "paquetes.h"
#include <iostream>

double* crearRegistro(int& cantidad)
{
    
    std::cout << "| Sistema de Control de Pesos de Paquetes|" << std::endl;


    std::cout << "Ingrese la cantidad de paquetes: ";
    std::cin >> cantidad;

    while (cantidad <= 0)
    {
        std::cout << "Error: debe ser mayor a cero, intentelo de nuevo: ";
        std::cin >> cantidad;
    }


    double* pesos = new double[cantidad];

    return pesos;
}

void ingresarPesos(double* pesos, int cantidad)
{
    std::cout << std::endl << "Ingrese el peso de cada paquete en kilogramos:" << std::endl;

    for (int i = 0; i < cantidad; i++)
    {
        std::cout << "  Paquete " << (i + 1) << ": ";
        std::cin >> pesos[i];


        while (pesos[i] <= 0)
        {
            std::cout << "  Error: el peso debe ser mayor a cero. Ingrese de nuevo: ";
            std::cin >> pesos[i];
        }
    }
}

double calcularPesoTotal(const double* pesos, int cantidad)
{
    double total = 0.0;

    for (int i = 0; i < cantidad; i++)
    {
        total += pesos[i];
    }

    return total;
}

int contarSobreLimite(const double* pesos, int cantidad, double limite)
{
    int contador = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (pesos[i] > limite)
        {
            contador++;
        }
    }

    return contador;
}


const double* buscarMasPesado(const double* pesos, int cantidad)
{

    int posMayor = 0;

    for (int i = 1; i < cantidad; i++)
    {
        if (pesos[i] > pesos[posMayor])
        {
            posMayor = i;
        }
    }

 
    return &pesos[posMayor];
}