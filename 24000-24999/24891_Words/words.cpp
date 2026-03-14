#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_magic_sqaure(const vector<string>& square) {
    for (int i = 0; i < square.size(); ++i) {
        string w;

        for (int row = 0; row < square.size(); ++row) {
            w.push_back(square[row][i]);
        }

        if (square[i] != w) {
            return false;
        }
    }

    return true;
}

bool simulate(vector<string>& candidates,
                vector<string>& square, int square_size) {
    if (square.size() == square_size) {
        return is_magic_sqaure(square);
    }

    for (int i = 0; i < candidates.size(); ++i) {
        if (candidates[i].empty()) {
            continue;
        }

        square.push_back(candidates[i]);
        candidates[i] = "";

        if (simulate(candidates, square, square_size) == true) {
            return true;
        }

        candidates[i] = square.back();
        square.pop_back();
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int L, N;
    vector<string> candidates, square;

    cin >> L >> N;

    for (int i = 1; i <= N; ++i) {
        string s;
        cin >> s;
        candidates.push_back(s);
    }

    sort(candidates.begin(), candidates.end());
    
    if (simulate(candidates, square, L) == false) {
        square.push_back("NONE");
    }

    for (int i = 0; i < square.size(); ++i) {
        cout << square[i] << '\n';
    }

    return 0;
}