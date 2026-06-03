#include<iostream>
using namespace std;

class Student{
    public:
    int age;
    int id;

    Student(int age, int id){
        this->age = age;
        this->id = id;
    }
};

int main(){
    Student ansh(22, 9);

    // Copy Constructor
    Student shilpi(ansh);

    cout<<"Shilpi Age: "<<shilpi.age<<endl;
    cout<<"Shipli Id: "<<shilpi.id<<endl;
    
}