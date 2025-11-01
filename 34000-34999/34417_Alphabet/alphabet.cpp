#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string L, missed;
    bool visited[0x100];

    cin >> L;
    fill(&visited['A'], &visited['Z'+1], false);

    for (int i = 0; i < L.length(); i++) {
        visited[L[i]] = true;
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        if (visited[c] == false) {
            missed.push_back(c);
        }
    }

    cout << (missed.empty()?"Alphabet Soup!":missed) << '\n';
    return 0;
}