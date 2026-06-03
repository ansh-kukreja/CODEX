#include<iostream>
using namespace std;

bool findEle(int arr[], int s, int e, int target){
    int m = s + (e-s);

    if(s > e){
        return false;
    }

    if(arr[m] == target){
        return true;
    }
    if(arr[m] < target){
        s=m+1;
    }
    if(arr[m] > target){
        e=m-1;
    }
    
    int ans = findEle(arr, s, e, target);
    return ans;
}

int main(){
    int n = 4, target=9;
    int arr[n] = {4,7,7,9};

    bool x = findEle(arr, 0,n-1, target);


    if(x){
        cout<<"Element Found";
    }
    else{
        cout<<"Element Not found";
    }
}