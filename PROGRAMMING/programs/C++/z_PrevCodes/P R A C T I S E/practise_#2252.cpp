#include<iostream>
using namespace std;

int main(){
    int a=4, b=9;
    int* x = &a;
    int* y = &b;

    cout<<x<<'\n';
    cout<<y<<'\n';
    cout<<x - y<<'\n';

    if(x >= y){
        cout<<"Y!!";
    }

}