#include <iostream>
#include <string>

using namespace std;

#define INF (100*1000*100)
#define MAX_SIZE (10000+1)

int N, K, cable[MAX_SIZE];

bool simulate(int size_of_piece) {
    int ret = 0;

    for (int i = 1; i <= N; i++) {
        ret += cable[i] / size_of_piece;

        if (ret >= K) {
            return true;
        }
    }

    return false;
}

int bin_search(int lo, int hi) {
    int ret = 0;

    for (; lo <= hi;) {
        int mid = (lo + hi) / 2;

        if (simulate(mid) == true) {
            ret = mid, lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return ret;
}

int input(void) {
    int max_size = 0;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        int m, c;
        char dot;

        cin >> m >> dot >> c;
        cable[i] = (m * 100) + c;
        max_size = max(max_size, cable[i]);
    }

    return max_size;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_size, ans;

    max_size = input();
    ans = bin_search(1, max_size);

    string m = to_string(ans / 100);
    string c = to_string(ans % 100);
    
    cout << m << '.' << ((c.length()!=2)?"0":"") << c << '\n';

    return 0;
}