#pragma once
#include <iostream>	
#include <ctime>
#include <chrono>

using std::cout;
using std::endl;
using std::rand;
using std::time;
using std::srand;
using std::cin;
using namespace std::chrono;

int** createMatrix(int n) {
	int** newMatrix = new int* [n];
	for (unsigned int i = 0; i < n; i++) {
		newMatrix[i] = new int[n];
	}
	return newMatrix;
}
void randomize(int**& A, int n) {
	srand(time(NULL));

	A = new int* [n];
	for (unsigned int i = 0; i < n; i++) {
		A[i] = new int[n];
		for (unsigned int j = 0; j < n; j++) {
			A[i][j] = rand() % 100;
		}
	}
}

void print(int** A, int n) {
	for (unsigned int i = 0; i < n; i++) {
		cout << endl;
		for (unsigned int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
	}
	cout << endl;
	cout << endl;
}

void remove(int**& A, int n) {
	for (unsigned int i = 0; i < n; i++) {
		delete[] A[i];
	}
	delete[] A;
}

//matrix operations
int** add(int** A, int** B, int n) {
	int** C = createMatrix(n);

	for (int i = 0; i < n; i++)
		C[i] = new int[n];
	for (unsigned int i = 0; i < n; i++)
		for (unsigned int j = 0; j < n; j++)
			C[i][j] = A[i][j] + B[i][j];
	return C;
}

int** subtract(int** A, int** B, int n) {
	int** C = createMatrix(n);

	for (int i = 0; i < n; i++)
		C[i] = new int[n];
	for (unsigned int i = 0; i < n; i++)
		for (unsigned int j = 0; j < n; j++)
			C[i][j] = A[i][j] - B[i][j];
	return C;
}

int** multiply(int** A, int** B, int n) {
	int** C = createMatrix(n);

	for (unsigned int i = 0; i < n; i++)
		C[i] = new int[n];
	for (unsigned int i = 0; i < n; i++)
		for (unsigned int j = 0; j < n; j++)
		{
			C[i][j] = 0;
			for (unsigned int k = 0; k < n; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	return C;
}