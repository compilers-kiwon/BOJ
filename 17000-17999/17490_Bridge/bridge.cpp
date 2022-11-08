#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (1000000+1)
#define NONE        0
#define INF         0x7FFFFFFFFFFFFFFF

typedef long long int   int64;
typedef pair<int,int>   Path;

int         N,M,num_of_connected;
int64       K,S[MAX_SIZE];
Path        p[MAX_SIZE];
bool        visited[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M>>K;

    for(int i=1;i<=N;i++)
    {
        cin>>S[i];
    }

    for(int i=1;i<=N;i++)
    {
        p[i] = make_pair(i-1,i+1);
    }

    p[1].first = N;
    p[N].second = 1;

    for(int i=1;i<=M;i++)
    {
        int a,b;

        cin>>a>>b;

        if( (a==1&&b==N) || (a==N&&b==1) )
        {
            p[1].first = p[N].second = NONE;
        }
        else
        {
            p[min(a,b)].second = p[max(a,b)].first = NONE;
        }
    }
}

void    dfs(int current,vector<int>& c)
{
    if( current==NONE|| visited[current]==true )
    {
        return;
    }

    c.push_back(current);
    visited[current] = true;

    dfs(p[current].first,c);
    dfs(p[current].second,c);
}

void    get_connected(void)
{
    for(int i=1;i<=N;i++)
    {
        if( visited[i] == false )
        {
            num_of_connected++;
            dfs(i,connected[num_of_connected]);
        }
    }
}

int64   get_min_num_of_required_stones(int idx)
{
    int64   ret = INF;

    for(int i=0;i<connected[idx].size();i++)
    {
        ret = min(ret,S[connected[idx][i]]);
    }

    return  ret;
}

bool    is_all_connected(void)
{
    if( num_of_connected == 1 )
    {
        return  true;
    }

    for(int i=1;i<=num_of_connected;i++)
    {
        K -= get_min_num_of_required_stones(i);

        if( K < 0 )
        {
            return  false;
        }
    }

    return  true;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_connected();

    cout<<(is_all_connected()?"YES":"NO")<<'\n';

    return  0;
}