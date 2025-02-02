#include <iostream>

using namespace std;

int a, b, c, d;

inline int get_length(int x) {
    return max(a*(x-b)*(x-b)+c, d);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, cnt;

    cnt = 0;
    cin>>a>>b>>c>>d>>N;

    for (int i = 1; i <= N; i++) {
        int u, v;

        cin>>u>>v;

        if (u <= c && u == get_length(v)) {
            cnt++;
        }
    }

    cout<<cnt<<'\n';
    return 0;
}