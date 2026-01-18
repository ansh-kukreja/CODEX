#include<iostream>
using namespace std;

class Complex{
    int num1, num2;

    public:
    void accept(){
        cout<<"--Enter two Complex Numbers--\n";
        cout<<"Enter First Number : "; cin>>num1;
        cout<<"Enter Second Number : "; cin>>num2;
    }

    Complex operator+(Complex obj){
        Complex c;
        c.num1 = num1 + obj.num1;
        c.num2 = num2 + obj.num2;
        return c;
    }

    void display(){
        cout<<num1<<"+"<<num2<<"i"<<"\n";
    }

};

int main(){
    cout<<"Gauraansh, 2210997081\n";
    Complex c1, c2, sum;
    c1.accept();
    c2.accept();
    sum = c1+c2;
    cout<<"\n Entered Values : ";
    cout<<"\t";
    c1.display();
    cout<<"\t";
    c2.display();
    cout<<"\t";
    sum.display();
}