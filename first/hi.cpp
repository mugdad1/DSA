#include <iostream>

int main() {
  // Step 1: Declaration and Initialization of an Array
  int myArray[5] = {10, 20, 30, 40, 50};

  // Step 2: Accessing Elements of an Array
  std::cout << "Element at index 0: " << myArray[0] << std::endl;
  std::cout << "Element at index 1: " << myArray[1] << std::endl;

  // Step 3: Modifying Elements of an Array
  myArray[2] = 35; // Changing the third element (index 2) to 35

  // Displaying the modified array
  std::cout << "Modified array:" << std::endl;
  for (int i = 0; i < 5; ++i) {
    std::cout << "Element at index " << i << ": " << myArray[i] << std::endl;
  }

  return 0;
}
