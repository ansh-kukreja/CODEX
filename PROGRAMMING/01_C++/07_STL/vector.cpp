#include<iostream>
#include<vector>
using namespace std;

int main(){

    // This will initialize a vector of size 9, with all elements initialized with a default value 7
    vector<int> a(9,7);

    // Copying Vector "a" in another vector "c"
    vector<int> c(a);

    vector<int> v;
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    cout<<"Capacity: "<<v.capacity()<<endl;
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Element at 2nd Index: "<<v.at(1)<<endl;
    cout<<"Front: "<<v.front()<<endl;
    cout<<"Back: "<<v.back()<<endl;
    v.push_back(9);
    v.pop_back();
}