#include <iostream>
using namespace std;

#define MAX 100
int heap[MAX];
int size = 0;

void insert(int val) {
    int i = size;
    heap[size++] = val;

    while (i != 0 && heap[(i - 1)/2] > heap[i]) {
        swap(heap[i], heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void heapify(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

void deleteRoot() {
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
}

int main() {
    insert(20);
    insert(10);
    insert(30);
    insert(5);

    deleteRoot();

    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";

    return 0;
}