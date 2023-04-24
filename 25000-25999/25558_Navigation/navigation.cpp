#include    <iostream>
#include    <vector>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (1000+1)
#define INF         0x7FFFFFFFFFFFFFFF

typedef long long int       int64;
typedef pair<int64,int64>   Pos;

static int  N;
static Pos  s,e;
static vector<Pos>  path[MAX_SIZE];

#define get_distance(p1,p2) \
    (abs((p1).first-(p2).first)+abs((p1).second-(p2).second))

int64   simulate(int idx)
{
    Pos             p = s;
    int64           ret = 0;
    vector<Pos>&    current = path[idx];

    current.push_back(e);

    for(int i=0;i<current.size();i++)
    {
        ret += get_distance(p,current[i]);
        p = current[i];
    }

    return  ret;
}

int input(void)
{
    cin>>N>>s.first>>s.second>>e.first>>e.second;

    for(int i=1;i<=N;i++)
    {
        int M;

        cin>>M;

        for(int j=1;j<=M;j++)
        {
            int64   x,y;

            cin>>x>>y;
            path[i].push_back({x,y});
        }
    }

    return  0;
}

int get_best_navigation(void)
{
    int     ret;
    int64   min_distance = INF;

    for(int i=1;i<=N;i++)
    {
        int64   dist = simulate(i);

        if( dist < min_distance )
        {
            ret = i;
            min_distance = dist;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_best_navigation()<<'\n';

    return  0;
}