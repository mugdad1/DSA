/*
Task 6: Multiply two 2D Arrays
Scan two arrays from user (two dimensional), calculate the multiplication of both and print the
result.
Hints:
The multiplication is only possible if the row matrix and the column matrix have the same
number of elements
*/
// task6.cpp
#include <iostream>
using namespace std;

void multiplyArrays(int arr1[2][2], int arr2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    cout << "The multiplication of two arrays is:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr1[2][2], arr2[2][2];

    cout << "Enter elements of the first 2x2 matrix:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> arr1[i][j];
        }
    }

    cout << "Enter elements of the second 2x2 matrix:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> arr2[i][j];
        }
    }

    int result[2][2];
    multiplyArrays(arr1, arr2, result);

    return 0;
}
