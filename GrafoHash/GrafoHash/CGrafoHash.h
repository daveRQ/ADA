#pragma once
#include "Priority_Queue.h"

#include <vector>
using std::vector;

class CGrafoHash {
public:
	vector<char> Vertex;
	vector<int> NumEdges;	// Num de aristas por vertice

	vector<int> AdreessEdges;		// Arista hacia Node
	vector<int> ValueEdges;	

	// dijkstra
	vector<int> d_value;
	vector<int> d_previous;
	vector<bool> d_permanente;

	CGrafoHash() { ; }
	~CGrafoHash() { ; }

	bool node_find(char dato, int &pos);
	bool node_add(char dato);
	bool node_remove(char dato);

	bool edge_add(char ini, char fin, int dato);
	bool edge_remove();
	void dijks(PriorityQueue<int, int> cola);
	void dijkstra(char ini);

	void print_dijkstra(int ini);
};

inline bool CGrafoHash::node_find(char dato, int &pos) {
	for (pos = 0; pos < Vertex.size(); pos++) {
		if (Vertex[pos] == dato)
			return true;
	}
	return false;
}
inline bool CGrafoHash::node_add(char dato) {
	int pos;
	if (node_find(dato, pos))
		return false;
	Vertex.push_back(dato);
	NumEdges.push_back(0);
	return true;
}
inline bool CGrafoHash::node_remove(char dato) {			// esta mal xD falta en este borrado
	/*int pos;
	if (!node_find(dato, pos))
		return false;
	Vertex.erase(Vertex.begin() + pos);
	return true;*/
}
	
inline bool CGrafoHash::edge_add(char ini, char fin, int valor) {
	int pos_ini;
	if (!node_find(ini, pos_ini))
		return false;

	int pos_fin;
	if (!node_find(fin, pos_fin))
		return false;
	
	int pos_edge = 0;
	for (int i = 0; i <= pos_ini; i++)
		pos_edge += NumEdges[i];

	AdreessEdges.insert(AdreessEdges.begin() + pos_edge, pos_fin);
	ValueEdges.insert(ValueEdges.begin() + pos_edge, valor);

	NumEdges[pos_ini]++;

	return true;
}
inline bool CGrafoHash::edge_remove() {
	return false;
}
inline void CGrafoHash::dijks(PriorityQueue<int, int> cola) {
	int tam = cola.tam;
	if (tam != 0) {
		if (d_value[cola.top_name()] == cola.top_value()) {
			int desde = 0, cont;
			for (int i = 0; i < cola.top_name(); ++i)
				desde += NumEdges[i];
			cont = NumEdges[cola.top_name()];
		
			for (int i = desde; i < (desde + cont); ++i) {
				if (d_permanente[AdreessEdges[i]] == false) {
					int temp = cola.top_value() + ValueEdges[i];
					if (d_value[AdreessEdges[i]] == -1 || temp < d_value[AdreessEdges[i]]) {
						d_value[AdreessEdges[i]] = temp;
						d_previous[AdreessEdges[i]] = cola.top_name();
						cola.push(temp, AdreessEdges[i]);
					}
				}
			}
			d_permanente[cola.top_name()] = true;
		}
		cola.pop();
		dijks(cola);

	}
}

inline void CGrafoHash::dijkstra(char ini) {
	int pos_ini;
	if (!node_find(ini, pos_ini))
		return;

	int tam = Vertex.size();		// inicializa todos los vectores para el dijkstra
	d_value.assign(tam, -1);
	d_previous.assign(tam, -1);
	d_permanente.assign(tam, false);

	PriorityQueue<int, int> cola;

	d_value[pos_ini] = 0;
	d_previous[pos_ini] = pos_ini;

	cola.push(d_value[pos_ini], pos_ini);

	dijks(cola);

	//for (int i = 0; i < tam; i++)
	//	std::cout << d_value[i] << " - ";
	//std::cout << std::endl;
	//for (int i = 0; i < tam; i++)
	//	std::cout << d_previous[i] << " - ";
	//std::cout << std::endl;
	//for (int i = 0; i < tam; i++)
	//	std::cout << d_permanente[i] << " - ";
	//std::cout << std::endl;

	print_dijkstra(pos_ini);
}

inline void CGrafoHash::print_dijkstra(int ini) {
	int tam = Vertex.size();
	for (int i = 0; i < tam; i++) {
		std::cout << "De " << Vertex[ini] << " a " << Vertex[i] << " es: " << d_value[i] << std::endl;
	}
}
