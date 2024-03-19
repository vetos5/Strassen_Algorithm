#include "strassen.h"
#include <cassert>
#include "auxiliary.h"

void runTest() {
    {
        const int n = 3;
        int** A = createMatrix(n);
        int** B = createMatrix(n);
        int** result;

        randomize(B, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = 0;
            }
        }
        result = multiply(A, B, n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                assert(result[i][j] == 0);
            }
        }

        remove(A, n);
        remove(B, n);
        remove(result, n);
    }
    {
        const int n = 3;
        int** A = createMatrix(n);
        int** B = createMatrix(n);
        int** result;

        randomize(A, n);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = 0;
            }
        }
        result = multiply(A, B, n);


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                assert(result[i][j] == 0);
            }
        }
        remove(A, n);
        remove(B, n);
        remove(result, n);
    }

    {
        int** A = createMatrix(1);
        int** B = createMatrix(1);
        A[0][0] = 3;
        B[0][0] = 2;

        int** result = strassen(A, B, 1);

        assert(result[0][0] == 6);

        remove(A, 1);
        remove(B, 1);
        remove(result, 1);
    }

    cout << "Tests passed successfully!" << endl;

}
int main() {

    runTest();

    int n;
    cout << "Enter the size of the matrix: " << endl;
    cin >> n;

    int** A = createMatrix(n);
    int** B = createMatrix(n);
    int** C = createMatrix(n);

    /*string fileA = "A.txt";
    randomize(A, n);
    saveToFile(A, n, fileA);
    
    string fileB = "B.txt";
    randomize(B, n);
    saveToFile(B, n, fileB);*/

    /*int** A = readFromFile("A.txt", n);
    int** B = readFromFile("B.txt", n);*/

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

    auto start1 = high_resolution_clock::now();
    C = strassen(A, B, n);
    auto stop1 = high_resolution_clock::now();
    auto duration_strassen = duration_cast<milliseconds>(stop1 - start1);
    /*cout << "Matrix C by Strassen:" << endl;
    print(C, n);*/

    cout << "Time taken by Strassen algorithm: " << duration_strassen.count() << " milliseconds" << endl;



    remove(A, n);
    remove(B, n);
    remove(C, n);
    return 0;
}

