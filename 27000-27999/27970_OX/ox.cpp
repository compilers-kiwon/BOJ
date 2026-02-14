#include <iostream>
#include <string>

using namespace std;

#define MOD(n) ((n)%1000000007)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    string s;

    cin >> s, n = 0;

    for (; !s.empty(); s.pop_back()) {
        n = MOD(n * 2 + (s.back()=='O'?1:0));
    }

    cout << n << '\n';

    return 0;
}