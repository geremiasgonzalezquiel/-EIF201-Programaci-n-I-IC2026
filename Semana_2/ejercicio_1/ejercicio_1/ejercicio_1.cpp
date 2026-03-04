#include <iostream>
#include "Estadisticas.h"

void llenarDatos(int arreglo[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Ingrese 10 numeros enteros " << i + 1 << ": ";
        std::cin >> arreglo[i];
    }
}

int obtenerMayor(int arreglo[], int size) {
    int mayor = arreglo[0];
    for (int i = 1; i < size; i++)
        if (arreglo[i] > mayor) mayor = arreglo[i];
    return mayor;
}

int obtenerMenor(int arreglo[], int size) {
    int menor = arreglo[0];
    for (int i = 1; i < size; i++)
        if (arreglo[i] < menor) menor = arreglo[i];
    return menor;
}

int calcularSuma(int arreglo[], int size) {
    int suma = 0;
    for (int i = 0; i < size; i++)
        suma += arreglo[i];
    return suma;
}

double calcularPromedio(int arreglo[], int size) {
    return static_cast<double>(calcularSuma(arreglo, size)) / size;
}

int main() {
    int numeros[MAX_SIZE];

    llenarDatos(numeros, MAX_SIZE);

    std::cout << "\n----- RESULTADOS -----\n";
    std::cout << "Valor mayor: " << obtenerMayor(numeros, MAX_SIZE) << std::endl;
    std::cout << "Valor menor: " << obtenerMenor(numeros, MAX_SIZE) << std::endl;
    std::cout << "Suma total: " << calcularSuma(numeros, MAX_SIZE) << std::endl;
    std::cout << "Promedio: " << calcularPromedio(numeros, MAX_SIZE) << std::endl;

    return 0;
}
