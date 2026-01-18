#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l;
    list<int> n(7,90);
    l.push_back(7);
    l.push_front(9);
    l.pop_back();
    l.pop_front();
    l.erase(l.begin());

    for(int i:n){
        cout<<i<<" ";
    }

}
