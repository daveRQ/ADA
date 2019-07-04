#pragma once
#include "pch.h"
#include "Pila.h"
#include <vector>

template <class G>
class CNode {
public:
	typedef	typename	G::Edge		Edge;
	typedef	typename	G::N		N;
	typedef typename	G::E		E;
	N data;
	char color;

	std::vector<Edge*> edges;
	CNode(N _data) { data = _data; color = 'w'; }
};
template <class G>
class CEdge {
public:
	typedef	typename	G::Node		Node;
	typedef	typename	G::N		N;
	typedef	typename	G::E		E;
	Node* nodes[2];		//0 es la salida .. 1 es llegada
	bool dir;			//0 un lado .. 1 ambos lados
	E data;
	CEdge(E _data, Node* a, Node* b, bool _dir) {
		data = _data;
		nodes[0] = a;
		nodes[1] = b;
		dir = _dir;
	}
};
template <class N, class E>
class CGrafo {
public:
	typedef	typename	CGrafo<N, E>	self;
	typedef	typename	CNode<self>		Node;
	typedef typename	CEdge<self>		Edge;
	typedef typename	N		N;
	typedef	typename	E		E;
	std::vector<Node*> nodes;

	CGrafo() { ; }
	bool find_Node(int &posicion, N data);
	bool insert_Node(N n);
	bool find_Edge(int &posicion, E e, Node* a, Node* b);
	bool insert_Edge(E e, Node* a, Node* b, bool dir);
	bool remove_Edge(E e, Node* a, Node* b, bool dir);
	bool remove_Node(N n);
	Node* n(N n) {
		int p;
		if (find_Node(p, n)) return nodes[p];
		return NULL;
	}
	void DFS_function();
	void DFS(CPila<Node*> Stack);
};

template<class N, class E>
inline bool CGrafo<N, E>::find_Node(int &posicion, N data) {
	int tam_nodes = nodes.size();
	for (posicion = 0; posicion < tam_nodes; posicion++) {
		if (data == nodes[posicion]->data)
			return 1;
	}
	return 0;
}
template<class N, class E>
inline bool CGrafo<N, E>::insert_Node(N n) {
	int p;
	if (find_Node(p, n))	return 0;
	nodes.push_back(new Node(n));
	return 1;
}
template<class N, class E>
inline bool CGrafo<N, E>::find_Edge(int &posicion, E data, Node* a, Node* b) {
	int tam_edges_a = a->edges.size();
	for (posicion = 0; posicion < tam_edges_a; posicion++) {
		bool p = (a->edges[posicion]->nodes[0] == a);
		if (data == a->edges[posicion]->data && a->edges[posicion]->nodes[p] == b)
			return true;
	}
	return false;
}
template<class N, class E>
inline bool CGrafo<N, E>::insert_Edge(E e, Node* a, Node* b, bool dir) {
	if (!a || !b) return 0;
	int posicion;
	if (find_Edge(posicion, e, a, b)) {
		if (a->edges[posicion]->dir == dir || a->edges[posicion]->dir == 1)	// Si no hay nada q agregar
			return false;
		a->edges[posicion]->dir = 1;			// Agrega para el otro lado mas
		b->edges.push_back(a->edges[posicion]);
		return true;
	}
	int pos;
	if (find_Edge(pos, e, b, a)) {
		bool p = (b->edges[pos]->nodes[0] == b);
		if (b->edges[pos]->nodes[p] == a) {
			b->edges[pos]->dir = 1;
			a->edges.push_back(b->edges[pos]);
			return true;
		}
	}
	Edge* temp = new Edge(e, a, b, dir);
	a->edges.push_back(temp);	// Agrego arista al nodo "a"
	if (dir == 1 && a != b)				// Si debo agregar a ambos lados
		b->edges.push_back(temp);
	return true;
}
template<class N, class E>
inline bool CGrafo<N, E>::remove_Edge(E e, Node* a, Node* b, bool dir) {
	if (!a || !b) return 0;
	int posicion_a;
	if (!find_Edge(posicion_a, e, a, b)) return false;
	if (a->edges[posicion_a]->dir == 1 && dir == 0) {		// Elimino solo media arista
		a->edges[posicion_a]->dir = 0;
		a->edges.erase(a->edges.begin() + posicion_a);
		return 1;
	}
	int posicion_b;
	if (find_Edge(posicion_b, e, b, a) && a != b) 			// Elimino arista si sale del nodo b
		b->edges.erase(b->edges.begin() + posicion_b);
	Edge* t = a->edges[posicion_a];
	a->edges.erase(a->edges.begin() + posicion_a);		// Elimino arista del nodo a
	delete t;
	return true;
}
template<class N, class E>
inline bool CGrafo<N, E>::remove_Node(N n) {
	int a;
	if (!find_Node(a, n)) return false;
	while (nodes[a]->edges.size() > 0) {
		Node* e_a = nodes[a]->edges[0]->nodes[0];
		Node* e_b = nodes[a]->edges[0]->nodes[1];
		remove_Edge(nodes[a]->edges[0]->data, e_a, e_b, 1);
	}
	nodes.erase(nodes.begin() + a);
	return true;
}

template<class N, class E>
inline void CGrafo<N, E>::DFS_function() {
	CPila<Node*> Stack;
	Stack.add(nodes[0]);
	Stack.top->dato->color = 'G';
	DFS(Stack);
}
template<class N, class E>
inline void CGrafo<N, E>::DFS(CPila<Node*> Stack) {
	if (!Stack.empty()) {
		bool flag = false;
		Node* V = Stack.top->dato;
		int contador = V->edges.size();
		for (int i = 0; i < contador; i++) {
			int j;
			if (V->edges[i]->nodes[0] != V) 	// Vemos el vecino del Nodo en la arista q no sea el mismo
				j = 0;
			else
				j = 1;
			if (V->edges[i]->nodes[j]->color == 'w') {  // Preguntamos si el vecino es blanco
				V->edges[i]->nodes[j]->color = 'G';
				Stack.add(V->edges[i]->nodes[j]);
				flag = true;
			}
		}
		if (flag == false) {
			V->color = 'b';
			cout << V->data << endl;
			Stack.remove();
		}
		DFS(Stack);
	}
}

