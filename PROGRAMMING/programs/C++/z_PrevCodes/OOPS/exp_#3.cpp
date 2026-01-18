#include<iostream>

using namespace std;

int main(){

    cout<<"harpreet, 2210997092";
    int n, x, ld, sum = 0;
    cout<<endl;
    cout<<"Enter a Number : ";
    cin>>n;

    x = n;

    while( x != 0){
        ld = x % 10;
        sum += ld;
        x = x / 10;
    }

    cout<<endl;
    cout<<"Sum of all the digits of the given number is : "<< sum;
    cout<<endl;

    return 0;
}