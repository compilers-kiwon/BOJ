#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> Dist;

priority_queue<Dist> commute_pq; // <-right, left>
priority_queue<int> prev_left_pq; // -left

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, d;
    size_t cnt;

    cin>>n;

    for (int i = 1; i <= n; i++) {
        int h, o;

        cin>>h>>o;
        commute_pq.push({-max(h,o), min(h,o)});
    }

    cin>>d;
    cnt = 0;

    for (; !commute_pq.empty(); commute_pq.pop()) {
        int cur_left = commute_pq.top().second;
        int cur_right = -commute_pq.top().first;

        if ((cur_right - cur_left) > d) {
            continue;
        }

        prev_left_pq.push(-cur_left);
        
        for (;!prev_left_pq.empty(); prev_left_pq.pop()) {
            int prev_most_left = -prev_left_pq.top();
            int farthest_left_from_cur_right = cur_right - d;

            if (prev_most_left >= farthest_left_from_cur_right) {
                break;
            }
        }

        cnt = max(cnt, prev_left_pq.size());
    }

    cout<<cnt<<'\n';

    return 0;
}