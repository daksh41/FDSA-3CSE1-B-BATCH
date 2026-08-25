#include <iostream>
using namespace std;

class Node
{
public:
    int token;
    Node* next;

    Node(int value)
    {
        token = value;
        next = NULL;
    }
};

class Queue
{
    Node* head;
    Node* tail;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
    }

    void insertEnd(int token)
    {
        Node* newNode = new Node(token);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteByValue(int token)
    {
        if (head == NULL)
            return;

        if (head->token == token)
        {
            Node* temp = head;
            head = head->next;

            if (head == NULL)
                tail = NULL;

            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->token != token)
        {
            temp = temp->next;
        }

        if (temp->next != NULL)
        {
            Node* del = temp->next;
            temp->next = del->next;

            if (del == tail)
                tail = temp;

            delete del;
        }
    }

    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->token << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void reversePrint(Node* temp)
    {
        if (temp == NULL)
            return;

        reversePrint(temp->next);
        cout << temp->token << " ";
    }

    void reverse()
    {
        reversePrint(head);
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.insertEnd(101);
    q.insertEnd(102);
    q.insertEnd(103);
    q.insertEnd(104);

    cout << "Forward: ";
    q.display();

    q.deleteByValue(102);

    cout << "After deletion: ";
    q.display();

    cout << "Reverse: ";
    q.reverse();

    return 0;
}