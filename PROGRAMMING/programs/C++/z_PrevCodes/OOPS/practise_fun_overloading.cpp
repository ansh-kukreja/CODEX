#include<iostream>
using namespace std;

class Add{
    public:
    void add(int x, int y){
        cout<<x+y;
    }
    void add(double x, double y){ 
        double sum = x + y;
        cout<<sum;
    }
    void add(int x, double y){
        double sum = x + y;
        cout<<sum;
    }
    void add(double x, int y){
        double sum = x + y;
        cout<<sum;
    }
    void add(string x, string y){
        string sum = x + y;
    }
};

int main(){
    Add x;
    x.add(4,7);
    cout<<endl;
    x.add(9,5.1);
    cout<<endl;
    x.add(4.7,9);
    cout<<endl;
    x.add(9.4,80.6);
    cout<<endl;
    x.add('4','7');
    cout<<endl;
}