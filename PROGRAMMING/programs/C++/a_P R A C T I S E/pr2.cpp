#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {1,2,3,4,7,5,6,7,8};

    int ans=0;

    for(int i=0; i<arr.size(); i++){
        ans = ans ^ arr[i];
    }

    cout<<ans<<endl;


    for(int i=1; i<arr.size(); i++){
        ans = ans ^ i;
    }

    cout<<ans<<endl;
}