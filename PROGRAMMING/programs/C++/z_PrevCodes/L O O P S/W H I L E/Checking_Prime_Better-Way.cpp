#include<iostream>
using namespace std;

int main(){
    int n;
    int i=2;
    int b=0;

    cout<< "Enter A Number: "; cin>> n;

    while(i<n){  
        if(n%i == 0){
            b=b+1;
            i++;
        }
        else{
            i++;
        }
    } 

    if(b == 0){
        cout<<n<<" is a Prime Number";
    }  

    else{
        cout<<"It is Not A Prime Number & divisibile by "<<b<<" digits";
    }


    return 0;
}