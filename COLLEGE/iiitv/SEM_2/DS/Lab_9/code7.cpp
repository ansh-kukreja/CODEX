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

int main() {
    int h1[] = {40, 30, 20};
    int h2[] = {35, 15, 10};

    int n1 = 3, n2 = 3;
    int merged[100];

    for (int i = 0; i < n1; i++)
        merged[i] = h1[i];

    for (int i = 0; i < n2; i++)
        merged[n1 + i] = h2[i];

    int n = n1 + n2;

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(merged, n, i);

    for (int i = 0; i < n; i++)
        cout << merged[i] << " ";

    return 0;
}