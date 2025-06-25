#include <iostream>

#define MAX_TIME (10000+1)
#define MAX_NUM_OF_SUBJECTS (1000+1)

typedef std::pair<int,int> Subject; // <priority, required time>

int N, K, table[MAX_NUM_OF_SUBJECTS][MAX_TIME];
Subject sub[MAX_NUM_OF_SUBJECTS];

void input(void) {
    std::cin>>N>>K;

    for (int i = 1; i <= K; i++) {
        int& I = sub[i].first;
        int& T = sub[i].second;

        std::cin>>I>>T;
    }
}

void simulate(void) {
    for (int k = 1; k <= K; k++) {
        const int cur_prio = sub[k].first;
        const int cur_required_time = sub[k].second;

        if (cur_required_time <= N) {
            table[k][cur_required_time] = cur_prio;
        }

        for (int t = 1; t <= N; t++) {
            if (table[k-1][t] != 0) {
                table[k][t] = std::max(table[k][t], table[k-1][t]);
            
                if ((t + cur_required_time) <= N) {
                    table[k][t + cur_required_time] =
                        std::max(table[k][t + cur_required_time], table[k-1][t] + cur_prio);
                }
            }
        }
    }
}

int get_max_prio(void) {
    int ret = 0;

    for (int t = 1; t <= N; t++) {
        ret = std::max(ret, table[K][t]);
    }

    return ret;
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    input();
    simulate();

    std::cout<<get_max_prio()<<'\n';

    return 0;
}