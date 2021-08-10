#include    <iostream>

using namespace std;

#define MAX_SIZE    (2000+1)
#define INF         0x7FFFFFFFFFFFFFFF

typedef long long int       int64;
typedef pair<int64,int64>   Pos;

int N;
Pos c[MAX_SIZE];

#define get_distance(a,b)   ((c[(a)].first-c[(b)].first)*(c[(a)].first-c[(b)].first)+ \
                                (c[(a)].second-c[(b)].second)*(c[(a)].second-c[(b)].second))
void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>c[i].first>>c[i].second;
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    int     c1,c2;
    int64   min_distance = INF;

    for(int i=1;i<N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            int64   n;

            if( (n=get_distance(i,j)) < min_distance )
            {
                min_distance = n;
                c1=i;c2=j;
            }
        }
    }

    cout<<c1<<' '<<c2<<'\n';

    return  0;
}