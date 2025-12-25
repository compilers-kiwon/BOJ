#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

#define SIZE_OF_MIDDLE_VAL (3)

void input(deque<int>& d) {
    int N;
    vector<int> num;

    for (cin >> N; N > 0; N--) {
        int a;
        cin >> a;
        num.push_back(a);
    }

    sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        d.push_back(num[i]);
    }
}

int simulate(deque<int>& d, vector<vector<int>>& steps) {
    for (; d.size() != 1;) {
        vector<int> num;

        for (int i = 0; i < SIZE_OF_MIDDLE_VAL; i++) {
            num.push_back(d.front());
            d.pop_front();
        }

        d.push_front(num[SIZE_OF_MIDDLE_VAL/2]);
        steps.push_back(num);
    }

    return d.front();
}

void print(int mid, const vector<vector<int>>& steps) {
    cout << mid << '\n';

    for (int i = 0; i < steps.size(); i++) {
        for (int j = 0; j < SIZE_OF_MIDDLE_VAL; j++) {
            cout << steps[i][j] << ((j==SIZE_OF_MIDDLE_VAL-1)?'\n':' ');
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int ans;
    deque<int> dq;
    vector<vector<int>> s;

    input(dq);
    ans = simulate(dq, s);
    print(ans, s);

    return 0;
}