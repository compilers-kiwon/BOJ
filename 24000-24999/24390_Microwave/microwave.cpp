#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_OPERATIONAL_TIME    3600

#define _10s            0
#define _60s            1
#define _600s           2
#define _START          3
#define MAX_NUM_BUTTONS 4

#define NOT_OPERATED    0

int required_time,dp[MAX_OPERATIONAL_TIME+1];

int input(void)
{
    int m,s;

    scanf("%02d:%02d",&m,&s);

    return  m*60+s;
}

int simulate(void)
{
    int         ret;
    queue<int>  time_q;
    const int   op_time[MAX_NUM_BUTTONS] = {10,60,600,30};

    time_q.push(0);dp[0]=1;
    time_q.push(op_time[_START]);dp[op_time[_START]]=1;

    for(;!time_q.empty();time_q.pop())
    {
        int current_time = time_q.front();
        
        if( required_time == current_time )
        {
            ret = dp[current_time];
            break;
        }

        for(int i=0;i<MAX_NUM_BUTTONS;i++)
        {
            int adj_time = current_time+op_time[i];

            if( adj_time<=MAX_OPERATIONAL_TIME 
                        && dp[adj_time]==NOT_OPERATED )
            {
                time_q.push(adj_time);
                dp[adj_time] = dp[current_time]+1;
            }
        }
    }

    return  ret;
}

int     main(void)
{
    required_time = input();
    cout<<simulate()<<'\n';

    return  0;
}