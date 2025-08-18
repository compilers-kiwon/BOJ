#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define get_diff(a,b) (abs((a)-(b)))

const int INF = 0x7FFFFFFF;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, E, cnt;
    vector<int> D, st;

    cin >> N >> E;

    for (int i = 1; i <= N; i++) {
        int density;
        cin >> density;
        D.push_back(density);
    }

    sort(D.begin(), D.end());
    cnt = 0, st.push_back(INF);

    for (int i = 0; i < D.size(); i++) {
        if (get_diff(st.back(), D[i]) >= E) {
            cnt++;
        }

        st.push_back(D[i]);
    }

    cout << cnt << '\n';
    return 0;
}