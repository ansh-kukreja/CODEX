#include<iostream>
using namespace std;

class Greet{
    public:

    void say(){
        cout<<endl<<"Ohh Kive aa Singhh!"<<endl<<endl;
    }

    void say(string name){
        cout<<endl<<"Ohh Kive aa "<<name<<endl<<endl;
    }

    void say(string name, int age){
        cout<<endl<<"Ohh Kive aa "<<age<<" saal da "<<name<<endl<<endl;
    }
};

int main(){
    Greet x;

    x.say();
    x.say("Ansh");
    x.say("Ansh", 22);
}