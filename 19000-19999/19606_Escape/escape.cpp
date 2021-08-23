#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000+1)
#define MAX_NUM     1000000

typedef pair<int,int>   Pos;    // first:row,second:col

int     M,N,x[MAX_SIZE][MAX_SIZE];
bool    visited[MAX_SIZE][MAX_SIZE];

vector<Pos> p[MAX_NUM+1];

void    input(void)
{
    cin>>M>>N;

    for(int row=1;row<=M;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>x[row][col];
            p[row*col].push_back(make_pair(row,col));
        }
    }
}

bool    simulate(void)
{
    bool        ret;
    queue<Pos>  q;

    visited[1][1] = true;
    q.push(make_pair(1,1));

    for(ret=false;!q.empty();q.pop())
    {
        int current_row = q.front().first;
        int current_col = q.front().second;

        if( current_row==M && current_col==N )
        {
            ret = true;
            break;
        }

        vector<Pos>&    adj = p[x[current_row][current_col]];

        for(int i=0;i<adj.size();i++)
        {
            int&    adj_row = adj[i].first;
            int&    adj_col = adj[i].second;

            if( visited[adj_row][adj_col] == false )
            {
                visited[adj_row][adj_col] = true;
                q.push(make_pair(adj_row,adj_col));
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    if( simulate() == false )
    {
        cout<<"no\n";
    }
    else
    {
        cout<<"yes\n";
    }

    return  0;
}