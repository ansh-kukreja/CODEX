#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue{
private:
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if((rear + 1) % MAX == front) {
            cout << "\nQueue Overflow\n";
            return;
        }

        if(front == -1) {
            front = rear = 0;
        }
        else{
            rear = (rear + 1) % MAX;
        }

        arr[rear] = value;
        cout << value << " inserted\n";
    }

    void dequeue() {
        if(front == -1) {
            cout << "\nQueue Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if(front == -1) {
            cout << "\nQueue is empty\n";
            return;
        }

        cout << "\nQueue elements: ";

        int i = front;
        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;

    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
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
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}