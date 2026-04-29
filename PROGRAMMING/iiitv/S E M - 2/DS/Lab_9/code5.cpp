#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i, left = 2*i+1, right = 2*i+2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int extractMax(int arr[], int &n) {
    int max = arr[0];
    arr[0] = arr[--n];
    heapify(arr, n, 0);
    return max;
}

int main() {
    int arr[] = {25, 10, 40, 30, 20, 50, 35};
    int n = 7, k = 3;

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = 1; i < k; i++)
        extractMax(arr, n);

    cout << "Kth largest = " << arr[0];

    return 0;
}