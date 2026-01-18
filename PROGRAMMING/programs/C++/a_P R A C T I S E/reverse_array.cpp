#include<iostream>
using namespace std;

void printReverse(int arr[], int size){
    int s=0;
    int e=size-1;

    while(s<e){
        // int t = arr[s];
        // arr[s] = arr[e];
        // arr[e] = t;

        swap(arr[s], arr[e]);

        s++;
        e--;
    }

    cout<<"Reverse Array --> ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int elma[] = {1,2,5,2,5,12,56,13,90,99,49};
    cout<<"Original Array --> 1,2,5,2,5,12,56,13,90,99,49\n";
    int size = sizeof(elma)/sizeof(int);
    printReverse(elma, size);
}