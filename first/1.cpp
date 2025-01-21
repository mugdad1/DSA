#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
string name;
cout<<"enter the name"<<endl;
getline(cin , name);
if(name.empty()){
    cout<<" name must be smaller"<<endl;

}else{
    cout<<"welcome"<<endl;
}
}

