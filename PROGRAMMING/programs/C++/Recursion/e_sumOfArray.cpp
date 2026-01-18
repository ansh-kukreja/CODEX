#include<iostream>
using namespace std;

int sumOfArray(int arr[], int size){
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }
    
    int sum = arr[0] + sumOfArray(arr + 1, size - 1);
    return sum;
}

int main(){
    int arr[4] = {4,7,8,9};
    int size = 4;
 
    cout<<"Sum of Array is : "<<sumOfArray(arr, size);
}