#include<iostream>
using namespace std;

class A{
    public:
    int a,b;

    void operator+ (A &ob){
        int val1 = this -> a;
        int val2 = ob.a;
        cout<< val2 - val1<<endl;
    }

    void operator() (){
        cout<<"() Operator Overloaded";
    }
};

int main(){
    A x1, x2;
    x1.a = 7;
    x2.a = 9;
    
    x1 + x2; // + overloading
    x1(); // () overloading
}