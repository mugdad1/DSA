/*
Task 2: Search the array
Input 10 values from user in an array, input another value and search this data value in array.
*/
// task2.cpp
#include <iostream>
using namespace std;

bool searchArray(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

int main() {
    const int size = 10;
    int arr[size];
    int target;

    cout << "Enter 10 integers:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the integer to search: ";
    cin >> target;

    if (searchArray(arr, size, target)) {
        cout << "The number " << target << " is found in the array.\n";
    } else {
        cout << "The number " << target << " is not found in the array.\n";
    }

    return 0;
}
