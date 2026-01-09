#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool simulate(const vector<int>& s, vector<int>& w) {
    for (int h = 0; h < s.size() - 2; h++) {
        for (int t = h + 2; t < s.size(); t++) {
            int a1, a2, a3;
            
            a1 = s[h], a3 = s[t];

            if ((a3 - a1) % 2 != 0) {
                continue;
            }

            a2 = a1 + (a3 - a1) / 2;

            auto it = lower_bound(s.begin(), s.end(), a2);

            if (*it == a2) {
                w.push_back(a1);
                w.push_back(a2);
                w.push_back(a3);

                return true;
            }
        }
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    vector<int> seq, wit;

    for (cin >> n; n > 0; n--) {
        int num;
        cin >> num;
        seq.push_back(num);
    }

    sort(seq.begin(), seq.end());

    if (simulate(seq, wit) == false) {
        cout << "Sequence is 3-free.\n";
    } else {
        cout << "Sequence is not 3-free. Witness: ";
        cout << wit[0] << ',' << wit[1] << ',' << wit[2] << ".\n";
    }

    return 0;
}