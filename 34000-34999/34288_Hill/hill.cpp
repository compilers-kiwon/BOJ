#include <iostream>
#include <vector>

using namespace std;

int input(vector<int>& heights) {
    int l, a;

    for (cin >> l >> a; l >= 0; l--) {
        int h;
        cin >> h;
        heights.push_back(h);
    }

    return a;
}

bool simulate(const vector<int>& h, int a) {
    for (int i = 1; i < h.size(); i++) {
        if ((h[i] - h[i-1]) > a) {
            return false;
        } 
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int acc;
    vector<int> track;

    acc = input(track);
    cout << (simulate(track, acc)?"POSSIBLE":"BUG REPORT") << '\n';

    return 0;
}