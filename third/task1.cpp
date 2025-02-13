/*
Experiment 1: Static Memory Allocation

Instruction:
    • Perform the following experiment using Program 1 and answer the given questions.

    1. Copy Program 1 code in Dev C++ then run the program.
    2. (Execution 1) During run time select [1]yes to add 5 more elements in the array.
    3. Then press [2] to print all array elements.
    4. Record the allocated memory and the memory used by the program in table 1 below. See program output for allocated and used memory.
    5. (Execution 2) Run the application again, but this time try to add 10 more elements by pressing [1]yes twice.
    6. Then press [2] to print array elements.
    7. Again Record the allocated and used memory in table 1 below.

	Table 1
Execution number
Allocated Memory
Used Memory
1

80
40
2
80

60

Question 1: (2 points)

Based on the performed experiment 1, explain how static memory allocation influence the efficiency of the program in terms of memory allocation and usage.

Type your answer inside this box.


//todo




Questions 2: (2 points)

Execute Program 1, then add 30 more elements in the array by choosing [1]yes for 6 times then press [2]no, to display the elements. Observe the output of the program and explain how does static memory allocation affects the efficiency of the program based on memory allocation and usage.

Type your answer inside this box.



//todo


k
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
int const SIZE = 20;
int array[SIZE];
int increase = 5;
int lastIndex = 0;
int choice, ctr;
cout << "\nAllocated Memory: " << sizeof(int) * SIZE <<endl;
srand((unsigned) time(0));
cout << "Array Contains 5 elements\n";
do
{
for(ctr = lastIndex; ctr < increase; ctr++) {
array[ctr] = rand();
lastIndex++;
}
cout << "Do you want to add more 5 numbers?[1]yes [2]no: ";
cin >> choice;
if(choice==1 && increase<SIZE) {
increase += 5;
}
}while(choice!=2);
for(int i = 0; i < increase; i++) {
cout << array[i] << " ";
}
cout << "\nMemory used: " << sizeof(int) * increase;
}
