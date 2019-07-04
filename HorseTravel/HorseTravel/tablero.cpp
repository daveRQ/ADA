#include "pch.h"
#include "tablero.h"


tablero::tablero(int _N) {
	N = _N;
	cont = N * N;

	int **m = new int *[N]();
	m[0] = new int[N * N]();
	for (int i = 1; i < N; ++i)
		m[i] = m[i - 1] + N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			tab[i][j] = 0;
	}

	ejex = new int[8];
	ejey = new int[8];

	ejex[0] = -1;
	ejex[1] = -2;
	ejex[2] = -2;
	ejex[3] = -1;
	ejex[4] = 1;
	ejex[5] = 2;
	ejex[6] = 2;
	ejex[7] = 1;

	ejey[0] = -2;
	ejey[1] = -1;
	ejey[2] = 1;
	ejey[3] = 2;
	ejey[4] = 2;
	ejey[5] = 1;
	ejey[6] = -1;
	ejey[7] = -2;
}


tablero::~tablero() {

}

void tablero::mover(int i, int pos_x, int pos_y, int * q) {
	int k, u, v;

	k = 0;
	*q = 0;
	do {
		u = pos_x + ejex[k]; v = pos_y + ejey[k]; /* seleccionar candidato */
		if (u >= 0 && u < N && v >= 0 && v < N) { /* esta dentro de los limites? */
			if (tab[u][v] == 0) {  /* es valido? */
				tab[u][v] = i;  /* anota el candidato */
				if (i < cont) {  /* llega al final del recorrido? */
					mover(i + 1, u, v, q);
					if (!*q) tab[u][v] = 0; /* borra el candidato */
				}
				else *q = 1; /* hay solucion */
			}
		}
		k++;
	} while (!*q && k < 8);
}

void tablero::Horse(int _pos_y, int _pos_x) {
	p_y = _pos_y;
	p_x = _pos_x;
	
	tab[p_y][p_x] = 1;
	int q;
	mover(2, p_y, p_x, &q);

	if (q) { /* hay solucion: la muestra. */
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				printf("%3d ", tab[i][j]);
			cout << endl;
		}
	}
	else
		cout << "\nNo existe solucion" << endl;;

}