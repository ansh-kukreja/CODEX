#include<iostream>
using namespace std;

class Human{
    public:
    int age;
    int height;
    string name;
};

class Male: public Human{
    public:
    int bicepSize;
    int maxBenchPress;
};

class Female: public Human{
    public:
    int hairLength;
    int noOfHoursChitChatDoneInADay;
};

int main(){
    Male ansh;
    Female shilpi;

    ansh.age = 22;
    ansh.bicepSize = 15;
    ansh.maxBenchPress = 100;

    shilpi.age = 22;
    shilpi.hairLength = 90;
    shilpi.noOfHoursChitChatDoneInADay = 20;
}