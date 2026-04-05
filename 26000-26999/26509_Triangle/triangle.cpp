#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void read_length(vector<int>& length) {
    for (int i = 0; i < 3; ++i) {
        int n;
        cin >> n;
        length.push_back(n);
    }

    sort(length.begin(), length.end());
}

bool is_triangle(const vector<int>& length) {
    int sum = 0;

    for (int i = 0; i < length.size() - 1; ++i) {
        sum += length[i] * length[i];
    }

    return (sum == length.back() * length.back());
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        vector<int> a, b;
        read_length(a), read_length(b);
        cout << ((a==b&&is_triangle(a))?"YES":"NO") << '\n';
    }

    return 0;
}