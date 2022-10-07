#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (200+1)

int         N,M,path[MAX_SIZE][MAX_SIZE];
bool        visited[MAX_SIZE];
vector<int> plan_to_visit,connected[MAX_SIZE];

void    input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>path[row][col];
        }
    }

    for(int i=1;i<=M;i++)
    {
        int city;

        cin>>city;
        plan_to_visit.push_back(city);
    }
}

void    get_connected(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=row+1;col<=N;col++)
        {
            if( path[row][col] == 1 )
            {
                connected[row].push_back(col);
                connected[col].push_back(row);
            }
        }
    }
}

void    bfs(int s)
{
    queue<int>  q;

    for(q.push(s),visited[s]=true;!q.empty();q.pop())
    {
        int current_city = q.front();
        vector<int>&    adj = connected[current_city];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_city = adj[i];

            if( visited[adj_city] == false )
            {
                q.push(adj_city);
                visited[adj_city] = true;
            }
        }
    }
}

bool    check_if_visitable(void)
{
    for(int i=0;i<plan_to_visit.size();i++)
    {
        if( visited[plan_to_visit[i]] == false )
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

    bfs(plan_to_visit.front());
    cout<<(check_if_visitable()?"YES":"NO")<<'\n';

    return  0;
}