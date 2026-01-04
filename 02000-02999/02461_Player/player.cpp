#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define MAX_SIZE (1000+1)
#define INF (1000000000)

typedef pair<int, int> State; // <-ability, class>

int N, M, ability[MAX_SIZE][MAX_SIZE], p[MAX_SIZE];

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> ability[i][j];
        }

        sort(&ability[i][1], &ability[i][M+1]);
    }
}

int simulate(void) {
    int ret, min_ability, max_ability;
    map<int, int> ability_cnt;
    priority_queue<State> pq;

    for (int i = 1; i <= N; i++) {
        int a = ability[i][1];
        pq.push({-a, i}), ++ability_cnt[a], p[i] = 1;
    }

    min_ability = ability_cnt.begin()->first;
    max_ability = ability_cnt.rbegin()->first;
    ret = max_ability - min_ability;

    for (;;) {
        int min_player_ability = -pq.top().first;
        int min_player_group = pq.top().second;

        pq.pop();
        
        if (--ability_cnt[min_player_ability] == 0) {
            ability_cnt.erase(min_player_ability);
        }

        if (p[min_player_group] < M) {
            int pos = p[min_player_group] + 1;
            int a = ability[min_player_group][pos];
        
            pq.push({-a, min_player_group});
            ability_cnt[a]++;
            p[min_player_group] = pos;
        } else {
            break;
        }

        min_ability = ability_cnt.begin()->first;
        max_ability = ability_cnt.rbegin()->first;
        ret = min(ret, max_ability - min_ability);
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