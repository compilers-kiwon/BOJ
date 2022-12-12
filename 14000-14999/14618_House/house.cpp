#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (5000+1)
#define INF         0x7FFFFFFF
#define NONE        -1

#define UNKNOWN             0
#define A_TYPE              2
#define B_TYPE              1

#define get_type(t) ((t)==UNKNOWN?'U':(t)==A_TYPE?'A':'B')

typedef pair<int,int>   Path;
typedef pair<int,int>   State;

int N,M,J,K,dp[MAX_SIZE];
int type_of_house[MAX_SIZE];

vector<Path>    connected[MAX_SIZE];

void    read_type(int n,int t)
{
    for(int i=1;i<=n;i++)
    {
        int h;

        cin>>h;
        type_of_house[h] = t;
    }
}

void    input(void)
{
    cin>>N>>M>>J>>K;

    read_type(K,A_TYPE);
    read_type(K,B_TYPE);

    for(int i=1;i<=M;i++)
    {
        int X,Y,Z;

        cin>>X>>Y>>Z;

        connected[X].push_back(make_pair(Y,Z));
        connected[Y].push_back(make_pair(X,Z));
    }

    fill(&dp[1],&dp[N+1],INF);
}

void    simulate(void)
{
    priority_queue<State>   pq;

    dp[J] = 0;
    pq.push(make_pair(0,J));

    for(;!pq.empty();)
    {
        int current_dist = -pq.top().first;
        int current_house = pq.top().second;

        pq.pop();

        if( current_dist > dp[current_house] )
        {
            continue;
        }

        vector<Path>&   adj = connected[current_house];

        for(int i=0;i<adj.size();i++)
        {
            int adj_house = adj[i].first;
            int adj_dist = current_dist+adj[i].second;

            if( adj_dist < dp[adj_house] )
            {
                dp[adj_house] = adj_dist;
                pq.push(make_pair(-adj_dist,adj_house));
            }
        }
    }
}

int     find_nearest_house(char& t)
{
    priority_queue<State>   pq;

    for(int i=1;i<=N;i++)
    {
        if( type_of_house[i]==UNKNOWN || dp[i]==INF )
        {
            continue;
        }

        pq.push(make_pair(-dp[i],type_of_house[i]));
    }

    if( pq.empty() )
    {
        return  NONE;
    }

    t = get_type(pq.top().second);
    return  -pq.top().first;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     min_dist;
    char    house_type;

    input();
    simulate();

    if( (min_dist=find_nearest_house(house_type)) != NONE )
    {
        cout<<house_type<<'\n'<<min_dist<<'\n';
    }
    else
    {
        cout<<"-1\n";
    }

    return  0;
}