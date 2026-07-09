#include<iostream>
using namespace std;


int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        char x = 'A';

        while(j<=n){
            char c = x+i-1;
            cout<<c<<" ";
            j++;
        };

        cout<<endl;
        i++;
    };
}