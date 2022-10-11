#include    <iostream>
#include    <vector>
#include    <queue>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (100+2)
#define INF         10000000.0f

#define CANNON_DIST 50.0f
#define CANNON_TIME 2.0f
#define WALK_SPEED  5.0f

#define START   0
#define END     1

typedef pair<double,double> Pos;    // first:X,second:Y
typedef pair<int,double>    Path;   // first:adj_pos,second:time
typedef pair<double,int>    State;  // first:-total_time,second:current_pos

vector<Pos>     pos;
vector<Path>    connected[MAX_SIZE];
double          dp[MAX_SIZE];

double  get_distance(const Pos& p1,const Pos& p2)
{
    double  d1 = p1.first-p2.first;
    double  d2 = p1.second-p2.second;

    return  sqrt(d1*d1+d2*d2);
}

void    input(void)
{
    int     n;
    double  X,Y;

    cin>>X>>Y;
    pos.push_back(make_pair(X,Y));

    cin>>X>>Y;
    pos.push_back(make_pair(X,Y));

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>X>>Y;
        pos.push_back(make_pair(X,Y));
    }

    fill(&dp[0],&dp[n+2],INF);
}

void    get_connected(void)
{
    for(int i=0;i<pos.size();i++)
    {
        for(int j=i+1;j<pos.size();j++)
        {
            double  dist,time;
            
            dist = get_distance(pos[i],pos[j]);
            
            if( i == START )
            {
                time = dist/WALK_SPEED;
            }
            else
            {
                time = CANNON_TIME+abs(dist-CANNON_DIST)/WALK_SPEED;
            }

            connected[i].push_back(make_pair(j,time));
            connected[j].push_back(make_pair(i,time));
        }
    }
}

double  find_shortest_path(void)
{
    double  ret;
    priority_queue<State>   pq;

    dp[START] = 0.0f;
    pq.push(make_pair(0.0f,START));

    for(;!pq.empty();)
    {
        double  current_time = -pq.top().first;
        int     current_pos = pq.top().second;

        pq.pop();

        if( current_pos == END )
        {
            ret = current_time;
            break;
        }

        vector<Path>&   adj = connected[current_pos];

        for(int i=0;i<adj.size();i++)
        {
            int     adj_pos = adj[i].first;
            double  adj_time = current_time+adj[i].second;

            if( adj_time < dp[adj_pos] )
            {
                dp[adj_pos] = adj_time;
                pq.push(make_pair(-adj_time,adj_pos));
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

    cout.precision(10);
    cout<<find_shortest_path()<<'\n';

    return  0;
}