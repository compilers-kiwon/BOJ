#include    <iostream>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (1000+1)
#define INF         0x7FFFFFFF

typedef pair<int,int>   Pos;    // first:x,second:y

int N;
Pos p[MAX_SIZE];

#define get_distance(a,b)   (abs(p[(a)].first-p[(b)].first)+abs(p[(a)].second-p[(b)].second))

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int&    X = p[i].first;
        int&    Y = p[i].second;

        cin>>X>>Y;
    }

    sort(&p[1],&p[N+1]);
}

Pos     get_optimal_pos(void)
{
    int min_distance = INF;
    Pos ret;

    for(int i=1;i<=N;i++)
    {
        int d = 0;

        for(int j=1;j<=N;j++)
        {
            d += get_distance(i,j);
        }

        if( d < min_distance )
        {
            ret = p[i];
            min_distance = d;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Pos optimal;

    input();
    optimal = get_optimal_pos();

    cout<<optimal.first<<' '<<optimal.second<<'\n';

    return  0;
}