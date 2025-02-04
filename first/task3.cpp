/*
Task 3: Count the number of even and odd integers in a linear array
Declare a linear array and input numeric data from user. Find the number of even and odd integer
data.
*/
// task3.cpp
#include <iostream>
using namespace std;

void countEvenOdd(int arr[], int size) {
    int even = 0, odd = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            ++even;
        } else {
            ++odd;
        }
    }

    cout << "Number of even integers: " << even << endl;
    cout << "Number of odd integers: " << odd << endl;
}

int main() {
    const int size = 5;
    int arr[size];

    cout << "Enter 5 integers:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    countEvenOdd(arr, size);

    return 0;
}
