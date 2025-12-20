#include <iostream>

using namespace std;

typedef long long int int64;

const int64 WORK_TIME = 8LL;

int64 get_num_of_middles(int64 total_time) {
    return ((total_time / WORK_TIME) - 1LL) +
                ((total_time % WORK_TIME)?1LL:0LL);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N, M, T, S;

    cin >> N >> M >> T >>S;

    int64 zip = N + (S * get_num_of_middles(N));
    int64 dok = T + M + ((2 * T + S) * get_num_of_middles(M));

    if (zip < dok) {
        cout << "Zip\n" << zip << '\n';
    } else {
        cout << "Dok\n" << dok << '\n';
    }

    return 0;
}