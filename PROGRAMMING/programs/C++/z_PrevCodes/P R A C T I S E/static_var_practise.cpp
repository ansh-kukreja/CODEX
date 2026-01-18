#include<iostream>
using namespace std;

class Demo{
    public:
    static int a;
    static int b;

    static void setData(int i, int j){
        a=i;
        b=j;
    }

    static void showData(){
        cout<<"Static : "<<a<<"\n";
        cout<<"Non Static : "<<b<<"\n";
    }
};

int Demo::a;
int Demo::b;

int main(){

    Demo obj1, obj2;

    Demo::setData(1,1);
    Demo::showData();
    

}