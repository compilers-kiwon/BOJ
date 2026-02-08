#include <iostream>

using namespace std;

#define MAX_SIZE (2000+1)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, a[MAX_SIZE], num_of_swaps;

    cin >> N, num_of_swaps = 0;

    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]), ++num_of_swaps;
            }
        }
    }

    cout << ((num_of_swaps%2==0)?"Yes":"No") << '\n';

    return 0;
}