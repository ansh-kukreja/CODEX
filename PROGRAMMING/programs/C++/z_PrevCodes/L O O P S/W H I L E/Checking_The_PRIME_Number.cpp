#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter Your Number: "; cin>>n;
    int i = 2;

    while (i<n) {
        if (n%i==0){
            cout<<"This Is Not A Prime Number"<< endl;
        }
        else{
            cout<<"This Is A Prime Number"<< endl;
        }
        
    i=i+1;
    }



    return 0;
}