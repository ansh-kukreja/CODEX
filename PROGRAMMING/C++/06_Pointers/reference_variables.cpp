#include<iostream>
using namespace std;

void update(int &ref){
    ref++;
}

int main(){

    int i = 90;

    int &j = i;

    cout<<"i: "<<i<<endl;
    cout<<"j: "<<j<<endl;


    cout<<"Before: "<<i<<endl;;
    update(i);
    cout<<"After: "<<i<<endl;
}