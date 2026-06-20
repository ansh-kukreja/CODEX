#include<iostream>
using namespace std;

int main(){
    int size=19;
    char c[size];

    cout<<"Enter a String with Spaces: ";
    cin.getline(c,size);
    cout<<"You Entered this MF -> "<<c;
}