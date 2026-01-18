#include<iostream>
using namespace std;

int main(){
    int cel;
    cout<<"Enter The Temperature In Celsius: "; cin>>cel;

    float fah=(cel*1.8)+32;

    cout<<cel<<" Celsius Is Equal To "<<fah<<" Fahrenheit.";

    return 0;
}