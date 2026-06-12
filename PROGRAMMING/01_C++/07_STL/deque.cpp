#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> a;
    a.push_back(4);
    a.push_front(7);

    for(int i:a){
        cout<<i<<" "<<endl;
    }

    cout<<"Element at 0 Index: "<<a.at(0)<<endl;
    cout<<"Element at Front: "<<a.front()<<endl;
    cout<<"Element at Back: "<<a.back()<<endl;
    cout<<"Element Empty or Not: "<<a.empty()<<endl;
    cout<<"Size of Deque: "<<a.size()<<endl;
    cout<<"Memory Allocated to Deque: "<<a.max_size()<<endl;
    cout<<"Deleting/Erasing Elements in a Deque"<<endl;
    a.erase(a.begin(), a.begin()+1);
    for(int i:a){
        cout<<i<<" ";
    }

}