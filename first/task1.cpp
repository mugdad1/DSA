/*
Task 1: Find the minimum numeric data in a linear array
*/                                                                             \
#include<iostream>

int add(int a, int b) { return a + b; }

int main() {
  int num1, num2;
  std::cout << "Enter the first number: ";
  std::cin >> num1;
  std::cout << "Enter the second number: ";
  std::cin >> num2;
  std::cout << "The sum is: " << add(num1, num2) << std::endl;
  return 0;
}
/*
Declare a linear array and input numeric data from user. Find the minimum
numeric data in this array.
*/
/*
#include <iostream>
using namespace std;

int findMin(int arr[], int size) {
  int min = arr[0];
  cout << "   h";
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
  int l = 8;

  int minNum = findMin(arr, size);
  cout << "The minimum number is: " << minNum << endl;

  return 0;
}
*/
