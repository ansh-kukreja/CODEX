#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if(rear == MAX - 1) {
            cout<<"\nQueue Overflow\n"<< endl;
            return;
        }

        if(front == -1)
            front = 0;

        arr[++rear] = value;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "\nQueue Underflow\n";
            return;
        }
        front++;
    }

    void display() {
        if(front == -1 || front > rear) {
            cout << "\nQueue is empty\n";
            return;
        }

        cout << "\nQueue elements: ";
        for(int i = front; i <= rear; i++) {
            cout << arr[i] <<" ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    cout << "\nInserting elements until queue becomes full..\n";
    for (int i = 1; i <= MAX; i++) {
        q.enqueue(i * 7);
    }

    q.display();

    cout << "\nDeleting two elements from the front..\n";
    q.dequeue();
    q.dequeue();

    q.display();

    cout << "\nAttempting to insert new elements again:\n";
    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}