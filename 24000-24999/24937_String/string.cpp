#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, p;
    string str = "SciComLove";

    cin >> N;
    p = N % str.length();
    cout << str.substr(p) << str.substr(0, p) << '\n';

    return 0;
}