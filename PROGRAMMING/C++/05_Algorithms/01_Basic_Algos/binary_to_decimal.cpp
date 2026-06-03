#include<iostream>

using namespace std;


int myPow(int a, int b){
    if(b==0) return 1;
    int ans = a;

    for(int i=0; i<b-1; i++){
        ans *= a;
    }
    return ans;
}


int main(){
    int b;
    cout<<"Enter a Binary Number: ";
    cin>>b;

    int n = b;
    int dec = 0;
    int i = 0;

    while(n){
        int bit = n%10;
        dec += myPow(2, i++) * bit;
        n /= 10;
    }
    cout<<"\nDecimal Equivalent of "<<b<<" is: "<<dec<<"\n\n";
}