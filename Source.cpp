#include "strassen.h"

int main() {
	int n;
	cin >> n;
	int** A = createMatrix(n);
	int** B = createMatrix(n);
	int** C = createMatrix(n);

	randomize(A, n);
	randomize(B, n);

	/*cout << "Matrix A: " << endl;
	print(A, n);

	cout << "Matrix B: " << endl;
	print(B, n);*/

    auto start = high_resolution_clock::now();
    C = multiply(A, B, n);
    auto stop = high_resolution_clock::now();
    auto duration_standard = duration_cast<milliseconds>(stop - start);

    /*cout << "Matrix C by Std:" << endl;
    print(C, n);*/

    cout << "Time taken by Standard algorithm: " << duration_standard.count() << " milliseconds" << endl;

    start = high_resolution_clock::now();
    C = strassen(A, B, n);
    stop = high_resolution_clock::now();
    auto duration_strassen = duration_cast<milliseconds>(stop - start);
   /* cout << "Matrix C by Strassen:" << endl;
    print(C, n);*/

    cout << "Time taken by Strassen algorithm: " << duration_strassen.count() << " milliseconds" << endl;

    
    
    remove(A, n);
    remove(B, n);
    remove(C, n);
    return 0;
}