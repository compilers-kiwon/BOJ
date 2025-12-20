#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, sum;
    vector<int> a, b;

    cin >> N, sum = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        b.push_back(num);
    }

    for (int i = 0; i < N; i++) {
        sum += (max(0, a[i] - b[i]));
    }

    cout << sum << '\n';

    return 0;
}