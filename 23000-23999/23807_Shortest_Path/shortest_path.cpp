#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

const static int MAX_SIZE = 100000+1;
const static int MAX_STOPS = 100+1;

typedef long long int   int64;
typedef pair<int,int64> Path;
typedef pair<int64,int> State;

static int  N,M,X,Z,P,s[MAX_STOPS];
static int64 dist[MAX_STOPS][MAX_SIZE];
static vector<Path> connected[MAX_SIZE];

const static int64 NONE = -1;
const static int64 INF = 0x7FFFFFFFFFFFFFFF;

static inline int get_city(int stop_idx) {
    return  s[stop_idx];
}

void input(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;

    for (int i=1;i<=M;i++) {
        int u,v;
        int64 w;

        cin>>u>>v>>w;

        connected[u].push_back({v,w});
        connected[v].push_back({u,w});
    }

    cin>>X>>Z>>P;

    for (int i=1;i<=P;i++) {
        cin>>s[i];
        fill(&dist[i][1],&dist[i][N+1],INF);
    }
}

void get_distance_to_all_cities(int s_idx)
{
    priority_queue<State>   pq;

    pq.push({0,get_city(s_idx)});
    dist[s_idx][get_city(s_idx)] = 0;
    
    for (;!pq.empty();pq.pop()) {
        int cur_city = pq.top().second;
        int64 cur_dist = -pq.top().first;

        vector<Path>&   adj = connected[cur_city];

        for (int i=0;i<adj.size();i++) {
            int adj_city = adj[i].first;
            int64 adj_dist = cur_dist+adj[i].second;

            if (adj_dist < dist[s_idx][adj_city]) {
                pq.push({-adj_dist,adj_city});
                dist[s_idx][adj_city] = adj_dist;
            }
        }
    } 
}

int64 simulate(void)
{
    int64   ret = NONE;

    for (int i=1;i<=P;i++) {
        for (int j=1;j<=P;j++) {
            for (int k=1;k<=P;k++) {
                if (i==j || j==k || k==i) continue;

                int64 d1 = dist[i][X];
                int64 d2 = dist[i][s[j]];
                int64 d3 = dist[j][s[k]];
                int64 d4 = dist[k][Z];

                if (d1==INF || d2==INF || d3==INF || d4==INF) {
                    continue;
                }

                if (ret==NONE || (d1+d2+d3+d4)<ret) {
                    ret = d1+d2+d3+d4;
                }
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for (int i=1;i<=P;i++) {
        get_distance_to_all_cities(i);
    }

    cout<<simulate()<<'\n';
    return  0;
}