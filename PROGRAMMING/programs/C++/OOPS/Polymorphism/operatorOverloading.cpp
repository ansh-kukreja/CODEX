#include<iostream>
using namespace std;

class Badmosh{
    public:
    int a;

    void operator+ (Badmosh &ob){
        int val = (this->a) + ob.a;
        cout<<endl<<"Sum is : "<<val<<endl<<endl;
    }

};

int main(){
    Badmosh ob, oc;

    ob.a = 7;
    oc.a = 2;

    ob+oc;
}