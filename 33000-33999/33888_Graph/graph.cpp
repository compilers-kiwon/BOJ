#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (50+1)

int N, A, B, C, D, E, F;
bool marked[MAX_SIZE], visited[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void input(void) {
    cin >> N;

    for (int i = 1; i <= N + 3; i++) {
        int U, V;
        
        cin >> U >> V;
        
        connected[U].push_back(V);
        connected[V].push_back(U);
    }
}

int find_vertex(int num_connectged_edges) {
    int ret;

    for (int i = 1; i <= N; i++) {
        if (connected[i].size() == num_connectged_edges && marked[i] == false) {
            ret = i;
            break;
        }
    }

    return ret;
}

int dfs(int cur, int num_of_connected_edges) {
    if (connected[cur].size() == num_of_connected_edges && marked[cur] == false) {
        return cur;
    }

    for (int i = 0; i < connected[cur].size(); i++) {
        int adj = connected[cur][i];

        if (visited[adj] == true || marked[adj] == true) {
            continue;
        }

        visited[adj] = true;

        int v = dfs(adj, num_of_connected_edges);

        if (v != 0) {
            return v;
        }
    }

    return 0;
}

#define FIND(start,end,cond) { \
    fill(&visited[1], &visited[N+1], false); \
    visited[(start)] = true; \
    (end) = dfs((start), cond); \
    marked[(end)] = true; \
}

void simulate(void) {
    F = find_vertex(1);
    marked[F] = true;

    FIND(F, E, 4);
    FIND(E, C, 4);
    FIND(E, B, 3);
    FIND(E, D, 3);

    A = find_vertex(3);
    marked[A] = true;

    if (D < B) {
        swap(B, D);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    cout << A << ' ' << B << ' ' << C << ' '
            << D << ' ' << E << ' ' << F << '\n';

    return 0;
}