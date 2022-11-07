#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (200+1)
#define NONE        0
#define INF         0x7FFFFFFF

int N,M,K,dist[MAX_SIZE][MAX_SIZE],C[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int A,B,T;

        cin>>A>>B>>T;
        dist[A][B] = T;
    }

    cin>>K;

    for(int i=1;i<=K;i++)
    {
        cin>>C[i];
    }
}

void    get_distance(void)
{
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if( i==j || dist[i][k]==NONE || dist[k][j]==NONE )
                {
                    continue;
                }

                if( dist[i][j]==NONE || dist[i][j]>dist[i][k]+dist[k][j] )
                {
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

int     get_max_distance(int mid)
{
    int ret = 0;

    for(int i=1;i<=K;i++)
    {
        if( C[i]!=mid && dist[C[i]][mid]==NONE && dist[mid][C[i]]==NONE )
        {
            ret = INF;
            break;
        }

        ret = max(ret,dist[C[i]][mid]+dist[mid][C[i]]);
    }

    return  ret;
}

vector<int> get_min_pos(void)
{
    int         min_distance = INF;
    vector<int> ret;

    for(int i=1;i<=N;i++)
    {
        int d = get_max_distance(i);

        if( d <= min_distance )
        {
            if( d < min_distance )
            {
                ret.clear();
            }

            min_distance = d;
            ret.push_back(i);
        }       
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_distance();

    vector<int> pos = get_min_pos();

    for(int i=0;i<pos.size();i++)
    {
        cout<<pos[i]<<' ';
    }

    return  0;
}