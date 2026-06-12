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

    // ======== For Static Objects the Destructor is called automatically =========
    Demo ob;
    
}