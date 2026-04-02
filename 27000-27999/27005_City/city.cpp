#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_SIZE (1000+1)
#define INF (MAX_SIZE*MAX_SIZE)

typedef pair<int, int> Pos; // <row, col>
typedef pair<Pos, int> State; // <Pos, num_of_steps>

int N, E, dp[MAX_SIZE][MAX_SIZE];
vector<Pos> connected[MAX_SIZE][MAX_SIZE];

void input(Pos& s, Pos& e) {
    cin >> N >> E;
    N = (2 * N) - 1, E = (2 * E) - 1;
    
    for (int row = 1; row <= N; ++row) {
        char buf[MAX_SIZE+1];

        cin >> &buf[1];
        fill(&dp[row][1], &dp[row][E+1], INF);

        for (int col = 1; col <= E; ++ col) {
            switch (buf[col]) {
                case 'S': s = {row, col}; break;
                case 'E': e = {row, col}; break;
                case '-':
                    connected[row][col-1].push_back({row, col + 1});
                    connected[row][col+1].push_back({row, col - 1});
                    break;
                case '|':
                    connected[row-1][col].push_back({row + 1, col});
                    connected[row+1][col].push_back({row - 1, col});
                    break;
                case '.':
                default :
                    // do nothing
                    break;
            }
        }
    }
}

void simulate(const Pos& s, const Pos& e) {
    queue<State> q;

    for (q.push({s, 0}), dp[s.first][s.second] = 0; !q.empty(); q.pop()) {
        Pos cur_pos = q.front().first;
        int cur_steps = q.front().second;

        if (cur_pos == e) {
            continue;
        }

        const vector<Pos>& adj = connected[cur_pos.first][cur_pos.second];

        for (int i = 0; i < adj.size(); ++i) {
            Pos a = adj[i];

            if (cur_steps + 1 < dp[a.first][a.second]) {
                q.push({a, cur_steps + 1});
                dp[a.first][a.second] = cur_steps + 1;
            }
        }
    }
}

char get_dir(const Pos& from, const Pos& to) {
    char ret;

    if (from.first == to.first) {
        ret = (from.second < to.second)?'E':'W';
    } else {
        ret = (from.first < to.first)?'S':'N';
    }

    return ret;
}

void backtrace_path(Pos p, int s, vector<pair<char, int>>& res) {
    while (s > 0) {
        --s;

        const vector<Pos>& adj = connected[p.first][p.second];

        for (int i = 0; i < adj.size(); ++i) {
            Pos a = adj[i];

            if (dp[a.first][a.second] == s) {
                char d = get_dir(a, p);
                
                if (!res.empty() && res.back().first == d) {
                    ++res.back().second;
                } else {
                    res.push_back({d, 1});
                }

                p = a;
                break;
            }
        }
    }
}

void print_path(const vector<pair<char, int>>& res) {
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i].first << ' ' << res[i].second << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Pos s, e;

    input(s, e);
    simulate(s, e);

    vector<pair<char, int>> path;

    backtrace_path(e, dp[e.first][e.second], path);
    print_path(path);

    return 0;
}