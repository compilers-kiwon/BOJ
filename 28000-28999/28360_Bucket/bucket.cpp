#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (50+1)
#define NONE        0
#define UNKNOWN     -1.0
#define INIT_BUCKET 100.0

static int      N,M,num_of_flow_to[MAX_SIZE];
static double   dp[MAX_SIZE];

static vector<int>  flow_from[MAX_SIZE];

#define set_precision(n)    {cout<<fixed;cout.precision((n));}

int input(void)
{
    cin>>N>>M;
    fill(&dp[1],&dp[N+1],UNKNOWN);

    for(int i=1;i<=M;i++)
    {
        int v,w;

        cin>>v>>w;

        flow_from[w].push_back(v);
        num_of_flow_to[v]++;
    }

    return  0;
}

double  get_dp(int cur_bucket)
{
    double& ret = dp[cur_bucket];

    if( ret != UNKNOWN )
    {
        return  ret;
    }

    ret = 0.0;

    for(int i=0;i<flow_from[cur_bucket].size();i++)
    {
        int prev_bucket = flow_from[cur_bucket][i];
        
        ret += get_dp(prev_bucket)/
                (double)num_of_flow_to[prev_bucket];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double  max_bucket = 0.0;

    input();
    dp[1] = INIT_BUCKET;

    for(int i=1;i<=N;i++)
    {
        if( num_of_flow_to[i] == NONE )
        {
            max_bucket = max(max_bucket,get_dp(i));
        }
    }

    set_precision(6);
    cout<<max_bucket<<'\n';

    return  0;
}