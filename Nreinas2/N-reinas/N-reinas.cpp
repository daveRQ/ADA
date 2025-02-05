// N-reinas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>

using namespace std;


class Tablero {
public:
	char **tablero;
	int tam;
	int queen;

	// Constructor
	Tablero(int _tam) {
		tam = _tam;
		queen = 0;
		// Creando Tablero
		tablero = new char *[tam]();
		tablero[0] = new char[tam * tam]();
		for (int i = 1; i < tam; ++i)
			tablero[i] = tablero[i - 1] + tam;

		// Inicializa el tablero a ' '
		for (int i = 0; i < tam; i++) {
			for (int j = 0; j < tam; j++)
				tablero[i][j] = ' ';
		}
	}

	void add_queen(int x, int y) {
		for (int i = 0; i < tam; ++i)
			tablero[y - 1][i] = '-';
		for (int i = 0; i < tam; ++i)
			tablero[i][x - 1] = '-';
		for (int j = x - 1, i = y - 1; i < tam && j < tam; ++i, ++j)
			tablero[i][j] = '-';
		for (int j = x - 1, i = y - 1; i > -1 && j < tam; --i, ++j)
			tablero[i][j] = '-';
		for (int j = x - 1, i = y - 1; i > -1 && j > -1; --i, --j)
			tablero[i][j] = '-';
		for (int j = x - 1, i = y - 1; i < tam && j > -1; ++i, --j)
			tablero[i][j] = '-';

		tablero[y - 1][x - 1] = 'R';
	}
	void remove_queen(int x, int y) {
		for (int i = 0; i < tam; ++i)
			tablero[y - 1][i] = ' ';
		for (int i = 0; i < tam; ++i)
			tablero[i][x - 1] = ' ';
		for (int j = x - 1, i = y - 1; i < tam && j < tam; ++i, ++j)
			tablero[i][j] = ' ';
		for (int j = x - 1, i = y - 1; i > -1 && j < tam; --i, ++j)
			tablero[i][j] = ' ';
		for (int j = x - 1, i = y - 1; i > -1 && j > -1; --i, --j)
			tablero[i][j] = ' ';
		for (int j = x - 1, i = y - 1; i < tam && j > -1; ++i, --j)
			tablero[i][j] = ' ';

		tablero[y - 1][x - 1] = ' ';
	}

	// N-Reinas
	bool full_queen(int x, int y) {
		
		add_queen(x, y);
		queen++;

		if (queen == tam)
			return true;
		
		for (int i = 0; i < tam; ++i) {
			if (tablero[y][i] == ' ') {
				
				if (full_queen(i + 1, (y % tam) + 1) == true)
					return true;
				remove_queen(i + 1, (y % tam) + 1);
				queen--;
				for (int j = 0; j < tam; ++j) {
					for (int k = 0; k < tam; ++k) {
						if (tablero[j][k] == 'R')
							add_queen(k + 1, j + 1);
					}
				}			
			}
		}		
	}

	void show() {
		//cout << "  ";
		//for (int i = 1; i <= tam; ++i)
		//	cout << i << ' ';
		//cout << endl;
		for (int i = 0; i < tam; i++) {
			cout << /*i + 1 <<*/ "|";
			for (int j = 0; j < tam; j++) {
				cout << tablero[i][j] << '|';
			}
			cout << endl;
		}
	}
};

int main() {
	Tablero A(30);

	A.full_queen(3, 1);
	A.show();

	system("PAUSE");
	return 0;
}