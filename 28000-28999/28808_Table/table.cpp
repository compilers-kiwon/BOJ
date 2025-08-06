#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, m, solved;

    solved = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        solved += ((s.find('+')!=string::npos)?1:0);
    }

    cout << solved << '\n';

    return 0;
}