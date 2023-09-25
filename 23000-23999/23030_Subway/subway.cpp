#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_NUM_OF_LINES    (10+1)
#define MAX_NUM_OF_STATIONS (50+1)

#define INF 0x7FFFFFFF

typedef pair<int,int>   Transfer;   // first: line, second: station

static int  N,M,num_of_stations[MAX_NUM_OF_LINES];
static int  dp[MAX_NUM_OF_LINES][MAX_NUM_OF_STATIONS];
static Transfer tr[MAX_NUM_OF_LINES][MAX_NUM_OF_STATIONS];

typedef pair<int,pair<int,int>> State;  // first: -time, second: <first: line, second: station>

#define push_new_path(t,l,s,pq) {dp[(l)][(s)]=(t);(pq).push({-(t),{(l),(s)}});}

int init_dp(void)
{
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=num_of_stations[i];j++) {
            dp[i][j] = INF;
        }
    }

    return  0;
}

int simulate(void)
{
    int T,U1,U2,V1,V2,ret;
    priority_queue<State> pq;
    const Transfer  none = {0,0};

    cin>>T>>U1>>U2>>V1>>V2;
    init_dp();
    
    pq.push({0,{U1,U2}});
    dp[U1][U2] = 0;

    for(;!pq.empty();) {
        int cur_time = -pq.top().first;
        int cur_line = pq.top().second.first;
        int cur_station = pq.top().second.second;
        
        pq.pop();
        if (cur_line==V1 && cur_station==V2) {
            ret = cur_time;
            break;
        }

        if (cur_station>1 &&
                cur_time+1<dp[cur_line][cur_station-1]) {
            push_new_path(cur_time+1,cur_line,cur_station-1,pq);
        }

        if (cur_station<num_of_stations[cur_line] &&
                cur_time+1<dp[cur_line][cur_station+1]) {
            push_new_path(cur_time+1,cur_line,cur_station+1,pq);
        }

        if (tr[cur_line][cur_station] != none) {
            int tr_line = tr[cur_line][cur_station].first;
            int tr_station = tr[cur_line][cur_station].second;

            if (cur_time+T < dp[tr_line][tr_station]) {
                push_new_path(cur_time+T,tr_line,tr_station,pq);
            }
        }
    }

    return  ret;
}

int input(void)
{
    cin>>N;
    for (int i=1;i<=N;i++) {
        cin>>num_of_stations[i];
    }

    cin>>M;
    for (int i=1;i<=M;i++) {
        int P1,P2,Q1,Q2;
        cin>>P1>>P2>>Q1>>Q2;

        tr[P1][P2] = {Q1,Q2};
        tr[Q1][Q2] = {P1,P2};
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int K;

    input();
    cin>>K;

    for (int i=1;i<=K;i++) {
        cout<<simulate()<<'\n';
    }

    return  0;
}