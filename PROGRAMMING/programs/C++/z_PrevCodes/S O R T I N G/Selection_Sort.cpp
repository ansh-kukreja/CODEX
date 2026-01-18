#include<iostream>
using namespace std;

void sortedArr(int arr[],int n){

    for(int i=0; i<(n-1); i++){

        int minIndex=i;

        for(int j=i+1; j<n; j++){

            if(arr[j] < arr[minIndex])
                minIndex = j;
            
        }

        swap(arr[i],arr[minIndex]);
        
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={89,99,98,45,0,9,74,947,-6};

    sortedArr(arr,9);


}