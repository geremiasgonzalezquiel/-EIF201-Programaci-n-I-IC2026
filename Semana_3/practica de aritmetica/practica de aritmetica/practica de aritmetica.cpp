#include <iostream>
using namespace std;

void imprimirTodo(int* arr, int n) {
	for (size_t i = 0; i < n; ++i) {
		std::cout << *(arr + i);
	}
}

int encontrarMaximo(int* arr, int n) {
	int max = *arr;
	for (int i = 0; i < n; i++) {
		if (max < *(arr + 1)) {
			max = *(arr + 1);
		}
	}
	return max;

}

void invertir(int* arr, int n) {
	int* izq = arr;
	int* der = arr + (n - 1);

	while (izq < der) {
		int temp = *izq;
		*izq = *der;
		*der = temp;
		izq++;
		der--;
	}



}

		int main(){
			int datos[6] = { 10, 30, 50, 20, 40, 60 };
			imprimirTodo(datos, 6);
			cout << encontrarMaximo(datos, 6) << endl;
			invertir(datos, 6);
			imprimirTodo(datos, 6);
			return 0;
		}