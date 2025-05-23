#include <iostream>
using namespace std;

int findMin(int arr[], int size) {
  int min = arr[0];
  for (int i = 1; i < size; ++i) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

int main() {
  const int size = 5;
  int arr[size];

  cout << "Enter 5 integers:\n";
  for (int i = 0; i < size; ++i) {
    cin >> arr[i];
  }

  int minNum = findMin(arr, size);
  cout << "The minimum number is: " << minNum << endl;

  return 0;
}
