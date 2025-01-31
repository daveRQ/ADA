// Grafo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// estructura (facil agredado)
// lista de lista   (Si no se modifica es rapida)
// lista de adyacencia (Tiene q ser dispersa)
// par ordenado grafo dirigido (a, b) ; a, b son un puntero a Nodo 
// Matriz de adyacencia (update = facil) (insertar y borar = dificiles)


#include "pch.h"
#include "GrafoEstructural.h"

int main() {
	CGrafo<char, int> G;
	G.insert_Node('A');
	G.insert_Node('B');
	G.insert_Node('C');
	G.insert_Node('D');
	G.insert_Node('E');
	G.insert_Node('F');
	G.insert_Edge(7, G.n('A'), G.n('B'), 1);
	G.insert_Edge(9, G.n('A'), G.n('C'), 1);
	G.insert_Edge(14, G.n('A'), G.n('F'), 1);
	G.insert_Edge(10, G.n('B'), G.n('C'), 1);
	G.insert_Edge(15, G.n('B'), G.n('D'), 1);
	G.insert_Edge(11, G.n('C'), G.n('D'), 1);
	G.insert_Edge(2, G.n('C'), G.n('F'), 1);
	G.insert_Edge(6, G.n('D'), G.n('E'), 1);
	G.insert_Edge(9, G.n('E'), G.n('F'), 1);



	G.DFS_function();


	system("PAUSE");
	return 0;
}
