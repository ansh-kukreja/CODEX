#include<iostream>
using namespace std;

bool isSorted(int arr[], int size){
    if(size == 0 || size == 1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }
    
    return isSorted(arr+1, size-1);
}

int main(){
    int arr[8] = {4,7,7,8,9,70,98,99};
    int size= 8;
    bool ans = isSorted(arr, size);
    if(ans){
        cout<<"Array is Sorted";
    }
    else{
        cout<<"Array is Not Sorted";
    }
}