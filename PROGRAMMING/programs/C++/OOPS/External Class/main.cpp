#include<iostream>
#include "hero.cpp"
using namespace std;

int main(){
    Hero batman;
    batman.name = "Batman Kukreja";
    batman.superPower = "Money";
    batman.age = 22;

    cout<<"Size of Hero Class: "<<sizeof(batman)<<endl;
}