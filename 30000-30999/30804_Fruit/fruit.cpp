#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_SIZE (200000+1)

int N, S[MAX_SIZE];
unordered_map<int, int> used;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int h, t, max_num_of_fruits;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }

    used[S[1]] = 1;
    max_num_of_fruits = 0, h = 1, t = 2;

    for (;;) {
        if (used.size() <= 2) {
            max_num_of_fruits = max(max_num_of_fruits, t - h);

            if (t <= N) {
                used[S[t++]]++;
            } else {
                break;
            }
        } else {
            if(--used[S[h]] == 0) {
                used.erase(S[h]);
            }

            h++;
        }
    }

    cout << max_num_of_fruits << '\n';

    return 0;
}