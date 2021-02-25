#include    <iostream>
#include    <queue>
#include    <vector>
#include    <cmath>

using namespace std;

#define MAX_SIZE        (4000+2)
#define MAX_DISTANCE    10000
#define INF             0x7FFFFFFF

typedef pair<int,int>   Pos;    // first:x,second:y
typedef pair<int,int>   Path;   // first:to,second:distance 
typedef pair<int,int>   State;  // first:-distance,second:village

int     N,dp[MAX_SIZE];
bool    is_prime[MAX_DISTANCE];

vector<Path> connected[MAX_SIZE];

#define square(a)               ((a)*(a))
#define get_distance(a,b,c,d)   (sqrt(square((a)-(c))+square((b)-(d))))

void    find_prime(void)
{
    fill(&is_prime[2],&is_prime[MAX_DISTANCE],true);

    for(int i=2;i<MAX_DISTANCE;i++)
    {
        if( is_prime[i] == true )
        {
            for(int j=i+i;j<MAX_DISTANCE;j+=i)
            {
                is_prime[j] = false;
            }
        }
    }
}

void    input(vector<Pos>& v)
{
    Pos X,A;

    cin>>X.first>>X.second>>A.first>>A.second>>N;
    
    v.push_back(X);
    v.push_back(A);
    
    for(int i=1;i<=N;i++)
    {
        Pos p;

        cin>>p.first>>p.second;
        v.push_back(p);
    }
}

void    build_graph(vector<Pos>& v)
{
    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            int&    x1 = v[i].first;
            int&    y1 = v[i].second;
            int&    x2 = v[j].first;
            int&    y2 = v[j].second;
            int     d = get_distance(x1,y1,x2,y2);

            if( is_prime[d] == true )
            {
                connected[i].push_back(make_pair(j,d));
                connected[j].push_back(make_pair(i,d));
            }
        }
    }
}

int     find_shortest_path(int from,int to,int num_of_villages)
{
    fill(&dp[0],&dp[num_of_villages],INF);

    priority_queue<State>   pq;

    dp[from] = 0;
    pq.push(make_pair(0,from));

    for(;!pq.empty();)
    {
        int current_distance,current_village;

        current_distance = -pq.top().first;
        current_village = pq.top().second;

        pq.pop();

        if( current_village == to )
        {
            return  current_distance;
        }

        vector<Path>&  adj = connected[current_village];

        for(int i=0;i<adj.size();i++)
        {
            int adj_village = adj[i].first;
            int adj_distance = adj[i].second;

            if( current_distance+adj_distance < dp[adj_village] )
            {
                dp[adj_village] = current_distance+adj_distance;
                pq.push(make_pair(-(current_distance+adj_distance),adj_village));
            }
        }
    }

    return  -1;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> p;

    input(p);
    find_prime();

    build_graph(p);
    cout<<find_shortest_path(0,1,p.size())<<'\n';

    return  0;
}