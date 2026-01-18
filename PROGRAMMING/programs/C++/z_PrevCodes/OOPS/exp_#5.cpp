#include<iostream>
using namespace std;

class Room{

    public:
    int length, breadth;

    void get(){
        cout<<"Enter length : "; cin>>length;
        cout<<"Enter breadth : "; cin>>breadth;
    }

    void display(){
        cout<<"Dimensions of Room are : "<<length<<" x "<<breadth<<"\n";
        cout<<"Length : "<<length<<"\n";
        cout<<"Breadth : "<<breadth<<'\n';
    }

    void area(){
        cout<<"~ Area : "<<length * breadth<<" sq km";
        cout<<endl;
    }

    void perimeter(){
        cout<<"~ Perimeter : "<<2*(length + breadth)<<" sq km";
        cout<<endl;
    }
};

int main(){

    Room r[5];
    cout<<"\nHarpreet , 2210997092\n\n";

    for(int i=0; i<5; i++){
        
    cout<<"ROOM "<<i+1<<'\n';
    r[i].get();
    r[i].display();
    r[i].area();
    r[i].perimeter();
    cout<<endl;
    }
}