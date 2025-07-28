#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    size_t n, cur, start, length;
    
    cur = 0;
    cin >> s >> n;

    for (size_t i = 1; i <= n; i++) {
        cin >> start >> length;
        cur += start;
    }

    cout << s.substr(cur, length) << '\n';

    return 0;
}