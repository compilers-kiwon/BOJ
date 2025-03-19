#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, y, m;

    cin>>N;
    y = 2024, m = 8;

    for (int i = 1; i < N; i++) {
        m += 7;

        if (m > 12) {
            ++y, m -= 12;
        }
    }

    cout<<y<<' '<<m<<'\n';
    return 0;
}