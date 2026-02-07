#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_EXP (9)
#define MAX_NUM (1000000)

vector<int> p[MAX_EXP+1];

void init(int e) {
    vector<int>& n = p[e];

    n.push_back(0);

    for (int i = 1, num = 1; num <= MAX_NUM; ++i) {
        num = p[e-1][i] * i;
        n.push_back(num);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    p[0] = vector<int>(MAX_NUM + 2, 1);
    
    for (int i = 1; i <= MAX_EXP; ++i) {
        init(i);
    }

    for (int B, N;;) {
        cin >> B >> N;

        if (B == 0 && N == 0) {
            break;
        }

        auto it = lower_bound(p[N].begin(), p[N].end(), B);

        int lo = *(it - 1);
        int hi = *(it);

        if ((B - lo) < (hi - B)) {
            cout << (it - 1) - p[N].begin() << '\n';
        } else {
            cout << it - p[N].begin() << '\n';
        }
    }

    return 0;
}