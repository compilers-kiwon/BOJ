#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    string S;

    cin >> n >> S;

    for (int i = 0; i < n; i++) {
        cout << ((S[i]=='l')?'L':'i');
    }

    cout << '\n';
    return 0;
}