#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter The Number: "; cin>>n;

    bool x=1;

    for(int i=2; i<n; i++){
        if(n%i==0){
            cout<<"This is NOT a Prime Number!";
            x=0;
            break;        // NOW THE LOOP WILL END HERE
        }    
    }

    if(x==1){
        cout<<"This Is A PRIME Number!";
    }

    return 0;
}