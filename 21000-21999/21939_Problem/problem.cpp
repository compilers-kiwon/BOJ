#include <iostream>
#include <queue>

using namespace std;

#define MAX_NUM_OF_PROBLEMS (100000+1)
#define MAX_DIFFICULTY (100+1)

typedef pair<int, int> Problem; // <difficulty, no>

int available_difficulty[MAX_NUM_OF_PROBLEMS];
bool solved[MAX_NUM_OF_PROBLEMS][MAX_DIFFICULTY];
priority_queue<Problem> difficult; // <difficulty, no>
priority_queue<Problem> easy; // <-difficulty, -no>

bool is_difficult_solved(void) {
    Problem p = difficult.top();
    return solved[p.second][p.first];
}

bool is_easy_solved(void) {
    Problem p = easy.top();
    return solved[-p.second][-p.first];
}

void read_problems(void) {
    int N;

    for (cin >> N; N > 0; N--) {
        int P, L;
        cin >> P >> L;
        available_difficulty[P] = L;
        difficult.push({L, P}), easy.push({-L, -P});
    }
}

void simulate(void) {
    int M;

    for (cin >> M; M > 0; M--) {
        string ins;

        cin >> ins;

        if (ins == "recommend") {
            int x;

            cin >> x;

            if (x == 1) {
                for (; is_difficult_solved() == true; difficult.pop());
                cout << difficult.top().second << '\n';
            } else {
                for (; is_easy_solved() == true; easy.pop());
                cout << -easy.top().second << '\n';
            }
        } else if (ins == "add") {
            int P, L;

            cin >> P >> L;
            
            solved[P][L] = false;
            available_difficulty[P] = L;

            difficult.push({L, P}), easy.push({-L, -P});
        } else { // ins == "solved"
            int P;
            cin >> P;
            solved[P][available_difficulty[P]] = true;
            available_difficulty[P] = 0;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    read_problems();
    simulate();

    return 0;
}