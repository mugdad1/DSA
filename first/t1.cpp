#include <array>
#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  // Declare an array with size 'n'
  int arr[n];
  // Input numeric data from user
  cout << "Enter " << n << " integers:" << endl;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  // Find the minimum numeric data in the array
  int minElement = arr[0]; // Assume the first element is the minimum
  for (int i = 1; i < n; ++i) {
    if (arr[i] < minElement) {
      minElement = arr[i];
    }
  }

  // Output the result
  cout << "The minimum numeric data in the array is: " << minElement << endl;

  return 0;
}
