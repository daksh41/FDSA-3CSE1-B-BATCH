#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string page;
    Node* next;
};

class Browser
{
    Node* top;

public:
    Browser()
    {
        top = NULL;
    }

    void visit(string page)
    {
        Node* newNode = new Node;
        newNode->page = page;
        newNode->next = top;
        top = newNode;
    }

    void back()
    {
        if (top == NULL)
        {
            cout << "No history left" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;

        cout<<"back to pre page then ";
    }

    void currentPage()
    {
        if (top == NULL)
            cout << "page not found" << endl;
        else
            cout <<"tab open : "<< top->page << endl;
    }
};

int main()
{
    Browser b;

    b.visit("google");
    b.currentPage();

    b.visit("gmail");
    b.currentPage();

    b.visit("youtube");
    b.currentPage();

    b.back();
    b.currentPage();

    b.back();
    b.currentPage();

    b.back();

    return 0;
}