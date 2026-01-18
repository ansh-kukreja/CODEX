#include<iostream>
using namespace std;

class Number{
    public:
    static int x;
    int y;

    void get(int i,int j){
        x=i;
        y=j;
    }

    void display(){
        cout<<"Static : "<<x<<"\n";
        cout<<"Non Static : "<<y<<"\n";
    }

    void increment(){
        x++;
        y++;
    }

};

int Number::x;

int main(){

    cout<<"\nHarpreet, 2210997092\n";
    Number o[5];

    for( int i = 0; i<5; i++){
        o[i].get(i+1,i+1);
    }

    cout<<"\n B E F O R E   I N C R E M E N T \n";
    cout<<endl;

    for( int i = 0; i<5; i++){
        o[i].display();
    }

    cout<<"\n A F T E R   I N C R E M E N T \n";
    cout<<endl;

    for( int i = 0; i<5; i++){
        o[i].increment();
    }

    for( int i = 0; i<5; i++){
        o[i].display();
    }
}