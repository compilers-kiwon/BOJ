#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (50+1)
#define MAX_DIR     4
#define MAX_NODES   (250+1)
#define INF         0x7FFFFFFF

#define START       'S'
#define KEY         'K'
#define WALL        '1'
#define EMPTY       '0'

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef pair<int,int>   Pos;    // first:row,second:col
typedef pair<int,int>   Nodes;  // first:node 1 of an edge,second:node 2 of an edge
typedef pair<int,Nodes> Path;   // first:-a length of an edge,second:Nodes

int                     N,M,parent[MAX_NODES],nodes_map[MAX_SIZE][MAX_SIZE];
char                    grid[MAX_SIZE][MAX_SIZE+1];
vector<Pos>             nodes;
priority_queue<Path>    connected;

#define get_idx(r,c)    nodes_map[(r)][(c)]
#define build_edge(d,r1,c1,r2,c2)   \
                        make_pair(-(d),make_pair(get_idx((r1),(c1)),get_idx((r2),(c2))))

int     find_parent(int n)
{
    int&    ret = parent[n];

    if( ret != n )
    {
        ret = find_parent(ret);
    }

    return  ret;
}

void    input(void)
{
    int cnt = 0;

    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=N;col++)
        {
            if( grid[row][col]==START || grid[row][col]==KEY )
            {
                parent[cnt] = cnt;
                nodes_map[row][col] = cnt++;
                nodes.push_back(make_pair(row,col));
            }
        }
    }
}

void    bfs(Pos s)
{
    int visited[MAX_SIZE][MAX_SIZE];

    for(int row=1;row<=N;row++)
    {
        fill(&visited[row][1],&visited[row][N+1],INF);
    }

    queue<Pos>  q;

    for(q.push(s),visited[s.first][s.second]=0;!q.empty();q.pop())
    {
        int current_row = q.front().first;
        int current_col = q.front().second;
        int current_dist = visited[current_row][current_col];

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( grid[adj_row][adj_col] == WALL)
            {
                continue;
            }

            if( visited[adj_row][adj_col] <= current_dist+1 )
            {
                continue;
            }

            q.push(make_pair(adj_row,adj_col));
            visited[adj_row][adj_col] = current_dist+1;

            if( grid[adj_row][adj_col]==START || grid[adj_row][adj_col]==KEY )
            {
                connected.push(build_edge(current_dist+1,s.first,s.second,adj_row,adj_col));
            }
        }
    }
}

void    get_connected(void)
{
    for(int i=0;i<nodes.size();i++)
    {
        bfs(nodes[i]);
    }
}

int     simulate(void)
{
    int ret = 0;

    for(;!connected.empty();connected.pop())
    {
        int dist = -connected.top().first;
        int n1 = connected.top().second.first;
        int n2 = connected.top().second.second;
        int p1 = find_parent(n1);
        int p2 = find_parent(n2);

        if( p1 == p2 )
        {
            continue;
        }

        parent[max(p1,p2)] = min(p1,p2);
        ret += dist;
    }

    for(int i=0;i<=M;i++)
    {
        if( find_parent(i) != 0 )
        {
            ret = -1;
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_connected();
    cout<<simulate()<<'\n';

    return  0;
}