#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

const unordered_set<string> promise = {
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie and hurt you",
    "Never gonna stop",
};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;

    getline(cin, s);

    for (int N = stoi(s); N > 0; --N) {
        string str;
        getline(cin, str);

        if (promise.find(str) == promise.end()) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}