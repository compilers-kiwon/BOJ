#include <iostream>
#include <set>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    set<int> appeared;
    
    for (cin >> N; N > 0; N--) {
        int A;
        cin >> A;
        appeared.insert(A);
    }

    for (auto it = appeared.begin(); it != appeared.end(); it++) {
        cout << *it << '\n';
    }

    return 0;
}