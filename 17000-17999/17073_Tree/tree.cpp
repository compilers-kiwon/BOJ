#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

const static int MAX_SIZE = 500000+1;

static int N;
static double W;
static bool visited[MAX_SIZE];
static vector<int> tree[MAX_SIZE];
static vector<int> connected[MAX_SIZE];

static inline void connect_nodes(int n1,int n2) {
    connected[n1].push_back(n2);
    connected[n2].push_back(n1);
}

static inline void set_precision(int len_of_fraction) {
    cout.precision(len_of_fraction);
    cout<<fixed;
}

void input(void)
{
    cin>>N>>W;

    for (int i=1;i<=N-1;i++) {
        int U,V;
        
        cin>>U>>V;
        connect_nodes(U,V);
    }
}

void get_tree(void)
{
    queue<int>  q;

    q.push(1);
    visited[1] = true;

    for (;!q.empty();q.pop()) {
        int cur = q.front();
        vector<int>& adj = connected[cur];

        for (int i=0;i<adj.size();i++) {
            if (visited[adj[i]]) continue;

            visited[adj[i]] = true;
            tree[cur].push_back(adj[i]);
            q.push(adj[i]);
        }
    }
}

double simulate(void)
{
    int num_of_leaf_nodes = 0;
    queue<int>  q;

    visited[1] = true;
    q.push(1);

    for (;!q.empty();q.pop()) {
        int cur = q.front();

        if (tree[cur].empty()) {
            num_of_leaf_nodes++;
            continue;
        }

        for (int i=0;i<tree[cur].size();i++) {
            q.push(tree[cur][i]);
        }
    }

    return  (W/(double)num_of_leaf_nodes);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_tree();

    set_precision(4);
    cout<<simulate()<<'\n';

    return  0;
}