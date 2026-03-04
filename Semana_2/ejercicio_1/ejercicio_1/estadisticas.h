#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

const int MAX_SIZE = 10;

void llenarDatos(int arreglo[], int size);
int obtenerMayor(int arreglo[], int size);
int obtenerMenor(int arreglo[], int size);
int calcularSuma(int arreglo[], int size);
double calcularPromedio(int arreglo[], int size);

#endif