#include<iostream>
using namespace std;


int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int i=1;
    while(i<=n){

        int j = n-i;
        while(j){
            cout<<" ";
            j--;
        }

        int k = 1;
        while(k <= i){
            cout<<k;
            k++;
        }

        int l = i-1;
        while(l){  
            cout<<l;
            l--;
        };

        cout<<endl;
        i++;
    }
}