#include <iostream>

using namespace std;

const int MINUTES_IN_DAY = 24 * 60;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M, minutes;

    cin >> N >> M;
    minutes =  (MINUTES_IN_DAY * M) / N;
    printf("%02d:%02d", minutes / 60, minutes % 60);

    return 0;
}