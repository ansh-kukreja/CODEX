#include<iostream>
using namespace std;


int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int i=1;
    while(i<=n){

        int j=n-i;
        while(j>=1){
            cout<<" ";
            j--;
        }

        int k=1;
        while(k<=i){
            cout<<"*";
            k++;
        }

        cout<<endl;
        i++;
    };
}