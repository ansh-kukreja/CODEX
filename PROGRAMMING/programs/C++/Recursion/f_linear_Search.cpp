#include<iostream>
using namespace std;

bool findEle(int arr[], int size, int target){
    if(size == 0){
        return false;
    }
    if(arr[0] == target){
        return true;
    }

    int ans = findEle(arr + 1, size-1, target);
    return ans;
}

int main(){
    int arr[4] = {4,7,7,9};
    int s = 4, target=4;

    bool x = findEle(arr, s, target);
    if(x){
        cout<<"Element Found";
    }
    else{
        cout<<"Element Not found";
    }
}