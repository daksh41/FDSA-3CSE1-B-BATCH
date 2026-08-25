#include <iostream>
using namespace std;

class Node
{
public:
    int token;
    Node *next;

    Node(int value)
    {
        token = value;
        next = NULL;
    }
};

class Queue
{
    Node *head;
    Node *tail;
    int len;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        len = 0;
    }

    void insertFront(int token)
    {
        Node *newNode = new Node(token);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        len++;
        display();
    }

    void insertEnd(int token)
    {
        Node *newNode = new Node(token);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        len++;
        display();
    }

    void insertAtPosition(int token, int position)
    {
        if (position <= 1)
        {
            insertFront(token);
            return;
        }

        if (position > len + 1)
        {
            cout << "Invalid position" << endl;
            display();
            return;
        }

        Node  *newNode = new Node(token);
        Node  *temp = head;

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (position == len + 1)
        {
            tail = newNode;
        }

        len++;
        display();
    }

    void display()
    {
        Node *temp = head;

        cout << "Queue :- ";

        while (temp != NULL)
        {
            cout << temp->token << " ";
            temp = temp->next;
        }

    }
};

int main()
{
    Queue q;

    q.insertFront(41);
    q.insertEnd(41);
    q.insertEnd(34);
    q.insertAtPosition(29, 2);
    q.insertFront(15);
    q.insertAtPosition(33, 10);

    return 0;
}