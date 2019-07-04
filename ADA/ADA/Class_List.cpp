#include "pch.h"
#include "Class_List.h"


Class_List::Class_List(int* a, int tam) {
	this->a = a;
	this->tam = tam;
}

Class_List::~Class_List() {
	delete[] a;
}

void Class_List::insert_sort() {
	for (int i = 1; i < tam; i++) {
		int j = i - 1;
		while (j >= 0 && a[j] > a[j + 1]) {
			int temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
			j--;
		}
	}
}

void Class_List::print() {
	for (int i = 0; i < tam; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}
