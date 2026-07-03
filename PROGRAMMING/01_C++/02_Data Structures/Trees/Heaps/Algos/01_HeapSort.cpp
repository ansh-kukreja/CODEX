#include<iostream>
using namespace std;


void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// ====== Heap Sort will only work if given array is alreay a heap (do buildHeap() first) =======
void heapSort(vector<int> &arr, int n){

    while(n > 1){
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main(){
    vector<int> arr = {-1, 70, 60, 55, 45, 50};
    int n = 5;

    heapSort(arr, n);

    cout<<endl;
    cout<<endl;
    for(int i=1; i<=n; i++) cout<<" "<<arr[i];
    cout<<endl;
    cout<<endl;
}