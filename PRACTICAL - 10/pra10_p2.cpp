#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> table[10];

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int code;
        cin >> code;

        int index = code % 10;

        table[index].push_back(code);
    }

    cout << "\nFinal Shelves:\n";

    for(int i = 0; i < 10; i++)
    {
        cout << i << " : ";

        if(table[i].empty())
        {
            cout << "EMPTY";
        }
        else
        {
            for(int book : table[i])
                cout << book << " ";
        }

        cout << endl;
    }

    return 0;
}