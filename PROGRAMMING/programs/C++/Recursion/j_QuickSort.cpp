
// Doing 1 Time and leaving rest for the Recursion

//  --------------------------------------------------------------------
// |  4   |  9  |  7  |  2  |  7  |  45  |  0  |  3  |  4  |  78  |  9  | 
//  --------------------------------------------------------------------

//  Picking up Value at Starting Index and putting at its right place, 
// (Calculate all the numbers less than Starting Index Value, then add that count to the starting index,
//  and "Swap( arr[ startingIndex ], arr[ startingIndex + count ] )" )

// Now Put All the Values less than the Value that we sorted above and put them to the left side,
// and values greater than that Value to the right side
// ( take i = starting , j = ending  and compare them with the Center Value, if (arr[i] > Value && arr[j] <= Value)
// then Swap them, and at last return the P (The value we sorted above first time) )



// ----------------------------------------------------------------------------------

#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pv = arr[s];
    int cnt = 0;

    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pv){
            cnt += 1;
        }
    }

    int p = s + cnt;

    swap(arr[s], arr[p]);

    int i=s, j=e;

    while(i < p && j > p){
        while(arr[i] <= pv){
            i++;
        }
        while(arr[j] > pv){
            j--;
        }
        if(i < p && j > p){
            swap(arr[i++], arr[j--]);
        }
    }

    return p;
}

void quickSort(int arr[], int s, int e){
    if(s >= e){
        return;
    }

    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main(){
    int size = 12;
    int arr[12] = {2,4,7,9,8,5,2,4,89,2,0,4};

    quickSort(arr, 0, size-1);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}