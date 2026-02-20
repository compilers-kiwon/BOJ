#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> State;

void init(int size, vector<State>& s) {
    for (int i = 1; i <= size; ++i) {
        s[i] = {i - 1, i + 1};
    }

    s[0].second = 1;
    s[1].first = size;
    s[size].second = 1;
}

int simulate(vector<State>& s, int size, int p) {
    int cur = 0;

    for (; size > 0; --size) {
        for (int i = 1; i <= p; ++i) {
            cur = s[cur].second;
        }

        int left = s[cur].first;
        int right = s[cur].second;

        s[left].second = right;
        s[right].first = left;
    }

    return cur;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        int N, M;
        vector<State> s;

        cin >> N >> M;

        if (N == 0 && M == 0) {
            break;
        } else {
            s = vector<State>(N + 1);
            init(N, s);
        }

        cout << simulate(s, N, M) << '\n';
    }

    return 0;
}