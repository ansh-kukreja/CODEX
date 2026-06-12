#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> v;

    v.push_back(0);
    v.push_back(2);
    v.push_back(4);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    
    // Binary Search
    cout<<"Checking if 4 Exists or not: "<<binary_search(v.begin(), v.end(), 4)<<endl;

    // Max / Min
    cout<<max(9,4)<<endl;
    cout<<min(9,4)<<endl;

    //Swap
    //Reverse
    //Rotate
    //Sort

}
