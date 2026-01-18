#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter The Number: "; cin>>n;

    int i = 1;

    while(i<=n){

        //CREATING FIRST TRIANGLE

        int j=n-i+1;
        int k=1;
        while(k<=j){
            cout<<k;
            k=k+1;

        }

        //CREATING SECOND TRIANGLE

        int l=(i-1)*2;
        int m=1;
        while(m<=l){
            cout<<"*";
            m=m+1;
        }
        
        //CREATING THIRD TRIANGLE
        
        while(j){
            cout<<j;
            j=j-1;
        }

        cout<< endl;
        i=i+1;

    }

    return 0;
}
