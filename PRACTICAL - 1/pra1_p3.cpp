#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);

    stringstream ss(sentence);

    string word;
    string longest = "";

    while (ss >> word) {
        if (word.length() > longest.length()) {
            longest = word;
        }
    }

    cout << "Longest Word = " << longest << endl;
    cout << "Length = " << longest.length();

    return 0;
}