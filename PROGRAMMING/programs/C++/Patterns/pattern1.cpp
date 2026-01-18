#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a No. : ";
    cin>>n;


    for(int i=0; i<n; i++){

        for(int j=0; j<(n-i); j++){
            cout<<1+j;
        }
        for(int k=0; k<(i*2); k++){
            cout<<"*";
        }
        for(int l=0; l<(n-i); l++){
            cout<<n-(i)-l;
        }
        
        cout<<endl;

    }
}
