#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_TIME    10080
#define TBD         -1

typedef pair<int,int>   State;  // first:duration,second:score

int             dp[MAX_TIME+1];
vector<State>   schedule[MAX_TIME+1];

void    init(void)
{
    fill(&dp[1],&dp[MAX_TIME+1],TBD);

    for(int i=1;i<=MAX_TIME;i++)
    {
        schedule[i].clear();
    }
}

void    input(void)
{
    int n;

    cin>>n;
    init();

    for(int i=1;i<=n;i++)
    {
        int s,d,p;

        cin>>s>>d>>p;
        schedule[s+d].push_back(make_pair(d,p));
    }
}

int     get_dp(int time)
{
    int&    ret = dp[time];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = get_dp(time-1);

    vector<State>&  available = schedule[time];

    for(int i=0;i<available.size();i++)
    {
        int&    duration = available[i].first;
        int&    score = available[i].second;
        
        ret = max(ret,get_dp(time-duration)+score);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for(;t!=0;t--)
    {
        input();
        cout<<get_dp(MAX_TIME)<<'\n';
    }

    return  0;
}