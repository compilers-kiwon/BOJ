#include    <iostream>
#include    <queue>

using namespace std;

typedef pair<int,pair<int,int>> Road;

int find_parent(int cur,int parent[])
{
    int& ret = parent[cur];
    if (ret != cur) ret = find_parent(ret,parent);
    return  ret;
}

bool input(priority_queue<Road>& pq)
{
    int n;

    cin>>n;
    if (n == 0) return false;

    for (int i=1;i<=n-1;i++) {
        char cur_pos;
        int num_of_adjs;

        cin>>cur_pos>>num_of_adjs;

        for (int j=1;j<=num_of_adjs;j++) {
            char adj_pos;
            int cost;

            cin>>adj_pos>>cost;
            pq.push({-cost,{cur_pos,adj_pos}});
        }
    }

    return  true;
}

int simulate(priority_queue<Road>& pq)
{
    int ret,parent[0x100];

    ret = 0;
    for (char c='A';c<='Z';c++) parent[c]=c;

    for (;!pq.empty();pq.pop()) {
        int cur_cost = -pq.top().first;
        int pos1 = pq.top().second.first;
        int pos2 = pq.top().second.second;

        int p1 = find_parent(pos1,parent);
        int p2 = find_parent(pos2,parent);

        if (p1 == p2) continue;

        parent[max(p1,p2)] = min(p1,p2);
        ret += cur_cost;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        priority_queue<Road> jungle_roads;
        if (input(jungle_roads) == false) break;
        cout<<simulate(jungle_roads)<<'\n';
    }

    return  0;
}