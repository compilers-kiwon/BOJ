#include    <iostream>
#include    <queue>
#include    <vector>

using namespace std;

#define EMPTY       0
#define MAX_SIZE    (200+1)

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3
#define MAX_DIR 4

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef pair<int,int>   Pos;    // first:row,second:col
typedef pair<int,Pos>   Virus;  // first:-virus,second:Pos

int N,K,S,X,Y;
int grid[MAX_SIZE][MAX_SIZE];

priority_queue<Virus>  pq;

#define build_virus_info(num,row,col)   make_pair((num),make_pair((row),(col)))

void    input(void)
{
    Virus   v;

    cin>>N>>K;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            int& n = grid[row][col];

            cin>>n;

            if( n != EMPTY )
            {
                v = build_virus_info(-n,row,col);
                pq.push(v);
            }
        }
    }

    cin>>S>>X>>Y;
}

void    simulate(void)
{
    for(int s=1;s<=S;s++)
    {
        vector<Virus>   infected;

        for(;!pq.empty();pq.pop())
        {
            Virus   current = pq.top();

            for(int d=UP;d<MAX_DIR;d++)
            {
                int adj_row = current.second.first+adj[d].d_row;
                int adj_col = current.second.second+adj[d].d_col;

                if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
                {
                    continue;
                }

                if( grid[adj_row][adj_col] == EMPTY )
                {
                    grid[adj_row][adj_col] = -current.first;
                    infected.push_back(build_virus_info(current.first,adj_row,adj_col));
                }
            }
        }

        for(int i=0;i<infected.size();i++)
        {
            pq.push(infected[i]);
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    cout<<grid[X][Y]<<'\n';

    return  0;
}