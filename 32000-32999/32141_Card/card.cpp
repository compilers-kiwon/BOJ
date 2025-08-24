#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, H;

    cin >> N >> H;

    for (int i = 1; i <= N; i++) {
        int d;
        
        cin >> d;

        if ((H -= d) <= 0) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}