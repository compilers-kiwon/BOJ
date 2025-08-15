#include <iostream>

using namespace std;

#define MAX_SIZE (100000+1)
#define is_odd(n) (((n)%2)==1)

int N, cnt[MAX_SIZE];
int num_of_odds, num_of_evens;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_num_of_soldiers = 0;

    cin >> N;
    num_of_evens = N / 2;
    num_of_odds = (N / 2) + (is_odd(N)?1:0);

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        max_num_of_soldiers =
            max(max_num_of_soldiers, ++cnt[a]);
    }

    if (max_num_of_soldiers <=
            max(num_of_evens, num_of_odds)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}