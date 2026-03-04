#include <iostream>
#include <iomanip>

const int FILAS = 3;
const int COLS = 3;

void leerMatriz(int m[FILAS][COLS])
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cout << "Ingrese un numero: ";
            std::cin >> m[i][j];
        }
    }
}

void imprimirMatriz(int m[FILAS][COLS])
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            std::cout << std::setw(4) << m[i][j];
        }
        std::cout << std::endl;
    }
}

void sumaFilas(int m[FILAS][COLS])
{
    for (int i = 0; i < FILAS; i++)
    {
        int suma = 0;

        for (int j = 0; j < COLS; j++)
        {
            suma = suma + m[i][j];
        }

        std::cout << "Suma fila " << i + 1 << ": " << suma << std::endl;
    }
}

void sumaColumnas(int m[FILAS][COLS])
{
    for (int j = 0; j < COLS; j++)
    {
        int suma = 0;

        for (int i = 0; i < FILAS; i++)
        {
            suma = suma + m[i][j];
        }

        std::cout << "Suma columna " << j + 1 << ": " << suma << std::endl;
    }
}

void sumaDiagonal(int m[FILAS][COLS])
{
    int suma = 0;

    for (int i = 0; i < FILAS; i++)
    {
        suma = suma + m[i][i];
    }

    std::cout << "Suma diagonal: " << suma << std::endl;
}

int main()
{
    int matriz[FILAS][COLS];

    leerMatriz(matriz);

    std::cout << "\nMatriz ingresada:\n";
    imprimirMatriz(matriz);

    sumaFilas(matriz);
    sumaColumnas(matriz);
    sumaDiagonal(matriz);

    return 0;