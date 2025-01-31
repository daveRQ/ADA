// ADA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <iostream>
#include <ctime>

using namespace std;

// rvhmora@ucsp.edu.pe


void heap_sort(int *a, int tam) {
	for (int k = tam; k > 0; k--) {
		for (int i = 1; i <= k; i++) {
			int num = a[i - 1];
			int j = i / 2;
			while (j > 0 && a[j - 1] < num) {
				a[i - 1] = a[j - 1];
				i = j;
				j = j / 2;
			}
			a[i - 1] = num;
		}
		int temp = a[0];
		a[0] = a[k - 1];
		a[k - 1] = temp;
	}
}


void aleatorio(int* a, int tam) {
	for (int i = 0; i < tam; i++) {
		a[i] = 0 + (rand() % 100);
	}
	cout << endl;
}

void print_arr(int* a, int tam) {
	for (int i = 0; i < tam; i++) {
		cout << a[i] << "   ";
	}
	cout << endl;
}


int main()
{
	srand(time(0));

	int pruebas = 5;

	cout << "ESTAS SON LAS PRUEBAS DEL EJERCICIO" << endl;
	for (int i = 1; i <= pruebas; i++) {
		int tam = 5 + (rand() % 10);
		int* a = new int[tam];
		aleatorio(a, tam);
		cout << "Lista desordenada" << endl;
		print_arr(a, tam);
		cout << "Esta es la lista ordenada" << endl;
		heap_sort(a, tam);
		print_arr(a, tam);
		cout << endl;
	}







	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
