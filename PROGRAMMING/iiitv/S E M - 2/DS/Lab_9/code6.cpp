#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int smallest = i, left = 2*i+1, right = 2*i+2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

int extractMin(int arr[], int &n) {
    int min = arr[0];
    arr[0] = arr[--n];
    heapify(arr, n, 0);
    return min;
}

int main() {
    int arr[] = {25, 10, 40, 30, 20, 50, 35};
    int n = 7, k = 3;

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = 1; i < k; i++)
        extractMin(arr, n);

    cout << "Kth smallest = " << arr[0];

    return 0;
}