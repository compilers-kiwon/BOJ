#include <iostream>

using namespace std;

#define INF (0x7FFFFFFF)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, T, B;

    cin>>N;
    T = 0, B = INF;

    for (int i = 1; i <= N; i++) {
        int time, length;

        cin>>time>>length;

        T = max(T, time);
        B = min(B, length);
    }

    cout<<((T * B) % 7) + 1<<'\n';

    return 0;
}