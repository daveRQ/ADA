// GrafoHash.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "CGrafoHash.h"
#include "Priority_Queue.h"
#include <ctime>

using namespace std;

void add_Nodes(CGrafoHash &G, int cant) {
	string Alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < Alfa.size() && i < cant; ++i)
		G.node_add(Alfa[i]);
}

int main() {
	CGrafoHash Grafo;
	
	add_Nodes(Grafo, 4);

	Grafo.edge_add('A', 'B', 3);
	Grafo.edge_add('A', 'D', 4);
	Grafo.edge_add('C', 'A', 2);
	Grafo.edge_add('D', 'C', 1);

	Grafo.dijkstra('A');
	
	
	return 0;
}
