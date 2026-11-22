#include <iostream>
#include <vector>
#include <set>

using namespace std;

void input(vector<int>& seq) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        seq.push_back(num);
    }
}

bool simulate(int a, int b, const vector<int>& seq) {
    for (int i = 1; i < seq.size(); ++i) {
        const int& prev = seq[i-1];
        const int& cur = seq[i];

        if ((prev * a + b) != cur){
            return false;
        }
    }

    return true;
}

void get_number(const vector<int>& seq, set<int>& candidates) {
    for (int a = -500; a <= 500; ++a) {
        for (int b = -50000; b <= 50000; ++b) {
            if (simulate(a, b, seq) == true) {
                candidates.insert(seq.back() * a + b);

                if (candidates.size() == 2) {
                    return;
                }
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> seq;
    set<int> candidates;

    input(seq);
    get_number(seq, candidates);

    if (candidates.size() == 1) {
        cout << *candidates.begin() << '\n';
    } else {
        cout << (candidates.empty()?'B':'A') << '\n';
    }

    return 0;
}