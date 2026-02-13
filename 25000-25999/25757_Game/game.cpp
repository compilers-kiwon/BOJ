#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    char G;
    set<string> players;

    for (cin >> N >> G; N > 0; --N) {
        string s;
        cin >> s;
        players.insert(s);
    }

    cout << players.size() / (G=='Y'?1:G=='F'?2:3) << '\n';

    return 0;
}