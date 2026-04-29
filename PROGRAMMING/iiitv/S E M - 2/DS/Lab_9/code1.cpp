#include <iostream>
using namespace std;

#define MAX 100
int heap[MAX];
int size = 0;

void insert(int val) {
    int i = size;
    heap[size++] = val;

    while(i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printHeap() {
    for(int i = 0; i < size; i++){
        cout << heap[i] << " ";
    }
}

int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(30);

    printHeap();
    return 0;
}