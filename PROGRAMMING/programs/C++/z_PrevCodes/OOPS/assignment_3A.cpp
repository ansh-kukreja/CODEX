#include<iostream>
using namespace std;

class Add{
    public:
    void add(int a, int b){
        cout<<"Addition of "<<a<<" and "<<b<<" is : "<<a+b;
        cout<<"\n\n";
    }

};

class Mul{
    public:
    void mul(int a, int b){
        cout<<"Multiplication of "<<a<<" and "<<b<<" is : "<<a*b;
        cout<<"\n\n";
    }
    
};

class Subtract{
    public:
    void sub(int a, int b){
        cout<<"Subtraction of "<<a<<" and "<<b<<" is : "<<a-b;
        cout<<"\n\n";
    }
    
};

class Calculate : public Add, public Mul, public Subtract{
};

int main(){
    cout<<"\nGauraansh, 2210997081\n\n";
    Calculate x;
    x.add(4,5);
    x.sub(49,7);
    x.mul(7,7);
}