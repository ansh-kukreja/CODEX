#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue(){
        front = -1;
        rear = -1;
    }

    void enqueue(int value){
        if(rear == MAX - 1) {
            cout << "\nQueue Overflow\n";
            return;
        }

        if(front == -1)
            front = 0;

        arr[++rear] = value;
    }

    void dequeue(){
        if(front == -1 || front > rear) {
            cout << "\nQueue Underflow\n";
            return;
        }
        front++;
    }

    void peek() {
        if(front == -1 || front > rear){
            cout << "\nQueue is empty\n";
            return;
        }

        cout<<"Front element: " << arr[front] << endl;
    }

    void display() {
        if(front == -1 || front > rear) {
            cout << "\nQueue is empty\n";
            return;
        }

        cout << "\nQueue elements: ";
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            q.peek();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while(choice != 5);

    return 0;
}