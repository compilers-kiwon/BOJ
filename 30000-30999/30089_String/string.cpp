#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string simulate(const string& src) {
    string ret;

    for (int i = 0; i < src.length(); ++i) {
        string head, tail;
        
        head = src.substr(0, i);
        tail = src.substr(i);
        reverse(tail.begin(), tail.end());
        
        if (head + tail == src) {
            reverse(head.begin(), head.end());
            ret = src + head;
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin >> T; T > 0; --T) {
        string S;
        cin >> S;
        cout << simulate(S) << '\n';
    }

    return 0;
}