#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_SIZE (2000)

void input(vector<int>& c) {
    int N;
    string S;

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        if (S[i] == '#') {
            c.push_back(i);
        }
    }
}

int find_cricket(const vector<int>& pos, vector<bool>& c, int period) {
    int ret = 0;

    for (int i = 0; i < pos.size(); i++) {
        if (c[pos[i]] == false) {
            continue;
        }

        ret++;

        for (int j = pos[i]; j < c.size(); j += period) {
            if (c[j] == false) {
                break;
            }

            c[j] = false;
        }
    }

    return ret;
}

bool check_cricket(const vector<bool>& c) {
    for (int i = 0; i < c.size(); i++) {
        if (c[i] == true) {
            return false;
        }
    }

    return true;
}

int simulate(const vector<int>& pos) {
    int ret = MAX_SIZE;

    for (int p = 1; p < MAX_SIZE; p++) {
        vector<bool> c(MAX_SIZE, false);

        for (int i = 0; i < pos.size(); i++) {
            c[pos[i]] = true;
        }

        int n = find_cricket(pos, c, p);

        if (check_cricket(c) == true) {
            ret = min(ret, n);
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> cricket;

    input(cricket);
    cout << simulate(cricket) << '\n';

    return 0;
}