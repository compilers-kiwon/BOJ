#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void input(vector<int>& dist) {
    int N, S;

    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        dist.push_back(abs(A - S));
    }

    sort(dist.begin(), dist.end());
}

int get_gcd(int small, int big) {
    for (int mod = big % small; mod > 0; mod = big % small) {
        big = small;
        small = mod;
    }

    return small;
}

int simulate(const vector<int>& dist) {
    int ret = dist.front();

    for (int i = 0; i < dist.size(); i++) {
        ret = get_gcd(ret, dist[i]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> dist;

    input(dist);
    cout << simulate(dist) << '\n';

    return 0;
}