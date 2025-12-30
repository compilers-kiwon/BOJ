#include <iostream>
#include <string>

using namespace std;

void correct_name(string& name) {
    for (int i = 0; i < name.length(); i++) {
        char& c = name[i];

        switch (c) {
            case 'i': c = 'e'; break;
            case 'e': c = 'i'; break;
            case 'I': c = 'E'; break;
            case 'E': c = 'I'; break;
            default: /*do nothing*/; break;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (string name; getline(cin, name);) {
        correct_name(name);
        cout << name << '\n';
    }

    return 0;
}