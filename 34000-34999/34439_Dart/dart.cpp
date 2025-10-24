#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define NUM_OF_DARTS (3)
#define MAX_NUM (20)

const int score[MAX_NUM]
    = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17,
       3, 19, 7, 16, 8, 11, 14, 9, 12, 5};

int get_num_of_pos(int n) {
    int pos;

    for (pos = 0; pos < MAX_NUM; pos++) {
        if (n == score[pos]) {
            break;
        }
    }

    return pos;
}

int get_score(int from, int to) {
    int ret = score[to];

    for (int i = from; i != to; i = (i + 1) % MAX_NUM) {
        ret += score[i];
    }

    return ret;
}

int simulate(const vector<int>& dart) {
    int max_score = 0;
    vector<int> pos;

    for (int i = 0; i < dart.size(); i++) {
        pos.push_back(get_num_of_pos(dart[i]));
    }

    sort(pos.begin(), pos.end());

    for (int i = 0; i < dart.size(); i++) {
        int p1 = pos[i];
        int p2 = pos[(i+1)%pos.size()];

        max_score = max(max_score, get_score(p1, p2));
    }

    return max_score;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        vector<int> d;

        for (int i = 1; i <= NUM_OF_DARTS; i++) {
            int w;
            cin >> w;
            d.push_back(w);
        }

        cout << simulate(d) << '\n';
    }

    return 0;
}