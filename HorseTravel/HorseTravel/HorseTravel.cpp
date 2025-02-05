// HorseTravel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <ctime>

const int ejex[8] = { -1,-2,-2,-1, 1, 2, 2, 1 }, ejey[8] = { -2,-1, 1, 2, 2, 1,-1,-2 };

void mover(int** tablero, int N, int i, int pos_x, int pos_y, bool *q) {
	int k, u, v;
	k = 0;
	*q = 0;
	do {	
		u = pos_x + ejex[k]; v = pos_y + ejey[k]; /* seleccionar candidato */
		if (u >= 0 && u < N && v >= 0 && v < N) { /* esta dentro de los limites? */
			if (tablero[u][v] == 0) {  /* es valido? */
				tablero[u][v] = i;  /* anota el candidato */
				if (i < (N * N)) {  /* llega al final del recorrido? */
					mover(tablero, N, i + 1, u, v, q);
					if (!*q) tablero[u][v] = 0; /* borra el candidato */
				}
				else *q = 1; /* hay solucion */
			}
		}
		k++;
	} while (!*q && k < 8);
}

void program(int N) {

	/* tablero del caballo. */
	int **tablero = new int *[N]();
	tablero[0] = new int[N * N]();
	for (int i = 1; i < N; ++i)
		tablero[i] = tablero[i - 1] + N;

	bool q;

	/* inicializa el tablero a cero */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			tablero[i][j] = 0;
	}

	/* pone el primer movimiento */

	tablero[0][0] = 1;
	mover(tablero, N, 2, 0, 0, &q);

	if (q) { /* hay solucion: la muestra. */
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				printf("%3d ", tablero[i][j]);
			cout << endl;
		}
	}
	else
		cout << "\nNo existe solucion" << endl;
}

int main() {
	unsigned t0, t1;

	for (int i = 1; i < 9; ++i) {
		t0 = clock();
		program(i);
		t1 = clock();

		double time = (double(t1 - t0) / CLOCKS_PER_SEC);
		cout << "Execution con dim = a " << i << ": " << time << endl;
	}

	return 0;
}

