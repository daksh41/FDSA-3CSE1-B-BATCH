#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Queue(int n) {
        capacity = n;
        arr = new int[n];
        front = 0;
        rear = -1;
        size = 0;
    }

    void join(int token) {
        if (size == capacity) {
            cout << "Error: Queue is Full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = token;
        size++;

        cout << "Front token: " << arr[front] << endl;
    }

    void serve() {
        if (size == 0) {
            cout << "Error: Queue is Empty" << endl;
            return;
        }

        front = (front + 1) % capacity;
        size--;

        if (size == 0) {
            front = 0;
            rear = -1;
        }

        if (size > 0)
            cout << "Front token: " << arr[front] << endl;
        else
            cout << "Queue is Empty" << endl;
    }
};

int main() {
    int n;
    cout << "Enter queue capacity: ";
    cin >> n;

    Queue q(n);

    q.join(41);
    q.join(40);
    q.join(34);

    q.serve();
    q.serve();

    q.join(29);
    q.join(18);

    q.join(15);

    q.serve();

    return 0;
}