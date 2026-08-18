#include <iostream>
using namespace std;

#define MAX 10

class CustomerQueue {
private:
    string arr[MAX];
    int front, rear;

public:
    CustomerQueue() {
        front = rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertVIP(string name) {
        if (isFull()) {
            cout << "\nQueue is full\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        }
        else if (front == 0) {
            front = MAX - 1;
        }
        else {
            front--;
        }

        arr[front] = name;
    }

    void insertRegular(string name) {
        if(isFull()) {
            cout<<"\nQueue is full\n";
            return;
        }

        if(front == -1) {
            front = rear = 0;
        }
        else if(rear == MAX - 1) {
            rear = 0;
        }
        else{
            rear++;
        }

        arr[rear] = name;
    }

    void serveCustomer() {
        if(isEmpty()) {
            cout << "\nNo customers waiting\n";
            return;
        }

        cout << arr[front] << " has been served\n";

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == MAX - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No customers in queue\n";
            return;
        }

        cout << "Waiting List: ";

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

    CustomerQueue q;
    int choice;
    string name;

    do {
        cout << "\n1. Insert VIP Customer";
        cout << "\n2. Insert Regular Customer";
        cout << "\n3. Serve Next Customer";
        cout << "\n4. Display Waiting List";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter VIP name: ";
            cin >> name;
            q.insertVIP(name);
            break;

        case 2:
            cout << "Enter customer name: ";
            cin >> name;
            q.insertRegular(name);
            break;

        case 3:
            q.serveCustomer();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}