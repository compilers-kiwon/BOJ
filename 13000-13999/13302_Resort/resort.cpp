#include <iostream>
#include <queue>

using namespace std;

#define INF (0x7FFFFFFF)
#define MAX_SIZE (100+1)
#define MAX_NUM_OF_TICKETS (3)
#define NUM_OF_COUPONS_FOR_TICKET (3)

int N, M;
bool closed[MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

typedef pair<int, int> State;

#define day first
#define num_of_coupons second

const struct {
    int period, cost, coupons;
} ticket[MAX_NUM_OF_TICKETS] = {{1, 10000, 0}, {3, 25000, 1}, {5, 37000, 2}};

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int d;
        cin >> d;
        closed[d] = true;
    }

    for (int d = 0; d <= N; d++) {
        fill(&dp[d][0], &dp[d][MAX_SIZE], INF);
    }
}

int simulate(void) {
    int ret = INF;
    queue<State> q;

    for (q.push({0, 0}), dp[0][0] = 0; !q.empty(); q.pop()) {
        State cur = q.front();
        int cur_cost = dp[cur.day][cur.num_of_coupons];

        if (cur.day == N) {
            ret = min(ret, cur_cost);
            continue;
        }

        if (closed[cur.day+1] == true) {
            if (cur_cost < dp[cur.day+1][cur.num_of_coupons]) {
                q.push({cur.day+1, cur.num_of_coupons});
                dp[cur.day+1][cur.num_of_coupons] = cur_cost;
            }
        }

        if (cur.num_of_coupons >= NUM_OF_COUPONS_FOR_TICKET) {
            if (cur_cost < dp[cur.day+1][cur.num_of_coupons-NUM_OF_COUPONS_FOR_TICKET]) {
                q.push({cur.day+1, cur.num_of_coupons-NUM_OF_COUPONS_FOR_TICKET});
                dp[cur.day+1][cur.num_of_coupons-3] = cur_cost;
            }
        }

        for (int i = 0; i < MAX_NUM_OF_TICKETS; i++) {
            int adj_day = min(N, cur.day + ticket[i].period);
            int adj_num_of_coupons = cur.num_of_coupons + ticket[i].coupons;
            int adj_cost = cur_cost + ticket[i].cost;

            if (adj_cost < dp[adj_day][adj_num_of_coupons]) {
                q.push({adj_day, adj_num_of_coupons});
                dp[adj_day][adj_num_of_coupons] = adj_cost;
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