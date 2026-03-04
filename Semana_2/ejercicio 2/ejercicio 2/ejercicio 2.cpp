#include <iostream>

void invertir(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[n - 1 - i];
    }
}

int main()
{
    int n;
    int a[20];
    int b[20];

    std::cout << "Ingrese el tamaño del arreglo (maximo 20): ";
    std::cin >> n;

    while (n > 20 || n <= 0)
    {
        std::cout << "Tamaño invalido. Ingrese otro: ";
        std::cin >> n;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << "Ingrese un numero: ";
        std::cin >> a[i];
    }

    invertir(a, b, n);

    std::cout << "Arreglo original: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }

    std::cout << "\nArreglo invertido: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << b[i] << " ";
    }

    return 0;
}