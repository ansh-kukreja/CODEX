#include<iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Display from Base" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Display from Derived" << endl;
    }
};

int main() {
    Base *ptr = new Derived();
    ptr->display(); // Late binding
    delete ptr;
    return 0;
}