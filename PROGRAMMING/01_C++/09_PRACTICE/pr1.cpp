#include<iostream>
using namespace std;

int main(){

    // Pointer / Pointer Variables
    int a = 90;
    int* p = &a;
    int** q = &p;

    cout<<a<<endl;
    cout<<*p<<endl;
    cout<<**q<<endl;

    // Reference variables
    int x = 9;
    int& y = x;

    cout<<x<<endl;
    cout<<y<<endl;
        x++;
        y--;
    cout<<x<<endl;
    cout<<y<<endl;
}