#include<iostream>
using namespace std;

class Demo{
    public:
    int a;
    int b;

    Demo(){
        cout<<"Constuctor Called"<<endl;
    }


    // Custom Destructor
    ~Demo(){
        cout<<"Destructor Called"<<endl;
    }
};

int main(){

    // ======== For Dynamic Objects we have to call the Destructor Manually =========
    Demo *st = new Demo();

    // Calls the Destructor aka frees the object memory..
    delete st;
    
}