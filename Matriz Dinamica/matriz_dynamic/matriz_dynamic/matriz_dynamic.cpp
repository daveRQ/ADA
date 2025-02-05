#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool leer_fichero_vector(string &fraseTotal) {
	fstream ficheroEntrada;
	string nombre;
	string frase;

	cout << "Dime el nombre del fichero: ";
	getline(cin, nombre);

	ficheroEntrada.open(nombre.c_str(), ios::in);
	if (ficheroEntrada.is_open()) {
		while (!ficheroEntrada.eof()) {
			getline(ficheroEntrada, frase);
			fraseTotal += frase + '\n';
		}
		ficheroEntrada.close();
		return true;
	}
	return false;
}

vector<int> vector_matriz(string linea) {
	vector<string> v_matriz;
	vector<int> v;

	size_t found;

	while (linea.find(',') < linea.size()) {
		found = linea.find(",");	
		v_matriz.push_back(linea.substr(0, found));
		linea = linea.substr(found + 1, linea.size());
	}
	v_matriz.push_back(linea);

	for (int i = 0; i < v_matriz.size(); i++)
		v.push_back(stoi(v_matriz[i]));
	return v;
}

void costo_mult_matrices(vector<int> vec) {
	int N = vec.size();
	int **m = new int *[N]();
	m[0] = new int[N * N]();
	for (int i = 1; i < N; ++i)
		m[i] = m[i - 1] + N;

	int MaxInt = 2147483647;

	for (int i = 1; i < N; i++)
		m[i][i] = 0;
	for (int h = 1; h < (N - 1); h++) {
		for (int i = 1; i < (N - h); i++) {
			int j = i + h;
			m[i][j] = MaxInt;
			for (int k = i; k < j; k++) {
				int temp = m[i][k] + m[k + 1][j] + (vec[i - 1] * vec[k] * vec[j]);
				if (temp < m[i][j])
					m[i][j] = temp;
			}
		}
	}

	string recorrido = "";

	for (int h = 2; h <= N; h++) {
		int menor = -1;
		for (int i = 1, j = h; j <= N; j++, i++) {
			
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << m[i][j] << "  ";
		}
		cout << endl;
	}
}

int main() {
	string vec;
	if (leer_fichero_vector(vec)) {
		vector<int> v = vector_matriz(vec);
		costo_mult_matrices(v);
	}
		
	else
		cout << "ERROR" <<endl;

	system("PAUSE");
	return 0;
}