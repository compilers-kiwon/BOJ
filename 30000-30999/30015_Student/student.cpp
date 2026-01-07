#include <iostream>
#include <vector>

using namespace std;

#define MSB_POS (19)

int count_num_of_students(const vector<int>& s, 
                            const vector<bool>& c, int a) {
    int ret = 0;

    for (int i = 0; i < s.size(); i++) {
        if (c[i] == true) {
            continue;
        }

        ret += ((a&s[i])==a)?1:0;
    }

    return ret;
}

int simulate(const vector<int>& s, int required) {
    int ret = 0;
    vector<bool> checked(s.size(), false);

    for (int m = MSB_POS; m >= 0; m--) {
        int n = count_num_of_students(s, checked, 1 << m);

        if (n >= required) {
            ret += 1 << m;

            for (int i = 0; i < s.size(); i++) {
                if (checked[i] == false) {
                    checked[i] = ((s[i]&(1<<m)) == 0);
                }
            }
        }
    }

    return ret;
}

int input(vector<int>& ability) {
    int N, K;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        ability.push_back(A);
    }

    return K;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K;
    vector<int> A;

    K = input(A);
    cout << simulate(A, K) << '\n';

    return 0;
}