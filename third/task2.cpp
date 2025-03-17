/*
Task: Convert the following program to implement dynamic memory allocation.
*/

#include <cstdlib>
#include <iostream>
using std::cout;
using std::srand;

int largest(int arr[], int n) {
  int i;

  int max = arr[0];

  for (i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];

  return max;
}

int main() 
{ 
	int N = 100;
    int arr[N];

    srand((unsigned)time(0));
    for (int ctr = 0; ctr < N; ctr++) {
      arr[ctr] = std::rand();
      cout << arr[ctr] << " ";
        }
  
    cout << "\n\nLargest value in the given array is " << largest(arr, N); 
    	 
	return 0; 
}