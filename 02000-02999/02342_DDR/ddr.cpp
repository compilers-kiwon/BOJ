#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (100000+1)

#define CENTER (0)
#define UP (1)
#define LEFT (2)
#define DOWN (3)
#define RIGHT (4)
#define MAX_DIR (5)

typedef pair<pair<int,int>,pair<int,int>> State;

const int effort_table[MAX_DIR][MAX_DIR] = {
    {1, 2, 2, 2, 2},
    {2, 1, 3, 4, 3},
    {2, 3, 1, 3, 4},
    {2, 4, 3, 1, 3},
    {2, 3, 4, 3, 1}
};

int step[MAX_SIZE], dp[MAX_SIZE][MAX_DIR][MAX_DIR];

static inline int get_effort(int from, int to) {
    return effort_table[from][to];
}

int input(void) {
    int i;

    for (i = 0; ; i++) {
        int s;
        cin>>s;

        if (s == 0) {
            break;
        } else {
            step[i+1] = s;
        }
    }

    return i;
}

int dance(int num_of_steps) {
    int ret;
    priority_queue<State> pq;
    State init = {{0,0}, {CENTER,CENTER}};

    for (pq.push(init); !pq.empty(); pq.pop()) {
        State current = pq.top();

        int current_effort = -current.first.first;
        int current_step = current.first.second;
        int current_left = current.second.first;
        int current_right = current.second.second;

        if (current_step == num_of_steps) {
            ret = current_effort;
            break;
        }

        int to = step[current_step+1];
        
        // move left foot
        if (current_right != to) {
            int next_effort = current_effort + get_effort(current_left, to);
            int next_step = current_step + 1;
            int next_left = to;
            int next_right = current_right;

            if (dp[next_step][next_left][next_right] == 0 ||
                    next_effort < dp[next_step][next_left][next_right]) {
                dp[next_step][next_left][next_right] = next_effort;
                pq.push({{-next_effort, next_step}, {next_left, next_right}});
            }
        }

        // move right foot
        if (current_left != to) {
            int next_effort = current_effort + get_effort(current_right, to);
            int next_step = current_step + 1;
            int next_left = current_left;
            int next_right = to;

            if (dp[next_step][next_left][next_right] == 0 ||
                    next_effort < dp[next_step][next_left][next_right]) {
                dp[next_step][next_left][next_right] = next_effort;
                pq.push({{-next_effort, next_step}, {next_left, next_right}});
            }
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_steps = input();

    if (num_of_steps == 0) {
        cout<<"0\n";
    } else {
        cout<<dance(num_of_steps)<<'\n';
    }

    return 0;
}