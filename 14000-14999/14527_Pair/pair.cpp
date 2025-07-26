#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE (100000+1)

typedef pair<int, int> State; // <milk, num>

int N;
State s[MAX_SIZE];

void input(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int& x = s[i].second;
        int& y = s[i].first;
        cin >> x >> y;
    }

    sort(&s[1], &s[N+1]);
}

int simulate(void) {
    int ret = 0;

    for (int h = 1, t = N; h <= t;) {
        ret = max(ret, s[h].first + s[t].first);

        if (h == t) {
            break;
        } else {
            int& num_of_small_cows = s[h].second;
            int& num_of_big_cows = s[t].second;

            if (num_of_small_cows < num_of_big_cows) {
                num_of_big_cows -= num_of_small_cows;
                h++;
            } else if (num_of_small_cows > num_of_big_cows) {
                num_of_small_cows -= num_of_big_cows;
                t--;
            } else {
                h++, t--;
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}