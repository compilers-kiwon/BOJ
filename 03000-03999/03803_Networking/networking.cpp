#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,pair<int,int>> Cable;

#define MAX_NUM_OF_POINTS (50+1)

int parent[MAX_NUM_OF_POINTS];

int find_parent(int n) {
    int& ret = parent[n];

    if (ret != n) {
        ret = find_parent(ret);
    }

    return ret;
}

bool input(priority_queue<Cable>& pq) {
    int P, R;

    cin>>P;

    if (P == 0) {
        return false;
    }

    for (int i = 1; i <= P; i++) {
        parent[i] = i;
    }

    cin>>R;

    for (int r = 1; r <= R; r++) {
        int i, j, l;
        cin>>i>>j>>l;
        pq.push({-l,{min(i,j),max(i,j)}});
    }

    return true;
}

int build_network(priority_queue<Cable>& pq) {
    int ret = 0;

    for (; !pq.empty(); pq.pop()) {
        int len = -pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;

        int pi = find_parent(i);
        int pj = find_parent(j);

        if (pi == pj) {
            continue;
        }

        ret += len;
        parent[max(pi,pj)] = min(pi,pj);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    for (;;) {
        priority_queue<Cable> pq_cable;

        if (input(pq_cable) == false) {
            break;
        }

        cout<<build_network(pq_cable)<<'\n';
    }

    return 0;
}