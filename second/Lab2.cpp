#include <iostream>
using namespace std;
int main(){

int const* ptr;
int var;
var = 50;

ptr = &var;
cout<<ptr<<endl;
int const  * pointVar;
int vare;
vare = 5;

 pointVar = &vare;

cout << *pointVar << endl;

    pointVar = &vare;

    // print value of var
    cout << "var = " << vare << endl;

    // print address of var
    cout << "Address of var (&var) = " << &vare << endl
         << endl;

    // print pointer pointVar
    cout << "pointVar = " << pointVar << endl;

    // print the content of the address pointVar points to
    cout << "Content of the address pointed to by pointVar (*pointVar) = " << *pointVar << endl;
    



    return 0 ;

}