#include<iostream>

using namespace std;

class abc{

    public:
    abc(int a){
        cout<<"Constructor 1 Called.."<<a;
    };

    abc(){
        cout<<"Constructor 2 Called.."<<a;
    };

    public:
     void get(){};
};

int main(){

    abc x(9);
}