#include<iostream>
using namespace std;

class Sum{
    public:

    void add(int a, int b, int c = 1, int d = 2){
        int ans = a+b+c+d;
        cout<<endl<<"Sum is : "<<ans<<endl<<endl;
    }
};

int main(){
    Sum s;
    s.add(7,4); // 14
    s.add(7,4,9); // 22
    s.add(7,4,9,8); // 28

}