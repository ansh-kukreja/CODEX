#include<iostream>
using namespace std;


int main(){
    int n=7;
    // int arr[n] = {40,4,7,9,7,6,79}; // 4 6 7 7 9 40 79 

    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}