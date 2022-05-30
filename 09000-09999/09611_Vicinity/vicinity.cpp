#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)
#define MAX_QUERY   (50+1)

typedef long long int       int64;
typedef pair<int64,int64>   Pos;
typedef pair<int,int64>     Query;

#define get_distance(x1,y1,x2,y2)   (((x1)-(x2))*((x1)-(x2))+((y1)-(y2))*((y1)-(y2)))

void    input(int& num_of_points,Pos p[],
                int& num_of_queries,Query q[])
{
    cin>>num_of_points;

    for(int i=1;i<=num_of_points;i++)
    {
        cin>>p[i].first>>p[i].second;
    }

    cin>>num_of_queries;

    for(int i=1;i<=num_of_queries;i++)
    {
        cin>>q[i].first>>q[i].second;
    }
}

int     check_vicinity(int num_of_points,Pos p[],Query q)
{
    int     cnt = 0;
    int64   x = p[q.first].first;
    int64   y = p[q.first].second;

    for(int i=1;i<=num_of_points;i++)
    {
        if( get_distance(x,y,p[i].first,p[i].second) <= q.second*q.second )
        {
            cnt++;
        }
    }

    return  cnt-1;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n,t;
    Pos     p[MAX_SIZE];
    Query   q[MAX_QUERY];

    input(n,p,t,q);

    for(int i=1;i<=t;i++)
    {
        cout<<check_vicinity(n,p,q[i])<<'\n';
    }

    return  0;
}