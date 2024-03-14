#include "strassen.h"

int main() {
	int n;
	cin >> n;
	int** A = createMatrix(n);
	int** B = createMatrix(n);
	int** C = createMatrix(n);

	randomize(A, n);
	randomize(B, n);

	cout << "Matrix A: " << endl;
	print(A, n);

	cout << "Matrix B: " << endl;
	print(B, n);



	cout << "Matrix C by Strassen:" << endl;
	print(strassen(A, B, n), n);

	cout << "Matrix C by Std:" << endl;
	print(multiply(A, B, n), n);
}