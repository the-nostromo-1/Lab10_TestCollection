// tests collection implementation
// Mikhail Nesterenko
// 4/6/2022

#include "collection.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main() {

	int size = 5;  // setting collection array size
	double* a = new double[size]; // allocating dynamic array

	// initializing array
	a[0] = 0.;
	a[1] = 10.;
	a[2] = 20.;
	a[3] = 30.;
	a[4] = 40.;

	cout << "Collection: ";
	output(a, size); // printing out the array
	cout << endl;

	cout << "Collection value: " << value(a, size) << endl;


	// asking user to input a number
	cout << "Input number to find in the collection: ";
	double number;
	cin >> number;

	// checking if the input number is in the collection
	int index = check(a, number, size);
	if (index == -1)
		cout << "The number is not in the array" << endl;
	else
		cout << "The number is at position " << index << endl;

	// adding a new number to the collection
	addNumber(a, 55.5, size);
	cout << "Collection after adding a new number: ";
	output(a, size);
	cout << endl;

	// adding a duplicate number to collection
	// the function should not add it
	addNumber(a, 20., size);
	cout << "Collection after adding existing number: ";
	output(a, size);
	cout << endl;

	//
	removeNumber(a, 10., size);
	cout << "Collection after removing number: ";
	output(a, size);

	delete[] a; // deallocating the array
}

void output(const double* colPtr, const int size) {
	for (int i = 0; i < size; ++i) {
		cout << colPtr[i] << " ";
	}
}

double value(const double* colPtr, const int size) {
	double new_value;
	for (int i = 0; i < size; ++i) {
		new_value += colPtr[i];
	}
	return new_value;
}

int check(const double* colPtr, const double number, const int size) {
	int temp_number;
	for (int i = 0; i < size; ++i) {
		if (colPtr[i] == number) {
			return i;
		}
	}
	return -1;
}

void addNumber(double*& colPtr, const double number, int& size) {
	int index_check = check(*&colPtr, number, size);
	if (index_check == -1) {
		++size;
		double* tmp = new double[size];
		for (int i = 0; i < size; ++i) {
			tmp[i] = colPtr[i];
		}
		tmp[size - 1] = number;
		delete[] colPtr;
		colPtr = tmp;
	}
}

void removeNumber(double*& colPtr, const double number, int& size) {
	bool found = false;
	--size;
	double* tmp = new double[size];
	for (int i = 0; i < size; ++i) {
		if (colPtr[i] == number) {
			found = true;
		}
		else {
			if (found == false) {
				tmp[i] = colPtr[i];
			}
			else {
				tmp[i - 1] = colPtr[i];
			}
		}
	}
	delete[] colPtr;
	colPtr = tmp;
}

// int index_check_2 = check(*&colPtr, number, size);
// if (index_check_2 == check(*&colPtr, number, size)) {
//    --size;
//    double *tmp_2 = new double [size];
//    for (int i = 0; i < size; ++i) {
//       if (colPtr[i] != number) {
//          tmp_2[i] = colPtr[i];
//       }
//    }
//    delete [] colPtr;
//    colPtr = tmp_2;
// }