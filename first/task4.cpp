/*
Task4: Calculate the Transpose of a 2 by 2 matrix
Transpose of a matrix converts the rows to columns and columns to rows.
*/
#include <iostream>
using namespace std;

void transposeMatrix(int matrix[2][2]) {
    cout << "The Transpose of the Matrix is:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[2][2];

    cout << "Enter elements of the 2x2 matrix:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> matrix[i][j];
        }
    }

    transposeMatrix(matrix);

    return 0;
}
