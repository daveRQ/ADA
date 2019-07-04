#pragma once
#include<iostream>

template <class V, class N>
class NodeValue {
public:
	V value;
	N name;
	NodeValue* next;
	NodeValue(V value, N name) { 
		this->value = value;
		this->name = name;
		next = NULL;
	}	
};

template <class V, class N>
class PriorityQueue {
public:
	NodeValue<V, N>* top;
	int tam;
	PriorityQueue() { top = NULL; tam = 0; }
	
	void find(NodeValue<V, N>** &p, V value);
	void push(V value, N name);
	void pop();
	V top_value();
	N top_name();
};
template <class V, class N>
inline void PriorityQueue<V, N>::find(NodeValue<V, N>** &p, V value) {
	for (p = &top; *p && value > (*p)->value; p = &((*p)->next));
}
template<class V, class N>
inline void PriorityQueue<V, N>::push(V value, N name) {
	NodeValue<V, N>** p;
	find(p, value);	
	NodeValue<V, N> *temp = new NodeValue<V, N>(value, name);
	temp->next = (*p);
	(*p) = temp;
	++tam;
}
template<class V, class N>
inline void PriorityQueue<V, N>::pop() {
	NodeValue<V, N> *temp = top;
	top = top->next;
	delete temp;
	--tam;
}
template<class V, class N>
inline V PriorityQueue<V, N>::top_value() {
	return top->value;
}
template<class V, class N>
inline N PriorityQueue<V, N>::top_name() {
	return top->name;
}