#include    <iostream>
#include    <vector>
#include    <queue>
#include    <algorithm>

using namespace std;

#define MAX_NUM_OF_BRIDGES  200000

typedef pair<int,int> Bridge;

static bool visited[MAX_NUM_OF_BRIDGES];

static inline bool in_range(int MIN,int n,int MAX) {
    return  (MIN<=n && n<=MAX);
}

void input(vector<Bridge>& b)
{
    int N;
    vector<Bridge> in;

    cin>>N;

    for (int i=1;i<=N;i++) {
        int L,R;
        cin>>L>>R;
        in.push_back({L,R});
    }

    sort(in.begin(),in.end());
    b.push_back({0,0});

    for (int i=0;i<N;i++) {
        Bridge& cur = in[i];

        if (in_range(b.back().first,cur.first,b.back().second)) {
            b.back().second = max(b.back().second,cur.second);
        } else {
            b.push_back(cur);
        }
    }
}

int simulate(const vector<Bridge>& b)
{
    int ret = 0;
    queue<int>  q;

    for (q.push(0),visited[0]=true;!q.empty();q.pop()) {
        int cur_bridge = q.front();
        int head_pos = b[cur_bridge].first;
        int tail_pos = b[cur_bridge].second;
        int can_jump = tail_pos-head_pos;

        ret = max(ret,tail_pos);

        for (int adj_bridge=cur_bridge+1;adj_bridge<b.size();adj_bridge++) {
            if (tail_pos+can_jump < b[adj_bridge].first) break;
            if (visited[adj_bridge]) continue;

            q.push(adj_bridge);
            visited[adj_bridge] = true;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Bridge>  bridges;

    input(bridges);
    cout<<simulate(bridges)<<'\n';

    return  0;
}