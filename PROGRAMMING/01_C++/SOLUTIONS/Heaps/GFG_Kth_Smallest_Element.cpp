#include<iostream>
using namespace std;


int kthSmallest(vector<int> &arr, int k) {
    priority_queue<int> pq;
    
    for (int i=0; i<k; i++) {
        pq.push(arr[i]);
    }
    
    for (int i=k; i < arr.size(); i++) {
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    return pq.top();
}



int main(){
    vector<int> arr = {24, 6, 3, 9, -1, 76, 0, 29};  // -1, 0, 3, 6, 9, 24, 29, 76

    cout<<endl<<endl<<"4th Smallest Element is: "<<kthSmallest(arr, 4)<<endl<<endl;
}