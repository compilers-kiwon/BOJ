#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000000+1)

#define NONE    0
#define RED     1
#define BLUE    2

int         n,m,visited[MAX_SIZE];
vector<int> disjoint[MAX_SIZE];

void    input(void)
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b;

        cin>>a>>b;

        disjoint[a].push_back(b);
        disjoint[b].push_back(a);
    }
}

bool    is_dividable(int s)
{
    queue<int>  q;

    q.push(s);
    visited[s] = RED;

    for(;!q.empty();q.pop())
    {
        int current = q.front();
        int adj_color = ((visited[current]==RED)?BLUE:RED);

        vector<int>&    the_others = disjoint[current];

        for(int i=0;i<the_others.size();i++)
        {
            int&    a = the_others[i];

            if( visited[a] == NONE )
            {
                visited[a] = adj_color;
                q.push(a);
            }
            else
            {
                if( visited[a] != adj_color )
                {
                    return  false;
                }
            }
        }
    }

    return  true;
}

bool    divide_team(void)
{
    for(int i=1;i<=n;i++)
    {
        if( visited[i]==NONE && is_dividable(i)==false )
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

    if( divide_team() == true )
    {
        cout<<"POSSIBLE\n";
    }
    else
    {
        cout<<"IMPOSSIBLE\n";
    }

    return  0;
}