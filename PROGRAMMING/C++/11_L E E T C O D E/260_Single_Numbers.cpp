#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    vector<int> arr = {1,2,1,3,2,9};
    int n = arr.size();
    map<int, int> toggle;
    vector<int> ans;

    for(int i=0; i<n; i++){
        if(toggle[arr[i]] == 1){
            toggle[arr[i]] = 2;
        }
        else{
            toggle[arr[i]] = 1;
        }
    }

    for(int i=0; i<n; i++){
        if(toggle[arr[i]] == 1){
            ans.push_back(arr[i]);
        }
    }

    cout<<"Value with 1 Occurence only: ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}