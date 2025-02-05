#include <iostream>
#include <queue>
#include <cstdint>

using namespace std;

#define MAX_NUM_OF_CONTESTS (100000+1)

int N;
uint64_t x[MAX_NUM_OF_CONTESTS], p[MAX_NUM_OF_CONTESTS];

bool simulate(void) {
    bool ret = true;
    priority_queue<uint64_t> prize_pq;
    uint64_t sum_of_prize = 0;

    for (int cur_contest = 1; cur_contest <= N; cur_contest++) {
        if (sum_of_prize <= x[cur_contest]) {
            sum_of_prize += p[cur_contest];
            prize_pq.push(p[cur_contest]);
        } else {
            uint64_t prev_max_prize = prize_pq.top();

            if ((sum_of_prize - prev_max_prize) <= x[cur_contest]) {
                if (prev_max_prize > p[cur_contest]) {
                    prize_pq.pop();
                    sum_of_prize -= prev_max_prize;
                    
                    prize_pq.push(p[cur_contest]);
                    sum_of_prize += p[cur_contest];
                } else {
                    // Skip the current contest
                }
            } else {
                // Skip the current contest
            }
        }

        if ((cur_contest - prize_pq.size()) > 1) {
            ret = false;
            break;
        }
    }

    return ret;
}

void input(void) {
    cin>>N;

    for (int i = 1; i <= N; i++) {
        cin>>x[i]>>p[i];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<(simulate()?"Kkeo-eok":"Zzz")<<'\n';

    return 0;
}