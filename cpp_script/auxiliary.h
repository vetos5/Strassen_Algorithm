#pragma once
#include <iostream>	
#include <ctime>
#include <chrono>
#include <fstream>
#include <string>
#include <thread>

using std::cout;
using std::endl;
using std::rand;
using std::time;
using std::srand;
using std::cin;
using namespace std::chrono;
using std::ofstream;
using std::string;
using std::ifstream;

int** createMatrix(int n) {
	int** newMatrix = new int* [n];
	for (unsigned int i = 0; i < n; i++) {
		newMatrix[i] = new int[n];
	}
	return newMatrix;
}
void randomize(int**& A, int n) {
	//srand(time(NULL));

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

void saveToFile(int** matrix, int n, const string& filename) {
	ofstream outputFile(filename);

	if (outputFile.is_open()) {

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				outputFile << matrix[i][j] << " ";
			}
			outputFile << endl;
		}
		outputFile.close();
		cout << "Saved to file... " << filename << endl;
	}
	else {
		cout << "Error. " << endl;
	}
}

int** readFromFile(const string& filename, int& n) {
	ifstream inputFile(filename); 

	if (inputFile.is_open()) {
		inputFile >> n; 
		int** matrix = new int* [n]; 

		for (int i = 0; i < n; ++i) {
			matrix[i] = new int[n];
			for (int j = 0; j < n; ++j) {
				inputFile >> matrix[i][j];
			}
		}

		inputFile.close(); 
		cout << "Reading success... " << filename << endl;
		return matrix;
	}
	else {
		cout << "Error." << endl;
		return nullptr;
	}
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

