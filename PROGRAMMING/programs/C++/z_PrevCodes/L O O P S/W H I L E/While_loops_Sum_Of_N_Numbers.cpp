#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter Your Number Here: "; cin>>n;

    int i=1;
    int sum=0;

    while (i<=n){
        sum= sum+i;
        i= i+1;
    }

    cout<<"The Sum Of All Numbers From 1-"<<n<<" is : "<<sum;

    return 0;
}