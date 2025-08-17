#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, A, B, good, bad;
    
    cin >> N >> A >> B;
    good = bad = 1;

    for (int  n = 1; n <= N; n++) {
        good += A, bad += B;

        if (good < bad) {
            swap(good, bad);
        } else if (good == bad) {
            --bad;
        }
    }

    cout << good << ' ' << bad << '\n';
    return 0;
}