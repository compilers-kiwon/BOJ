#include    <iostream>
#include    <queue>
#include    <vector>

using namespace std;

#define MAX_SIZE        (1000+1)
#define MAX_VIRUS       3
#define MAX_DIR         4
#define NOT_INFECTED    0
#define BLOCK           -1

typedef pair<int,int>   Pos;

int N,M,grid[MAX_SIZE][MAX_SIZE];
int infected_day[MAX_SIZE][MAX_SIZE];

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(queue<Pos>& q)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            cin>>grid[row][col];

            if( grid[row][col] > 0 )
            {
                q.push(make_pair(row,col));
                infected_day[row][col] = 1;
            }
        }
    }
}

void    infect(int from_row,int from_col,
                int to_row,int to_col,int day)
{
    grid[to_row][to_col] = min(MAX_VIRUS,
            grid[to_row][to_col]+grid[from_row][from_col]);
    infected_day[to_row][to_col] = day;
}

void    sort_virus(vector<Pos>& v,queue<Pos>& q)
{
    for(int i=0;i<v.size();i++)
    {
        int&    row = v[i].first;
        int&    col = v[i].second;

        if( grid[row][col] < MAX_VIRUS )
        {
            q.push(make_pair(row,col));
        }
    }
}

void    simulate(queue<Pos>& q)
{
    for(;!q.empty();)
    {
        vector<Pos> new_infected;

        for(int p=1,size=q.size();p<=size;p++,q.pop())
        {
            int current_row = q.front().first;
            int current_col = q.front().second;
            int today = infected_day[current_row][current_col]+1;

            for(int d=0;d<MAX_DIR;d++)
            {
                int adj_row = current_row+adj[d].d_row;
                int adj_col = current_col+adj[d].d_col;

                if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M)
                    || grid[adj_row][adj_col] == grid[current_row][current_col] )
                {
                    continue;
                }

                if( grid[adj_row][adj_col] == NOT_INFECTED ||
                        infected_day[adj_row][adj_col] == today  )
                {
                    infect(current_row,current_col,adj_row,adj_col,today);
                    new_infected.push_back(make_pair(adj_row,adj_col));
                }
            }
        }

        sort_virus(new_infected,q);
    }
}

void    count_virus(int* result)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            result[max(0,grid[row][col])]++;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<Pos>  q;
    int         cnt[MAX_VIRUS+1] = {0,};

    input(q);
    simulate(q);
    count_virus(cnt);

    for(int i=1;i<=MAX_VIRUS;i++)
    {
        cout<<cnt[i]<<' ';
    }

    return  0;
}