#include <iostream>
#include <string>

using namespace std;

#define NUM_OF_RATES (4)

const pair<int, int> RATES[NUM_OF_RATES] = {
    {0, 2}, {2, 4}, {4, 6}, {6, 10}
};

const string type[NUM_OF_RATES] = {
    "weak", "normal", "strong", "very strong"
};

bool in_range(int p, int r, int idx) {
    int lower = r * RATES[idx].first;
    int upper = r * RATES[idx].second;
    int scaled = 10 * p;

    return (lower <= scaled && scaled < upper);
}

int simulate(int p, int r) {
    int ret;

    for (int i = 0; i < NUM_OF_RATES; ++i) {
        if (in_range(p, r, i) == true) {
            ret = i;
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int p, r;
    cin >> p >> r;
    cout << type[simulate(p, r)] << '\n';

    return 0;
}