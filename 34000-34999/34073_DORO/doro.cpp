#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string d;

    for (cin >> N; N > 0; --N) {
        string w;
        cin >> w;
        d += w + "DORO" + (N==1?"\n":" ");
    }

    cout << d;

    return 0;
}