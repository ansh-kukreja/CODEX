#include<iostream>
using namespace std;

class Demo{
    public:

    Demo(){
        cout<<"Default Constructor Called!"<<endl;
    }

    int a;
}; 

int main(){

    // Statically Created
    Demo d;

    // Dynamically Created
    Demo *ob = new Demo(); 
}