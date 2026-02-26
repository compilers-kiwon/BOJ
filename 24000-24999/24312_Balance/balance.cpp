#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int NUM_OF_FRUITS = 4;

int input(vector<int>& fruits) {
    int ret = 0;

    for (int i = 1; i <= NUM_OF_FRUITS; ++i) {
        int w;
        cin >> w;
        fruits.push_back(w), ret += w;
    }

    return ret;
}

int simulate(vector<int>& fruits, int t) {
    int ret = t;

    do {
        int sum = 0;

        for (int i = 0; i < fruits.size(); ++i) {
            sum += fruits[i];
            ret = min(ret, abs(t-(2 *sum)));
        }
    } while(next_permutation(fruits.begin(), fruits.end()));

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> w;
    int total_weight = input(w);

    sort(w.begin(), w.end());
    cout << simulate(w, total_weight) << '\n';

    return 0;
}