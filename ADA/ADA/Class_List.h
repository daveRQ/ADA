#pragma once

class Class_List {
private:
	int* a;
	int tam;
public:
	Class_List(int* a, int tam);
	~Class_List();

	void insert_sort();
	void print();
};

