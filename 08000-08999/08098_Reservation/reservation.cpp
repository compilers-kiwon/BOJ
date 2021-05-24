#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (30000+1)
#define TBD         -1

int         n,max_end_time,dp[MAX_SIZE];
vector<int> lecture_time[MAX_SIZE];         // [end_time] = <start_time1,start_time2,...>

void    input(void)
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int p,k;

        cin>>p>>k;

        lecture_time[k].push_back(p);
        max_end_time = max(max_end_time,k);
    }

    fill(&dp[0],&dp[max_end_time+1],TBD);
}

int     get_dp(int end_time)
{
    if( end_time < 0 )
    {
        return  0;
    }

    int&    ret = dp[end_time];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = get_dp(end_time-1);

    for(int i=0;i<lecture_time[end_time].size();i++)
    {
        int start_time = lecture_time[end_time][i];

        ret = max(ret,get_dp(start_time)+end_time-start_time);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_dp(max_end_time)<<'\n';

    return  0;
}