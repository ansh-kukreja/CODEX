#include<iostream>
using namespace std;

// =========== 'this' is a Pointer that stores the address of current object ===========


class Demo{
    public:

    Demo(){
        cout<<endl<<"Value of 'this' :           "<< this <<endl;
    }

    int id;
    Demo(int id){
        this->id = id;
    }
}; 

int main(){
    Demo d;
    cout<<"Address of Current Object : "<<&d<<endl<<endl;
}
