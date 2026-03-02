#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void input(vector<int>& A, vector<int>& B,
            unordered_set<int>& used) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        A.push_back(num), used.insert(num);
    }

    for (int i = 1; i <= 2 * N; ++i) {
        int num;
        cin >> num;
        B.push_back(num);
    }
}

bool is_prefix(const vector<int>& small,
                const vector<int>& big) {
    for (int i = 0; i < small.size(); ++i) {
        if (small[i] != big[i]) {
            return false;
        }
    }

    return true;
}

bool can_build_suffix(const vector<int>& arr,
                        const unordered_set<int>& used) {
    for (int i = arr.size() / 2; i < arr.size(); ++i) {
        if (used.find(arr[i]) == used.end()) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> A, B;
    unordered_set<int> used;

    input(A, B, used);

    if (is_prefix(A, B) && can_build_suffix(B, used)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}