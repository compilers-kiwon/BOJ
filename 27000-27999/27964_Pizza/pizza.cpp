#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

const string CHEESE = "Cheese";

bool is_Cheese(const string& t) {
    return ((t.length() >= CHEESE.length()) &&
            (t.substr(t.length() - CHEESE.length()) == CHEESE));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    unordered_set<string> cheese;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        string s;

        cin >> s;

        if (is_Cheese(s)) {
            cheese.insert(s);
        }
    }

    cout << ((cheese.size()>=4)?"yummy":"sad") <<'\n';

    return 0;
}