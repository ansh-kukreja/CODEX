#include<iostream>
using namespace std;

class mkbc{
    public:
    int x=4, y=9;
    void set(mkbc *a, mkbc b){
        cout<<a.x;
    }
    void get(mkbc d, mkbc e){

    }
};
int main(){
    mkbc a,b,c,d,e;
    a.set(&a,b);

}