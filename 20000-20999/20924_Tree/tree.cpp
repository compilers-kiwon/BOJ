#include    <iostream>
#include    <queue>
#include    <vector>

using namespace std;

const static int MAX_SIZE = 200000+1;

typedef pair<int,int> Path;     // first: to, second: distance
typedef pair<int,int> State;    // first: node, second: distance_to_node

static int N,R;
static bool visited[MAX_SIZE];
static vector<Path> connected[MAX_SIZE];
static vector<Path> tree[MAX_SIZE];

static inline void connect_nodes(int a,int b,int d) {
    connected[a].push_back({b,d});
    connected[b].push_back({a,d});
}

static inline void add_next_node_to_q(int cur_node,
                        Path p,queue<int>& q) {
    visited[p.first] = true;
    tree[cur_node].push_back(p);
    q.push(p.first);
}

void input(void)
{
    cin>>N>>R;

    for (int i=1;i<=N-1;i++) {
        int a,b,d;

        cin>>a>>b>>d;
        connect_nodes(a,b,d);
    }
}

void get_tree(void)
{
    queue<int>  q;

    for (visited[R]=true,q.push(R);!q.empty();q.pop()) {
        int cur = q.front();
        vector<Path>& adj = connected[cur];

        for (int i=0;i<adj.size();i++) {
            if (visited[adj[i].first]) continue;
            add_next_node_to_q(cur,adj[i],q);
        }
    }
}

int get_giga_node(int& dist)
{
    int ret = R;

    for (dist=0;tree[ret].size()==1;
            ret=tree[ret].front().first) {
        dist += tree[ret].front().second;
    }

    return  ret;
}

int get_length_of_longest_branch(int g)
{
    int ret = 0;
    queue<State>    q;

    for (q.push({g,0});!q.empty();q.pop()) {
        int cur_node = q.front().first;
        int cur_dist = q.front().second;

        vector<Path>&   adj = tree[cur_node];

        if (adj.empty()) {
            ret = max(ret,cur_dist);
            continue;
        }

        for (int i=0;i<adj.size();i++) {
            q.push({adj[i].first,
                    cur_dist+adj[i].second});
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_tree();

    int giga,length_to_giga;

    giga = get_giga_node(length_to_giga);
    
    cout<<length_to_giga<<' '
        <<get_length_of_longest_branch(giga)<<'\n';

    return  0;
}