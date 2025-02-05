// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++) {
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot) {
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) 	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


// Driver program to test above functions 
int main() {
	srand(time(NULL));
	
	//int num_listas = 100;

	//for (int i = 0; i < num_listas; ++i) {
	//	int tam = 10 + rand() % 20;
	//	int* a = new int[tam];
	//	for (int j = 0; j < tam; ++j) {
	//		a[j] = 10 + rand() % 50;
	//	}

	//	int n = tam;
	//	quickSort(a, 0, tam - 1);
	//	//printArray(a, tam);

	//	delete a;
	//}


	int tam = 100000;
	int* a = new int[tam];
	for (int j = 0; j < tam; ++j) {
		a[j] = 0 + rand() % 40;
	}

	quickSort(a, 0, tam - 1);
	//printArray(a, tam);

	return 0;
}
