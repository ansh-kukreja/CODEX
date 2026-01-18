#include<iostream>
using namespace std;

int main(){
    int n;
    int rev=0;
    int ld;
    cout<<"Enter The Number: "; cin>>n;

    while(n!=0){
        ld=n%10;
        rev=rev*10+ld;
        n=n/10;
    }

    cout<<rev;


    return 0;
}