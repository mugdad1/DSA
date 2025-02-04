/*
Task 2: Sum and product of digits
Write a program that uses a function to find the sum and the product of digits of a given number. Note: you must print the result inside the main function and write the process of finding the sum and product of digits inside another function in c++
*/
#include <iostream>

using namespace std;

void calculateSumAndProduct(int number, int &sum, int &product) {
    sum = 0;
    product = 1;

    while (number != 0) {
        int digit = number % 10;
        sum = sum+ digit;
        product = product* digit;
        number = number/ 10;
    }
}

int main() {
    int number;
    int sum;
    int product;

    cout << "Enter an integer: ";
    cin >> number;

    calculateSumAndProduct(number, sum, product);

    cout << "Sum of digits: " << sum << endl;
    cout << "Product of digits: " << product << endl;

    return 0;
}
