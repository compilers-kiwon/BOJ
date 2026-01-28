#include <iostream>

using namespace std;

typedef long long int int64;

int64 const dice[6+1] = {0LL, 6LL, 5LL, 4LL, 3LL, 2LL, 1LL};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 n, min_score, max_score;
    
    cin >> n;
    max_score = n * 6LL, min_score = n / 6LL + dice[n%6LL];
    cout << min_score << ' ' << max_score << '\n';

    return 0;
}