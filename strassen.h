#pragma once
#include "auxiliary.h"

int** strassen(int** A, int** B, int n) {
	if (n <= 128) {
		return multiply(A, B, n);
	}

	int** C = createMatrix(n);

	size_t newSize = n / 2;

	int** A11 = createMatrix(newSize);
	int** A12 = createMatrix(newSize);
	int** A21 = createMatrix(newSize);
	int** A22 = createMatrix(newSize);
	int** B11 = createMatrix(newSize);
	int** B12 = createMatrix(newSize);
	int** B21 = createMatrix(newSize);
	int** B22 = createMatrix(newSize);

	for (unsigned int i = 0; i < newSize; i++) {
		for (unsigned int j = 0; j < newSize; j++) {
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][newSize + j];
			A21[i][j] = A[newSize + i][j];
			A22[i][j] = A[newSize + i][newSize + j];
			B11[i][j] = B[i][j];
			B12[i][j] = B[i][newSize + j];
			B21[i][j] = B[newSize + i][j];
			B22[i][j] = B[newSize + i][newSize + j];
		}
	}

	//S
	int** S1 = subtract(B12, B22, newSize);
	int** S2 = add(A11, A12, newSize);
	int** S3 = add(A21, A22, newSize);
	int** S4 = subtract(B21, B11, newSize);
	int** S5 = add(A11, A22, newSize);
	int** S6 = add(B11, B22, newSize);
	int** S7 = subtract(A12, A22, newSize);
	int** S8 = add(B21, B22, newSize);
	int** S9 = subtract(A11, A21, newSize);
	int** S10 = add(B11, B12, newSize);

	//P
	int** P1 = strassen(A11, S1, newSize);
	int** P2 = strassen(S2, B22, newSize);
	int** P3 = strassen(S3, B11, newSize);
	int** P4 = strassen(A22, S4, newSize);
	int** P5 = strassen(S5, S6, newSize);
	int** P6 = strassen(S7, S8, newSize);
	int** P7 = strassen(S9, S10, newSize);

	//Ci

	int** C11 = subtract(add(add(P5, P4, newSize), P6, newSize), P2, newSize);				// P5 + P4 - P2 + P6
	int** C12 = add(P1, P2, newSize);														// P1 + P2
	int** C21 = add(P3, P4, newSize);														// P3 + P4
	int** C22 = subtract(subtract(add(P5, P1, newSize), P3, newSize), P7, newSize);			// P1 + P5 - P3 - P7

	for (unsigned int i = 0; i < newSize; i++) {
		for (unsigned int j = 0; j < newSize; j++) {
			C[i][j] = C11[i][j];
			C[i][newSize + j] = C12[i][j];
			C[newSize + i][j] = C21[i][j];
			C[newSize + i][newSize + j] = C22[i][j];
		}
	}

	remove(A11, newSize);
	remove(A12, newSize);
	remove(A21, newSize);
	remove(A22, newSize);
	remove(B11, newSize);
	remove(B12, newSize);
	remove(B21, newSize);
	remove(B22, newSize);
	remove(S1, newSize);
	remove(S2, newSize);
	remove(S3, newSize);
	remove(S4, newSize);
	remove(S5, newSize);
	remove(S6, newSize);
	remove(S7, newSize);
	remove(S8, newSize);
	remove(S9, newSize);
	remove(P1, newSize);
	remove(P2, newSize);
	remove(P3, newSize);
	remove(P4, newSize);
	remove(P5, newSize);
	remove(P6, newSize);
	remove(P7, newSize);
	remove(C11, newSize);
	remove(C12, newSize);
	remove(C21, newSize);
	remove(C22, newSize);

	return C;
}