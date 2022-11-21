#include    <iostream>
#include    <vector>
#include    <queue>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (3000+1)
#define MAX_DIR     4
#define NOT_VISITED -1

typedef pair<int,int>   Pos;
typedef pair<int,int>   Traffic;

int             N,M,K,visited[MAX_SIZE][MAX_SIZE];
bool            traffic_map[MAX_SIZE][MAX_SIZE];
vector<Traffic> t[MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void    get_traffic_line(int row,int col,int len)
{
    int up = row;
    int down = row;
    int left = max(col-len,1);
    int right = min(col+len,M);

    t[row].push_back(make_pair(left,right));
    
    for(int d=1;d<=len;d++)
    {
        up--;down++;left++;right--;

        if( up<1 && down>M )
        {
            break;
        }
        
        if( up >= 1 )
        {
            t[up].push_back(make_pair(left,right));
        }

        if( down <= N )
        {
            t[down].push_back(make_pair(left,right));
        }
    }
}

void    input(void)
{
    cin>>N>>M>>K;

    for(int i=1;i<=K;i++)
    {
        int R,C,D;

        cin>>R>>C>>D;
        get_traffic_line(R,C,D);
    }
}

void    merge_traffic_line(int row)
{
    vector<Traffic>&    tr = t[row];
    vector<Traffic>     current;

    current.push_back(make_pair(0,0));

    for(int i=0;i<tr.size();i++)
    {
        int&    left = tr[i].first;
        int&    right = tr[i].second;

        if( IN_RANGE(current.back().first,left,current.back().second) )
        {
            current.back().second = max(current.back().second,right);
        }
        else
        {
            current.push_back(tr[i]);
        }
    }

    for(int i=1;i<current.size();i++)
    {
        for(int col=current[i].first;col<=current[i].second;col++)
        {
            traffic_map[row][col] = true;
        }
    }
}

void    build_traffic_map(void)
{
    for(int row=1;row<=N;row++)
    {
        if( t[row].empty() )
        {
            continue;
        }

        sort(t[row].begin(),t[row].end());
        merge_traffic_line(row);
    }
}

void    init_visited(void)
{
    for(int row=1;row<=N;row++)
    {
        fill(&visited[row][1],&visited[row][M+1],NOT_VISITED);
    }
}

int     bfs(void)
{
    int         ret = NOT_VISITED;
    queue<Pos>  q;

    init_visited();

    for(q.push(make_pair(1,1)),visited[1][1]=0;!q.empty();q.pop())
    {
        int current_row = q.front().first;
        int current_col = q.front().second;

        if( current_row==N && current_col==M )
        {
            ret = visited[current_row][current_col];
            break;
        }

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) ||
                    traffic_map[adj_row][adj_col]==true || visited[adj_row][adj_col]!=NOT_VISITED )
            {
                continue;
            }

            q.push(make_pair(adj_row,adj_col));
            visited[adj_row][adj_col] = visited[current_row][current_col]+1;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    build_traffic_map();

    int dist = bfs();

    if( dist == NOT_VISITED )
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n"<<dist<<'\n';
    }

    return  0;
}