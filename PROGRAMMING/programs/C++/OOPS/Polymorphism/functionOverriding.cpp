#include<iostream>
using namespace std;

class Mammal{
    public:
    void speak(){
        cout<<endl<<"Jingalala hu hu"<<endl<<endl;
    }
};

class Animal: public Mammal{
    public:
    void speak(){
        cout<<endl<<"Oo-oo aa-aa!🐒"<<endl<<endl;
    }
};

class Human: public Animal{
    public:
    void speak(){
        cout<<endl<<"Kive aa Sinngh"<<endl<<endl;
    }
};

int main(){
    Mammal m;
    Animal a;
    Human h;

    m.speak();
    a.speak();
    h.speak();
}