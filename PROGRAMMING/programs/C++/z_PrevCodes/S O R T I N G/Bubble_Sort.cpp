#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    
    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-1;j++){

            if(arr[j]>arr[j+1]){

                swap(arr[j],arr[j+1]);

            }

        }
    }
    for(int x=0;x<n;x++){
        cout<<arr[x]<<" ";
    }

}

int main(){
    int arr[7]={9,3,0,4,55,45,8};
    bubbleSort(arr,7);

}
