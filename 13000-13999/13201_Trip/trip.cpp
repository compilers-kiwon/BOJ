#include    <iostream>
#include    <string>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE        (100+1)
#define MAX_FLIGHT      (1000+1)
#define START_AIRPORT   "ICN"
#define NONE            0.0

typedef long double   Probability;

int         N,K,start_idx;
bool        queued[MAX_SIZE][MAX_FLIGHT];
string      airport[MAX_SIZE];
Probability grid[MAX_SIZE][MAX_SIZE],dp[MAX_SIZE][MAX_FLIGHT];

typedef pair<int,int>   State;  // first:airport, second:flight

void    input(vector<int>* connected)
{
    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        string& str = airport[i];

        cin>>str;

        if( str == START_AIRPORT )
        {
            start_idx = i;
        }

        fill(&queued[i][1],&queued[i][K+1],false);
        fill(&dp[i][1],&dp[i][K+1],NONE);
    }

    for(int row=1;row<=N;row++)
    {
        Probability sum = 0.0;

        for(int col=1;col<=N;col++)
        {
            cin>>grid[row][col];
            sum += grid[row][col];
        }

        if( sum == 0.0 )
        {
            continue;
        }

        for(int col=1;col<=N;col++)
        {
            if( grid[row][col] != NONE )
            {
                grid[row][col] /= sum;
                connected[row].push_back(col);
            }
        }
    }
}

int     simulate(vector<int>* connected)
{
    int             ret;
    queue<State>    q;
    Probability     p;

    q.push(make_pair(start_idx,0));
    queued[start_idx][0] = true;

    for(p=NONE,dp[start_idx][0]=1.0;!q.empty();)
    {
        int current_airport = q.front().first;
        int current_flight = q.front().second;

        q.pop();
        queued[current_airport][current_flight] = false;

        Probability&    current_probability = dp[current_airport][current_flight];

        if( current_flight == K )
        {
            if( current_probability > p )
            {
                p = current_probability;
                ret = current_airport;
            }

            continue;
        }

        vector<int>&    adj = connected[current_airport];

        for(int i=0;i<adj.size();i++)
        {
            int&        adj_airport = adj[i];
            Probability adj_probability;

            adj_probability = current_probability*grid[current_airport][adj_airport];

            if( adj_probability > dp[adj_airport][current_flight+1] )
            {
                dp[adj_airport][current_flight+1] = adj_probability;

                if( queued[adj_airport][current_flight+1] == false )
                {
                    queued[adj_airport][current_flight+1] = true;
                    q.push(make_pair(adj_airport,current_flight+1));
                }
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        vector<int> connected[MAX_SIZE];

        input(connected);
        cout<<airport[simulate(connected)]<<'\n';
    }

    return  0;
}