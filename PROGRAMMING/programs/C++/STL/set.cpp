#include<iostream>
#include<set>
using namespace std;

int main(){

    // Stores Multiple Same Values as a Single Value
    set<int> s;

    s.insert(7);
    s.insert(9);
    s.insert(7);
    s.insert(0);
    s.insert(7);
    s.insert(9);

    for(int i:s){
        cout<<i<<" ";
    }

    s.erase(s.begin());

    cout<<"\nAfter Erase\n";

    for(int i:s){
        cout<<i<<" ";
    }
}