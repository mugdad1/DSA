/*
Task 5: Sum of diagonal elements in 2D Arrays
In a two dimensional array, find the sum of diagonal elements, e.g. in the array below,
, the diagonal elements are 2, 6 and 0 and their sum is 8
*/
// task5.cpp
#include <iostream>
using namespace std;

int sumDiagonal(int matrix[2][2]) {
    int sum = matrix[0][0] + matrix[1][1];
    return sum;
}

int main() {
    const int size = 2;
    int matrix[size][size];

    cout << "Enter elements of the 2x2 matrix:\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> matrix[i][j];
        }
    }

    int diagSum = sumDiagonal(matrix);
    cout << "The sum of diagonal elements is: " << diagSum << endl;

    return 0;
}
