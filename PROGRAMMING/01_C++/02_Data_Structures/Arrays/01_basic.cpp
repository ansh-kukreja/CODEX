#include<iostream>

using namespace std;

int main(){
    int arr1[40];

    int arr2[40] = {0};  // Initialized whole array with value '0'

    int arr3[40] = {1,2,8,4,2,}; // Will set rest of the 35 values as '0'



// ------- Finding Size of an Array -------
    int arr4[7] = {4,2,5,7,6,9,0};
    int arr4Size = sizeof(arr4)/sizeof(arr4[0]);

    cout<<"\nSize of Arr4: "<<arr4Size<<"\n\n";

// ----------------------------------------


    for(int i=0; i<40; i++){
        cout<<arr3[i]<<" ";
    }

}