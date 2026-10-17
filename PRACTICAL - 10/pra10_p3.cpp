#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    const int PRIME = 7;

    int table[SIZE];

    for(int i = 0; i < SIZE; i++)
        table[i] = -1;

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int id;
        cin >> id;

        int h1 = id % SIZE;
        int h2 = PRIME - (id % PRIME);

        int index = h1;
        int j = 0;

        while(table[index] != -1 && j < SIZE)
        {
            j++;
            index = (h1 + j * h2) % SIZE;
        }

        if(j == SIZE)
        {
            cout << "Table is full or no suitable slot found\n";
        }
        else
        {
            table[index] = id;
        }
    }

    cout << "\nFinal Hash Table:\n";

    for(int i = 0; i < SIZE; i++)
    {
        cout << i << " : ";

        if(table[i] == -1)
            cout << "EMPTY";
        else
            cout << table[i];

        cout << endl;
    }

    return 0;
}