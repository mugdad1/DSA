#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int SIZE = 10; // Size of the array
    vector<int> arr(SIZE); // Declare a vector of size 10

    // Input numeric data from the user
    cout << "Enter " << SIZE << " integers:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cin >> arr[i];
    }

    // Initialize counters for even and odd integers
    int evenCount = 0;
    int oddCount = 0;

    // Count even and odd integers
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] % 2 == 0) {
            evenCount++; // Increment even counter
        } else {
            oddCount++; // Increment odd counter
        }
    }

    // Output the results
    cout << "Number of even integers: " << evenCount << endl;
    cout << "Number of odd integers: " << oddCount << endl;

    return 0;
}
