#include    <iostream>
#include    <vector>
#include    <queue>
#include    <set>

using namespace std;

#define MAX_SIZE    (100000+1)
#define INF         0x7FFFFFFFFFFFFFFF

typedef long long int   int64;
typedef pair<int,int64> Path;   // first:to,second:cost
typedef pair<int64,int> State;  // first:-total_cost,second:Pos

int             N,M,A,B;
int64           C,dp[MAX_SIZE];
vector<Path>    connected[MAX_SIZE];
vector<int64>   candidate;

void    input(void)
{
    set<int64>  p;

    cin>>N>>M>>A>>B>>C;

    for(int i=1;i<=M;i++)
    {
        int     p1,p2;
        int64   cost;

        cin>>p1>>p2>>cost;
        p.insert(cost);

        connected[p1].push_back(make_pair(p2,cost));
        connected[p2].push_back(make_pair(p1,cost));
    }

    for(set<int64>::iterator it=p.begin();it!=p.end();it++)
    {
        candidate.push_back(*it);
    }
}

void    init_dp(void)
{
    fill(&dp[1],&dp[N+1],INF);dp[A] = 0;
}

bool    simulate(int64 payable)
{
    priority_queue<State>   pq;

    for(init_dp(),pq.push(make_pair(0,A));!pq.empty();)
    {
        int64   current_cost = -pq.top().first;
        int     current_pos = pq.top().second;
        
        pq.pop();

        if( current_pos == B )
        {
            return  true;
        }

        if( current_cost > dp[current_pos] )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int     adj_pos = adj[i].first;
            int64   adj_cost = current_cost+adj[i].second;

            if( adj_cost>C || adj[i].second>payable || adj_cost>=dp[adj_pos] )
            {
                continue;
            }
            
            dp[adj_pos] = adj_cost;
            pq.push(make_pair(-adj_cost,adj_pos));
        }
    }

    return  false;
}

int64   find_min_payable_money(void)
{
    int64   ret = -1;
    
    for(int left_idx=0,right_idx=candidate.size()-1;left_idx<=right_idx;)
    {
        int mid_idx = (left_idx+right_idx)>>1;

        if( simulate(candidate[mid_idx]) == false )
        {
            left_idx = mid_idx+1;
        }
        else
        {
            ret = candidate[mid_idx];
            right_idx = mid_idx-1;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<find_min_payable_money()<<'\n';

    return  0;
}