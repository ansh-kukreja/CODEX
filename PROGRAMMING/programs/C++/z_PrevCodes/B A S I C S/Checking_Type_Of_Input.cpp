#include<iostream>
using namespace std;

int main(){
    char a; 
    cout<<("Enter Anything: ");
    cin>> a;

    if(a>='a'){
        cout<< "It is a lower case alphabet";
    }

    else if(a>='A'){
        cout<< "It is a Upper Case Letter";

    }

    else {
        cout<< "It is a Number";
    }
    
    return 0;
}

