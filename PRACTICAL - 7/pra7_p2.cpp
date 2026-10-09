#include <iostream>
using namespace std;

class Queue {
    struct Node {
        string patient;
        Node* next;

        Node(string p) {
            patient = p;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void arrive(string patient) {
        Node* newNode = new Node(patient);

        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front patient : " << front->patient << endl;
    }

    void attend() {
        if (front == nullptr) {
            cout << "Error: No patients waiting" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        delete temp;

        if (front == nullptr)
            rear = nullptr;

        if (front != nullptr)
            cout << "Front patient: " << front->patient << endl;
        else
            cout << "Ward is Empty" << endl;
    }
};

int main() {
    Queue q;

    q.arrive("DAKSH");
    q.arrive("JASH");
    q.arrive("DHARM");

    q.attend();
    q.attend();

    q.arrive("MARUT");

    q.attend();
    q.attend();
    q.attend();

    return 0;
}