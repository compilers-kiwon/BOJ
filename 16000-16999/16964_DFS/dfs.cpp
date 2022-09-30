#include    <iostream>
#include    <stack>
#include    <set>

using namespace std;

#define MAX_SIZE    (100000+1)

int         N,visited[MAX_SIZE];
set<int>    connected[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<N;i++)
    {
        int u,v;

        cin>>u>>v;

        connected[u].insert(v);
        connected[v].insert(u);
    }

    for(int i=1;i<=N;i++)
    {
        cin>>visited[i];
    }
}

int     simulate(void)
{
    if( visited[1] != 1 )
    {
        return  0;
    }

    stack<int>  st;

    st.push(1);

    for(int i=2;i<=N;i++)
    {
        set<int>::iterator  it = connected[st.top()].find(visited[i]);

        if( it == connected[st.top()].end() )
        {
            return  0;
        }

        connected[*it].erase(st.top());
        connected[st.top()].erase(it);

        for(st.push(visited[i]);!st.empty();st.pop())
        {
            if( !connected[st.top()].empty() )
            {
                break;
            }
        }
    }

    return  ((st.empty())?1:0);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}