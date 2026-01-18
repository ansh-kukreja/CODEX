#include<iostream>
#include<vector>
using namespace std;

bool isUnique(vector<int> occ){
    for(int i=0; (i)<occ.size(); i++){
        for(int j=i+1; j<occ.size(); j++){
            if(occ[i] == occ[j])
                return false;
        }
    }
    return true;
}

int main(){
    //int arr[15] = {4,4,7,8,8,48,4, 48, 48, 48,9,9,9,9, 9}; // 4-3  7-1  8-2  48-4  9-5
    int arr[2] = {1,2};
    int n = 2;

    vector<int> occ;

    for(int i=0; (i)<n; i++){
        int count=0;
        if(arr[i] != INT32_MIN){
            for(int j=i+1; j<n; j++){
                if(arr[i] == arr[j]){
                    arr[j] = INT32_MIN;
                    count++;
                }
            }
            occ.push_back(count+1);
        }
    }

    for(int j=0; j<occ.size(); j++){
        cout<<occ[j]<<" ";
    }
    bool ans = isUnique(occ);
    if(ans == 1){
        cout<<"The Fucking Answer is True";
    }
    else{
        cout<<"The Fucking Answer is False";
    }
}