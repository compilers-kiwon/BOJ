#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define MAX_NUM (10000)
#define MAX_SIZE (5000+1)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int N, M, arr[MAX_SIZE];

bool can_be_merged(const set<int>& sub, int cur_num, int upper_of_diff) {
    int min_num = *sub.begin();
    int max_num = *sub.rbegin();

    if (IN_RANGE(min_num, cur_num, max_num)) {
        return true;
    }

    min_num = min(min_num, cur_num);
    max_num = max(max_num, cur_num);

    if (max_num - min_num <= upper_of_diff) {
        return true;
    }

    return false;
}

int divide(int upper_of_diff) {
    set<int> cur;
    int num_of_subs = 0;

    for (int i = 1; i <= N; ++i) {
        int num = arr[i];

        if (!cur.empty() && !can_be_merged(cur, num, upper_of_diff)) {
            ++num_of_subs, cur.clear();
        }
        
        cur.insert(num);
    }

    return (num_of_subs + (cur.empty()?0:1));
}

int bin_search(int lo, int hi) {
    int ret;

    for (; lo <= hi;) {
        int mid = (lo + hi) / 2;

        if (divide(mid) <= M) {
            ret = mid, hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ret;
}

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << bin_search(0, MAX_NUM) << '\n';

    return 0;
}