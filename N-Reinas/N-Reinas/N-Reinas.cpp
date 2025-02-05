// N-Reinas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

#define MAXCANDIDATOS 100 // max cantidad de candidatos
#define NMAX 20 // máximo tamaño del tablero

int nroSol; // cuenta soluciones
void imprimeSolucion(int a[], int n) {
	//cout << "Solucion: " << nroSol << endl;
	nroSol++;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == a[j]) 
				cout << "R ";
			else 
				cout << "- ";
		}
		cout << endl;
	}
	cout << "==================" << endl;
}
void contador(int a[], int n) {
	nroSol++;
}
int construyeCandidatos(int a[], int k, int n, int c[]) {
	int i, j, ncandidatos = 0;
	for (i = 0; i < n; i++) {
		int band = 1;
		for (j = 0; j < k; j++) {
			/* restriccion de diagonal restriccion de fila */
			if (abs(k - j) == abs(i - a[j]) || i == a[j])
				band = 0;
		}
		if (band) {
			c[ncandidatos] = i;
			ncandidatos++;
		}
	}
	return ncandidatos;
}
void backtrack(int a[], int k, int n) {
	int i;
	int c[MAXCANDIDATOS];
	if (k == n) {
		imprimeSolucion(a, k);
		system("PAUSE");
	}
	else {
		int ncandidates = construyeCandidatos(a, k, n, c);
		for (i = 0; i < ncandidates; i++) {
			a[k] = c[i];
			backtrack(a, k + 1, n);
		}
	}
}
void program(int dim) {
	int a[NMAX], n;
	n = dim;
	nroSol = 0;
	backtrack(a, 0, n);
	cout << "Numero de Soluciones: " << nroSol << endl;
	//imprimeSolucion(a, n);
}
int main() {
	/*unsigned t0, t1;

	for (int i = 1; i <= 15; ++i) {
		t0 = clock();
		program(i);
		t1 = clock();

		double time = (double(t1 - t0) / CLOCKS_PER_SEC);
		cout << "Execution con dim = a " << i << ": " << time << endl;
	}*/


	program(11);
	return 0;
}