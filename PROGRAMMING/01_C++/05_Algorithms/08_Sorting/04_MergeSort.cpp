#include<iostream>
using namespace std;

void mergeTwoSortedArrays(int *arr, int s, int e){
    int mid = s + (e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int mainArrayIndex = s;
    for(int i=0; i<len1; i++){
        arr1[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++){
        arr2[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = s;
    int index1 = 0;
    int index2 = 0;

    while(index1 < len1 && index2 < len2){
        if(arr1[index1] < arr2[index2]){
            arr[mainArrayIndex++] = arr1[index1++];
        }
        else{
            arr[mainArrayIndex++] = arr2[index2++];
        }
    }

    while(index1 < len1){
        arr[mainArrayIndex++] = arr1[index1++];
    }
    while(index2 < len2){
        arr[mainArrayIndex++] = arr2[index2++];
    }

    delete []arr1;
    delete []arr2;
}

void mergeSort(int *arr, int s, int e){
    if(s >= e){
        return;
    }

    int mid = s + (e-s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    mergeTwoSortedArrays(arr, s, e);
}

int main(){
    int n = 9;
    int arr[9] = {7,5,9,6,52,8,741,80,9};

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}