#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void input(vector<string>& single, vector<string>& concatenated) {
    int n;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        string w;
        cin >> w;
        single.push_back(w);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            concatenated.push_back(single[i] + single[j]);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> single, concatenated;

    input(single, concatenated);
    sort(single.begin(), single.end());
    sort(concatenated.begin(), concatenated.end());

    int m;

    cin >> m;

    for (int i = 1; i <= m; ++i) {
        string typed;

        cin >> typed;

        if (binary_search(single.begin(), single.end(), typed)) {
            cout << "1\n";
        } else if (binary_search(concatenated.begin(), concatenated.end(), typed)) {
            cout << "2\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}