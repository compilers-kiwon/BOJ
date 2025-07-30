#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    priority_queue<char> num, alpha;

    cin >> s;

    for (size_t i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            num.push(s[i]);
        } else {
            alpha.push(-s[i]);
        }
    }

    for (; !num.empty() && !alpha.empty(); num.pop(), alpha.pop()) {
        cout << (char)(-alpha.top()) << num.top();
    }

    return 0;
}