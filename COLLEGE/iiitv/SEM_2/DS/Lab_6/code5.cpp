#include <iostream>
using namespace std;

#define MAX 5

class Deque {
private:
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int x) {
        if(isFull()) {
            cout<<"\nQueue Overflow\n";
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

        arr[front] = x;
    }

    void insertRear(int x) {
        if(isFull()) {
            cout << "\nDeque Overflow\n";
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

        arr[rear] = x;
        cout <<endl<< x << " inserted at rear\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "\nDeque Underflow\n";
            return;
        }

        cout <<endl<< arr[front] << " deleted from front\n";

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

    void deleteRear() {
        if (isEmpty()) {
            cout << "\nDeque Underflow\n";
            return;
        }

        cout <<endl<< arr[rear] << " deleted from rear\n";

        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = MAX - 1;
        }
        else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "\nDeque is empty\n";
            return;
        }

        cout << "\nDeque elements: ";

        int i = front;
        while(true){
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main() {

    Deque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);

    dq.display();

    dq.deleteFront();
    dq.deleteRear();

    dq.display();

    return 0;
}