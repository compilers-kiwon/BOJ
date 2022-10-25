#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)
#define START       1

int     N,M,S;
bool    visited[MAX_SIZE],fan[MAX_SIZE];
vector<int> connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int u,v;

        cin>>u>>v;
        connected[u].push_back(v);
    }

    cin>>S;

    for(int i=1;i<=S;i++)
    {
        int s;

        cin>>s;
        fan[s] = true;
    }
}

bool    tour_without_fan(void)
{   
    if( fan[START] == true )
    {
        return  false;
    }

    queue<int>  q;

    for(q.push(START),visited[START]=true;!q.empty();q.pop())
    {
        int current = q.front();

        if( connected[current].empty() == true )
        {
            return  true;
        }

        for(int i=0;i<connected[current].size();i++)
        {
            int&    adj = connected[current][i];

            if( visited[adj]==true || fan[adj]==true )
            {
                continue;
            }

            q.push(adj);visited[adj]=true;
        }
    }

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<(tour_without_fan()?"yes":"Yes")<<'\n';

    return  0;
}