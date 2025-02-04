/*
Task 1: Reverse of an integer
Write a program that finds the reverse of an integer given by the user using pointers. Note: you must access and modify the number using a pointer using c++ 
*/
#include <iostream>

using namespace std;


void reverseNumber(int* num) {
    int reversed = 0;
    if (*num == 0) {
        cout << "Reversed Number: 0" << endl;
        return;
    }
    
    while(*num != 0) {
        int digit = *num % 10;
        reversed = (reversed * 10) + digit;
        *num = *num / 10;
    }
    
    cout << "Reversed Number: " << reversed << endl;
}

int main() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    reverseNumber(&number);

    return 0;
}
