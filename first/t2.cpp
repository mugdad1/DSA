#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10; // Size of the array
    int arr[SIZE]; // Declare an array of size 10

    // Input 10 values from the user
    cout << "Enter 10 integers:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cin >> arr[i];
    }

    // Input the value to search for
    int searchValue;
    cout << "Enter a value to search for: ";
    cin >> searchValue;

    // Search for the value in the array
    bool found = false;
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == searchValue) {
            found = true;
            cout << "Value " << searchValue << " found at index " << i << "." << endl;
            break; // Exit the loop once the value is found
        }
    }

    if (!found) {
        cout << "Value " << searchValue << " not found in the array." << endl;
    }

    return 0;
}
