#include <iostream>
#include <set>

using namespace std;

#define MAX_SIZE (99+1)

typedef struct {
    set<int> light, heavy;
} State;

int N, M;
bool heavy_visited[MAX_SIZE], light_visited[MAX_SIZE];
State marble[MAX_SIZE];

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int h, l;

        cin >> h >> l;
        
        marble[l].heavy.insert(h);
        marble[h].light.insert(l);
    }
}

int get_num_of_heavy_marbles(int cur) {
    int ret = 1;

    heavy_visited[cur] = true;

    for (auto it = marble[cur].heavy.begin(); it != marble[cur].heavy.end(); it++) {
        if (heavy_visited[*it] == true) {
            continue;
        }
        ret += get_num_of_heavy_marbles(*it);
    }

    return ret;
}

int get_num_of_light_marbles(int cur) {
    int ret = 1;

    light_visited[cur] = true;

    for (auto it = marble[cur].light.begin(); it != marble[cur].light.end(); it++) {
        if (light_visited[*it] == true) {
            continue;
        }

        ret += get_num_of_light_marbles(*it);
    }

    return ret;
}

bool determine_mid_weight(int m) {
    int mid = (N + 1) / 2;
    return (get_num_of_heavy_marbles(m) <= mid
                && get_num_of_light_marbles(m) <= mid);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_impossible_marbles = 0;

    input();

    for (int m = 1; m <= N; m++) {
        fill(&heavy_visited[1], &heavy_visited[N+1], false);
        fill(&light_visited[1], &light_visited[N+1], false);
        num_of_impossible_marbles += determine_mid_weight(m)?0:1;
    }

    cout << num_of_impossible_marbles << '\n';
    return 0;
}