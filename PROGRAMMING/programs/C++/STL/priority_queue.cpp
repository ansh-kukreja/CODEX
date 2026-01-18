#include<iostream>
#include<queue>
using namespace std;

int main(){

    // Max Priority Queue (Default) - Stores value in "Largest -> Smallest" Format , also called Max Heap
    priority_queue<int> maxi;

    // Min Priority Queue - Stores value in "Smallest -> Largest" Format, also called Min Heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(4);
    maxi.push(2);
    maxi.push(0);
    maxi.push(9);

    int n=maxi.size();

    for(int i=0; i<n; i++){
        cout<<maxi.top()<<" ";  // 9 4 2 0
        maxi.pop();
    }
    cout<<endl;

    mini.push(7);
    mini.push(9);
    mini.push(4);
    mini.push(6);

    n=mini.size();

    for(int i=0; i<n; i++){
        cout<<mini.top()<<" ";  // 4 6 7 9
        mini.pop();
    }
    cout<<endl;
}