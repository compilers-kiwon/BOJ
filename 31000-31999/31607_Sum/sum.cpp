#include <iostream>
#include <vector>

using namespace std;

#define NUM_OF_NUMBERS (3)

enum {
    SUCCESS = 1,
    FAILURE = 0,
};

int simulate(const vector<int>& num, int sum) {
    for (int i = 0; i < num.size(); i++) {
        if (sum - num[i] == num[i]) {
            return SUCCESS;
        }
    }

    return FAILURE;
}

int input(vector<int>& num) {
    int sum = 0;

    for (int i = 0; i < NUM_OF_NUMBERS; i++) {
        int n;
        cin >> n;
        sum += n, num.push_back(n);
    }

    return sum;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int sum;
    vector<int> num;

    sum = input(num);
    cout << simulate(num, sum) << '\n';

    return 0;
}