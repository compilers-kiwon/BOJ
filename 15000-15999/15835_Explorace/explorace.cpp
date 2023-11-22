#include    <iostream>
#include    <queue>

using namespace std;

const static int MAX_SIZE = 20+1;

typedef pair<int,pair<int,int>> State;  // <-d,<n1,n2>>

static inline void init_arr(int arr[],int size) {
    for (int i=1;i<=size;i++) arr[i]=i;
}

static inline void merge(int n1,int n2,int parent[]) {
    parent[max(n1,n2)] = min(n1,n2);
}

int find_parent(int n,int parent[])
{
    int&    ret = parent[n];
    if (ret != n) ret=find_parent(ret,parent);
    return  ret;
}

int input(priority_queue<State>& pq)
{
    int N,M;

    cin>>N>>M;

    for (int i=1;i<=M;i++) {
        int a,b,d;
        cin>>a>>b>>d;
        pq.push({-d,{a,b}});
    }

    return  N;
}

int simulate(void)
{
    int num_of_checkpoints,total_distance;
    int parent[MAX_SIZE];
    priority_queue<State> paths;

    total_distance = 0;
    num_of_checkpoints = input(paths);
    init_arr(parent,num_of_checkpoints);

    for (;!paths.empty();paths.pop()) {
        int d = -paths.top().first;
        int a = paths.top().second.first;
        int b = paths.top().second.second;

        int a_parent = find_parent(a,parent);
        int b_parent = find_parent(b,parent);

        if (a_parent == b_parent) continue;
        merge(a_parent,b_parent,parent);
        total_distance += d;
    }

    return  total_distance;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t=1;t<=T;t++) {
        cout<<"Case #"<<t<<": "
            <<simulate()<<" meters\n";
    }

    return  0;
}