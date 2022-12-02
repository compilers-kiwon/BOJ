#include    <iostream>
#include    <vector>
#include    <queue>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (1000+1)
#define MAX_DIST    10000000000.0f

typedef pair<int,int>       Pos;    // fist:x,second:y
typedef pair<int,double>    Wire;   // first:adj_plant,second:distance
typedef pair<double,int>    State;  // first:-total_used_wire,second:plant
typedef long long int       int64;

int     N,W;
Pos     p[MAX_SIZE];
bool    exist[MAX_SIZE][MAX_SIZE];
double  M,dp[MAX_SIZE];

vector<Wire>    connected[MAX_SIZE];

double  get_distance(int p1,int p2)
{
    int64   x1 = p[p1].first;
    int64   y1 = p[p1].second;
    int64   x2 = p[p2].first;
    int64   y2 = p[p2].second;

    int64   dx = x1-x2;
    int64   dy = y1-y2;

    return  sqrt((dx*dx)+(dy*dy));
}

void    input(void)
{
    cin>>N>>W>>M;

    for(int i=1;i<=N;i++)
    {
        cin>>p[i].first>>p[i].second;
        dp[i] = MAX_DIST;
    }

    for(int i=1;i<=W;i++)
    {
        int p1,p2;

        cin>>p1>>p2;
        exist[p1][p2] = exist[p2][p1] = true;
    }
}

void    get_connected(void)
{
    for(int i=1;i<N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if( exist[i][j] == false )
            {
                double dist = get_distance(i,j);
            
                if( dist <= M )
                {
                    connected[i].push_back(make_pair(j,dist));
                    connected[j].push_back(make_pair(i,dist));
                }
            }
            else
            {
                connected[i].push_back(make_pair(j,0.0f));
                connected[j].push_back(make_pair(i,0.0f));
            }
        }
    }
}

double  simulate(void)
{
    double  ret = -1.0;
    priority_queue<State>   pq;

    dp[1] = 0.0f;
    pq.push(make_pair(0.0f,1));

    for(;!pq.empty();)
    {
        double  current_dist = -pq.top().first;
        int     current_plant = pq.top().second;

        pq.pop();

        if( current_plant == N )
        {
            ret = current_dist;
            break;
        }

        if( current_dist > dp[current_plant] )
        {
            continue;
        }

        vector<Wire>&   adj = connected[current_plant];

        for(int i=0;i<adj.size();i++)
        {
            int     adj_plant = adj[i].first;
            double  adj_dist = current_dist+adj[i].second;

            if( adj_dist < dp[adj_plant] )
            {
                dp[adj_plant] = adj_dist;
                pq.push(make_pair(-adj_dist,adj_plant));
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_connected();

    cout<<(int64)floor(simulate()*1000.0f)<<'\n';

    return  0;
}