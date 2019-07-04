#pragma once


template <class T>
class PNode {
public:
	T dato;
	PNode<T>* next;
	PNode(T _dato) { dato = _dato; next = NULL; }
};

template <class T>
class CPila {
public:
	PNode<T>* top;
	CPila() { top = NULL; }
	void add(T dato);
	bool remove();
	bool empty();
};

template <class T>
void CPila<T>::add(T dato) {
	PNode<T>* t = new PNode<T>(dato);
	t->next = top;
	top = t;
}

template <class T>
bool CPila<T>::remove() {
	if (top == NULL) return false;
	PNode<T>* t = top;
	top = top->next;
	delete t;
	return true;
}

template <class T>
bool CPila<T>::empty() {
	if (top == NULL)
		return true;
	return false;
}

