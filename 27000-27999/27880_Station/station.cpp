#include <iostream>
#include <string>

using namespace std;

int main(void) {
    //cin.tie(NULL);
    //cin.sync_with_stdio(false);

    int depth = 0;
    
    string s;
    int x;

    for (; cin >> s >> x;) {
        if (s == "Es") {
            depth += x * 21;
        } else {
            depth += x * 17;
        }
    }

    cout << depth << '\n';

    return 0;
}