#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter The Number: "; cin>>n;

    int i = 1;
    int x = 1;

    while (i<=n){
        int j=1;
        while(j<=n){
            cout<<x;
            j=j+1;
        }
        cout<< endl;
        i=i+1;
        x=x+1;
        
    }



    return 0;
}