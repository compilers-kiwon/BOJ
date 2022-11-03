#include    <iostream>
#include    <vector>
#include    <queue>
#include    <set>

using namespace std;

#define MAX_SIZE    (1000+1)

#define EMPTY   '0'
#define BLOCK   '1'
#define START   '2'

typedef pair<int,int>       Pos;
typedef struct{int g,l,r;}  State;

int     N,M,L,R,g_map[MAX_SIZE][MAX_SIZE],num_of_groups;
char    grid[MAX_SIZE][MAX_SIZE+1];
bool    visited[MAX_SIZE*MAX_SIZE];
Pos     start;

vector<Pos> group[MAX_SIZE*MAX_SIZE];
set<int>    connected[MAX_SIZE*MAX_SIZE];

#define get_group_idx(pos)  (g_map[(pos).first][(pos).second])

void    input(void)
{
    cin>>N>>M>>L>>R;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=M;col++)
        {
            if( grid[row][col] == START )
            {
                start = make_pair(row,col);
                grid[row][col] = EMPTY;
            }
        }
    }
}

void    get_group(void)
{
    int g_idx = 1;

    for(int col=1;col<=M;col++)
    {
        for(int row=1;row<=N;row++)
        {
            if( grid[row][col] == BLOCK )
            {
                if( group[g_idx].empty() == false )
                {
                    g_idx++;num_of_groups++;
                }
                continue;
            }

            g_map[row][col] = g_idx;
            group[g_idx].push_back(make_pair(row,col));
        }

        if( group[g_idx].empty() == false )
        {
            g_idx++;num_of_groups++;
        }
    }
}

void    build_graph(void)
{
    for(int i=1;i<=num_of_groups;i++)
    {
        vector<Pos>&    mid = group[i];

        for(int j=0;j<mid.size();j++)
        {
            int row = mid[j].first;
            int col = mid[j].second;
            int left = col-1;
            int right = col+1;

            if( left>=1 && grid[row][left]!=BLOCK )
            {
                connected[i].insert(g_map[row][left]);
                connected[g_map[row][left]].insert(i);
            }

            if( right<=M && grid[row][right]!=BLOCK )
            {
                connected[i].insert(g_map[row][right]);
                connected[g_map[row][right]].insert(i);
            }
        }
    }
}

int     move(void)
{
    int             ret;
    queue<State>    q;
    State           s = {g_map[start.first][start.second],L,R};

    q.push(s);
    visited[get_group_idx(start)] = true;

    for(ret=group[get_group_idx(start)].size();!q.empty();q.pop())
    {
        int current_group = q.front().g;
        int left_step = q.front().l;
        int right_step = q.front().r;
        
        set<int>&   adj = connected[current_group];

        for(set<int>::iterator it=adj.begin();it!=adj.end();it++)
        {
            int&    current_col = group[current_group].front().second;
            int&    adj_col = group[*it].front().second;
            
            if( visited[*it] == true )
            {
                continue;
            }

            if( ((current_col>adj_col)&&(left_step<=0))
                || ((current_col<adj_col)&&(right_step<=0)) )
            {
                continue;
            }

            s.g = *it;
            s.l = left_step-((current_col>adj_col)?1:0);
            s.r = right_step-((current_col<adj_col)?1:0);

            q.push(s);
            visited[*it] = true;
            
            ret += group[*it].size();
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_group();

    build_graph();
    cout<<move()<<'\n';

    return  0;
}