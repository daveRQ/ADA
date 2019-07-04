#pragma once

#include "Pila.h"
#include "pch.h"
#include <vector>


// Grafo con aristas bidireccionales sin templates por el poco tiempo q tengo

class MEdge {
public:
	char vertices[2];
	int valor;
	MEdge(char ini, char fin, int _valor) {
		vertices[0] = ini;
		vertices[1] = fin;
		valor = _valor;
	}
};

class MGrafo {
public:
	std::vector<char> Nodes;
	std::vector<MEdge*> Edges;
	int* m;
	char* color;

	bool insert_Node(char n);
	bool remove_Node(char n);
	bool insert_Edge(char ini, char fin, int valor);
	bool remove_Edge(char ini, char fin, int valor);
	void matriz();
	void DFS_function();
	void DFS(CPila<char> Stack);
};

bool MGrafo::insert_Node(char n) {
	int last = Nodes.size();
	for (int i = 0; i < last; i++) {
		if (Nodes[i] == n)
			return false;
	}
	Nodes.push_back(n);
	return true;
}
bool MGrafo::remove_Node(char n) {
	int last = Nodes.size();
	for (int i = 0; i < last; i++) {
		if (Nodes[i] == n) {
			Nodes.erase(Nodes.begin() + i);
			return true;
		}
	}
	return false;
}
bool MGrafo::insert_Edge(char ini, char fin, int valor) {
	MEdge* temp = new MEdge(ini, fin, valor);
	Edges.push_back(temp);
	return true;
}
bool MGrafo::remove_Edge(char ini, char fin, int valor) {
	// Buscaria y borraria Edge si la encuentra
	return true;
}
void MGrafo::matriz() {
	int tam = Nodes.size();
	m = new int[tam * tam];
	
	for (int i = 0; i < (tam * tam); ++i)
		m[i] = 0;

	int last = Edges.size();
	for (int i = 0; i < last; ++i) {
		int col = -1;
		for (int j = 0; j < tam && col < 0; ++j) {	// Busca el primer vertice
			if (Edges[i]->vertices[0] == Nodes[j])
				col = j;
		}
		int fil = -1;
		for (int j = 0; j < tam && fil < 0; ++j) {	// Busca el segundo vertice
			if (Edges[i]->vertices[0] == Nodes[j])
				fil = j;
		}
		m[(tam * fil) + col] = 1;
		m[(tam * col) + fil] = 1;	// ya q todo es bidireccional
	}
}


void MGrafo::DFS_function() {
	int tam = Nodes.size();
	color = new char[tam];
	for (int i = 0; i < tam; ++i)
		color[i] = 'w';
	
	CPila<char> Stack;
	Stack.add(Nodes[0]);

	color[0] = 'g';

	DFS(Stack);
}
void MGrafo::DFS(CPila<char> Stack) {
	if (!Stack.empty()) {
		int tam = Nodes.size();
		
		bool flag = false;
		char V = Stack.top->dato;

		int fil = -1;
		for (int j = 0; j < tam && fil < 0; ++j) {	// Busca el primer vertice
			if (V == Nodes[j])
				fil = j;
		}
		int i;
		for (i = 0; i < tam; i++) {
			if (m[(tam * fil) + i] == 1 && color[i] == 'w') {
				color[i] = 'g';
				flag = true;
				Stack.add(Nodes[i]);
			}
		}
		if (flag == false) {
			color[i] = 'b';
			std::cout << Nodes[i] << std::endl;
			Stack.remove();
		}
		DFS(Stack);
	}
}











