#include <iostream>
#include <array>
using namespace std;

int main() {
    const int SIZE = 2; // Size of the matrix
    array<array<int, SIZE>, SIZE> matrix; // Declare a 2x2 matrix

    // Input the elements of the matrix
    cout << "Enter the elements of a 2x2 matrix:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Calculate the transpose
    array<array<int, SIZE>, SIZE> transpose; // Declare a matrix for the transpose
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            transpose[j][i] = matrix[i][j]; // Swap rows and columns
        }
    }

    // Output the transpose
    cout << "Transpose of the matrix is:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
