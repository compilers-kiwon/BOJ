#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (1000000+1)
#define NUM_OF_ACTIONS (2)

int N, K;
char state[MAX_SIZE+1];
bool visited[MAX_SIZE];

bool simulate(void) {
    queue<int> q;
    int offset[NUM_OF_ACTIONS] = {1, K};

    for (q.push(1), visited[1] = true; !q.empty(); q.pop()) {
        int cur_pos = q.front();

        if (cur_pos == N) {
            break;
        }

        for (int i = 0; i < NUM_OF_ACTIONS; i++) {
            int adj_pos = cur_pos + offset[i];
        
            if (adj_pos <= N && !visited[adj_pos] && state[adj_pos] == '_') {
                q.push(adj_pos), visited[adj_pos] = true;
            }
        }
    }

    return visited[N];
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N >> K >> &state[1];
    cout << (simulate()?"YES":"NO") << '\n';

    return 0;
}