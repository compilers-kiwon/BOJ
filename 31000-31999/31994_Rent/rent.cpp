#include <iostream>
#include <string>
#include <map>

using namespace std;

#define MAX_SIZE (7)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    map<int, string> seminar;

    for (int i= 1; i <= MAX_SIZE; ++i) {
        int n;
        string s;

        cin >> s >> n;
        seminar[n] = s;
    }

    cout << seminar.rbegin()->second << '\n';

    return 0;
}