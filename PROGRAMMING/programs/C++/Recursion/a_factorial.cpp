#include<iostream>
using namespace std;

int fact(int n){
    if(n == 0)
        return 1;

    int x = n * fact(n-1);

    return x;
}

int main(){
    int n;
    cout<<"Enter a Number: "; cin>>n;
    int ans = fact(n);
    cout<<ans;
}