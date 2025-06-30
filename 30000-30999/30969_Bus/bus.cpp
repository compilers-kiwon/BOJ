#include <iostream>
#include <string>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, ans;
    int cnt[1000+1] = {0, };
    int64 cost;

    cin>>N;
    ans = cost = 0;

    for (int i = 1; i <= N; i++) {
        int64 C;
        string D;

        cin>>D>>C;

        if (D == "jinju") {
            cost = C;

            for (int i = cost + 1; i <= 1000; i++) {
                ans += cnt[i];
            }
        }
        
        if (C > 1000) {
            ++ans;
        } else {
            if (cost > 0) {
                if (C > cost) {
                    ++ans;
                }
            } else {
                ++cnt[C];
            }
        }
    }

    cout<<cost<<'\n'<<ans<<'\n';

    return 0;
}