#include <iostream>
using namespace std;

#define MAX 10

struct Process {
    int pid;
    int burst;
};

class CircularQueue {
private:
    Process q[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    void enqueue(Process p) {
        if (isFull()) {
            cout << "\nQueue Overflow\n";
            return;
        }

        if(front == -1) front = rear = 0;
        else rear = (rear + 1) % MAX;

        q[rear] = p;
    }

    Process dequeue() {
        Process p = q[front];

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;

        return p;
    }
};

int main() {

    CircularQueue cq;
    int n, tq;

    cout << "Enter num of processes: ";
    cin >> n;

    cout << "Enter Time Quantum: ";
    cin >> tq;

    for(int i = 0; i < n; i++) {
        Process p;
        p.pid = i + 1;

        cout << "Enter Burst Time for Process " << p.pid << ": ";
        cin >> p.burst;

        cq.enqueue(p);
    }

    cout << "\n Round Robin Execution \n";

    while (!cq.isEmpty()) {

        Process current = cq.dequeue();

        cout << "Processing P" << current.pid << " for ";

        if (current.burst > tq) {
            cout << tq << " units\n";
            current.burst -= tq;
            cq.enqueue(current);
        }
        else {
            cout << current.burst << " units (Completed)\n";
            current.burst = 0;
        }
    }

    cout << "\nAll processes completed.\n";

    return 0;
}