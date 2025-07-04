#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, time;

    cin>>N;
    time = -1;

    for (int i = 1; i <= N; i++) {
        unsigned int M, O;

        cin>>M>>O;

        if (O == 0) {
            time = min((unsigned int)time, M);
        }
    }

    cout<<time<<'\n';

    return 0;
}