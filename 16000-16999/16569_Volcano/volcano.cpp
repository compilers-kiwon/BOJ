#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define MAX_TIME    (200+1)
#define MAX_DIR     4

typedef pair<int,int>   Pos;    // first:row,second:col

int         M,N,V,X,Y,h[MAX_SIZE][MAX_SIZE];
bool        corrupted[MAX_SIZE][MAX_SIZE];
bool        visited[MAX_SIZE][MAX_SIZE];
vector<Pos> volcano[MAX_TIME];

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>M>>N>>V>>X>>Y;

    for(int row=1;row<=M;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>h[row][col];
        }
    }

    for(int i=1;i<=V;i++)
    {
        int x,y,t;

        cin>>x>>y>>t;

        visited[x][y] = true;
        volcano[t].push_back(make_pair(x,y));
    }
}

void    check_eruption_of_volcano(int time,queue<Pos>& q)
{
    if( time >= MAX_TIME )
    {
        return;
    }

    for(int i=0;i<volcano[time].size();i++)
    {
        q.push(volcano[time][i]);
    }
}

Pos     get_adj_pos(int row,int col,int dir)
{
    int r = row+adj[dir].d_row;
    int c = col+adj[dir].d_col;

    return  make_pair(r,c);
}

void    add_new_pos(int row,int col,
                        queue<Pos>& q,
                        bool m[][MAX_SIZE])
{
    m[row][col] = true;
    q.push(make_pair(row,col));
}

int     simulate(int& time_to_visit)
{
    int         ret = -1;
    queue<Pos>  pq,vq;

    add_new_pos(X,Y,pq,visited);

    for(int t=0;!pq.empty();t++)
    {
        // 1. volcano
        check_eruption_of_volcano(t,vq);

        for(int i=1,size=vq.size();i<=size;i++,vq.pop())
        {
            int current_row = vq.front().first;
            int current_col = vq.front().second;

            for(int d=0;d<MAX_DIR;d++)
            {
                Pos     adj_pos = get_adj_pos(current_row,current_col,d);
                int&    adj_row = adj_pos.first;
                int&    adj_col = adj_pos.second;

                if( !IN_RANGE(1,adj_row,M) || !IN_RANGE(1,adj_col,N) )
                {
                    continue;
                }

                if( corrupted[adj_row][adj_col] == true )
                {
                    continue;
                }

                add_new_pos(adj_row,adj_col,vq,corrupted);
            }
        }

        // 2. person
        for(int i=1,size=pq.size();i<=size;i++,pq.pop())
        {
            int current_row = pq.front().first;
            int current_col = pq.front().second;

            if( h[current_row][current_col] > ret )
            {
                time_to_visit = t;
                ret = h[current_row][current_col];
            }

            for(int d=0;d<MAX_DIR;d++)
            {
                Pos     adj_pos = get_adj_pos(current_row,current_col,d);
                int&    adj_row = adj_pos.first;
                int&    adj_col = adj_pos.second;

                if( !IN_RANGE(1,adj_row,M) || !IN_RANGE(1,adj_col,N) )
                {
                    continue;
                }

                if( corrupted[adj_row][adj_col] == true ||
                            visited[adj_row][adj_col] == true )
                {
                    continue;
                }

                add_new_pos(adj_row,adj_col,pq,visited);
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_height,time;

    input();
    max_height = simulate(time);

    cout<<max_height<<' '<<time<<'\n';

    return  0;
}