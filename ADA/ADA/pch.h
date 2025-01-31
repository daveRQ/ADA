// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

#include <iostream>
// TODO: add headers that you want to pre-compile here

#endif //PCH_H


// Merge EJERCICIO 1
void merge(int* arr, int ini, int m, int fin) {
	int i = ini, f = m + 1;
	int* temp = new int[fin - ini + 1];
	int i_t = 0;// iterador de temp
	while (i <= m && f <= fin) {
		if (arr[i] < arr[f]) {
			temp[i_t] = arr[i];
			++i;
		}
		else {
			temp[i_t] = arr[f];
			++f;
		}
		++i_t;
	}
	/*if (i == m)
		temp[i_t] = arr[i];
	else
		temp[i_t] = arr[f];*/
	while (i <= m) {
		temp[i_t] = arr[i];
		++i;
		++i_t;
	}
	while (f <= fin) {
		temp[i_t] = arr[f];
		++f;
		++i_t;
	}

	for (int i = ini; i <= fin; i++)
		arr[i] = temp[i - ini];
}
void merge_sort(int* arr, int ini, int fin) {
	if (ini < fin) {
		int m = (ini + fin) / 2;
		merge_sort(arr, ini, m);
		merge_sort(arr, m + 1, fin);
		merge(arr, ini, m, fin);
	}
}

// EJERCICIO 2
void merge_var(int* arr, int ini, int m, int fin) {
	int i = ini, f = m + 1;
	int* temp = new int[m - ini + 1];
	int i_t = 0;// iterador de temp
	while (i_t < (m - ini + 1)) {
		if (arr[i] < arr[f]) {
			temp[i_t] = arr[i];
			++i;
		}
		else {
			temp[i_t] = arr[f];
			++f;
		}
		++i_t;
	}
	while (i <= m && f <= fin) {
		if (arr[i] < arr[f]) {
			arr[i_t + ini] = arr[i];
			++i;
		}
		else {
			arr[i_t + ini] = arr[f];
			++f;
		}
		++i_t;
	}
	while (i <= m) {
		arr[i_t + ini] = arr[i];
		++i;
		++i_t;
	}
	while (f <= fin) {
		arr[i_t + ini] = arr[f];
		++f;
		++i_t;
	}
	for (int i = 0; i < (m - ini + 1); i++)
		arr[i + ini] = temp[i];
}
void merge_sort_var(int* arr, int ini, int fin) {
	if (ini < fin) {
		int m = (ini + fin) / 2;
		merge_sort_var(arr, ini, m);
		merge_sort_var(arr, m + 1, fin);
		merge_var(arr, ini, m, fin);
	}
}

