#include <iomanip>   // For stream manipulators such as setw() etc.
#include <iostream>
using namespace std;

// Function prototypes
void displaySizeOfDataTypes();
void performOperations();
void displayArray(int arr[], int size);
void initializeArray(int arr[], int size, int startValue);
void Display2Array(int x[][2],int rows);

int main() {
    system("cls");  // Clear previous outputs before running

    displaySizeOfDataTypes();
    performOperations();

    int n[10];
    initializeArray(n, 10, 100);
    displayArray(n, 10);

    int x[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8} };
    Display2Array(x, 5);

    return 0;
}

// Function definitions
void displaySizeOfDataTypes() {
    cout << "Size of data types without variables:" << endl;
    cout << setw(10) << sizeof(float) << " bytes" << endl;
    cout << setw(10) << sizeof(double) << " bytes" << endl;
    cout << setw(10) << sizeof(bool) << " bytes" << endl;
    cout << setw(10) << sizeof(int) << " bytes" << endl;
    cout << setw(10) << sizeof(char32_t) << " bytes" << endl;
    cout << setw(10) << sizeof(short int) << " bytes" << endl;
}

void performOperations() {
    int a = 10, b = 20, c;
    float f1, f2, f;

    cout << "Enter floats f1 and f2 to divide: ";
    cin >> f1 >> f2;

    c = a + b;
    f = f1 / f2;

    cout << "Sum (int): " << c << endl;
    cout << "Quotient (float): " << f << endl;
}

void displayArray(int arr[], int size) {
    cout << "\nElement" << setw(13) << "Value" << endl;
    for (int i = 0; i < size; ++i) {
        cout << setw(7) << i << setw(13) << arr[i] << endl;
    }
}

void initializeArray(int arr[], int size, int startValue) {
    for (int i = 0; i < size; ++i) {
        arr[i] = i + startValue;
    }
}

void Display2Array(int x[][2], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "x[" << i << "][" << j << "]: " << x[i][j] << endl;
        }
    }
}
