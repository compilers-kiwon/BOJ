#include    <iostream>
#include    <vector>
#include    <queue>
#include    <algorithm>
#include    <climits>

using namespace std;

#define MAX_SIZE        10000
#define NUM_OF_ROADS    2

#define TRUE    1
#define FALSE   0
#define NONE    -1

static vector<int>  dp[NUM_OF_ROADS];
static vector<int>  road[NUM_OF_ROADS];

typedef struct{int pos,r,sum;}  State;

#define init_q(q,r) \
    ((q).push({0,r,road[(r)].front()}),dp[(r)][0]=road[(r)].front())

int read_road(int idx)
{
    int N;

    cin>>N;
    
    if( N == 0 )
    {
        return  FALSE;
    }

    dp[idx].clear();
    road[idx].clear();

    for(int i=0;i<N;i++)
    {
        int num;

        cin>>num;

        road[idx].push_back(num);
        dp[idx].push_back(INT_MIN);
    }

    return  TRUE;
}

int input(void)
{
    for(int i=0;i<NUM_OF_ROADS;i++)
    {
        if( read_road(i) == FALSE )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int get_pos(int r,int n)
{
    vector<int>::iterator   it;

    it = lower_bound(road[r].begin(),road[r].end(),n);

    if( it==road[r].end() || *it!= n )
    {
        return  NONE;
    }

    return  it-road[r].begin();
}

int simulate(void)
{
    queue<State>    q;

    for(init_q(q,0),init_q(q,1);!q.empty();q.pop())
    {
        int current_pos = q.front().pos;
        int current_road = q.front().r;
        int current_sum = q.front().sum;
        int current_num = road[current_road][current_pos];

        int adj_pos = current_pos+1;
        int adj_road = (current_road+1)%NUM_OF_ROADS;

        // 1. next
        if( current_pos != road[current_road].size()-1 )
        {
            int adj_num = road[current_road][adj_pos];

            if( dp[current_road][adj_pos] < current_sum+adj_num )
            {
                q.push({adj_pos,current_road,current_sum+adj_num});
                dp[current_road][adj_pos] = current_sum+adj_num;
            }
        }

        // 2. cross
        adj_pos = get_pos(adj_road,current_num);

        if( adj_pos==NONE || dp[adj_road][adj_pos] >= current_sum )
        {
            continue;
        }       

        q.push({adj_pos,adj_road,current_sum});
        dp[adj_road][adj_pos] = current_sum;
    }

    return  0;
}

int get_max_sum(void)
{
    int ret = INT_MIN;

    for(int i=0;i<NUM_OF_ROADS;i++)
    {
        ret = max(ret,dp[i].back());
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;input()!=FALSE;)
    {
        simulate();
        cout<<get_max_sum()<<'\n';
    }

    return  0;
}