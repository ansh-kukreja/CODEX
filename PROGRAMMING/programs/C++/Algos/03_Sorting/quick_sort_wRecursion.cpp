#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count=0;

    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot){
            count += 1;
        }
    }

    int pivotindex = s+count;
    swap(arr[s], arr[pivotindex]);
    int i=s, j=e;

    while(i < pivotindex && pivotindex < j){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotindex && pivotindex < j){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotindex;
}

void qSort(int arr[], int s, int e){
    if(s >= e){
        return;
    }
    int pivot = partition(arr, s, e);

    qSort(arr, s, pivot-1);
    qSort(arr, pivot+1, e);
}

int main(){
    int arr[7] = {9,4,2,89,7,47,79}; // 2 4 7 9 47 79 89
    int n = 7;

    qSort(arr, 0, n-1);

    cout<<"Sorted Array : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}