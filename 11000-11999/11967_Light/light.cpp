#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define MAX_DIR     4

typedef pair<int,int>   Pos;    // first:row,second:col

int         N,M;
bool        visited[MAX_SIZE][MAX_SIZE];
bool        light_on[MAX_SIZE][MAX_SIZE];
vector<Pos> switches[MAX_SIZE][MAX_SIZE];

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        Pos p1,p2;

        cin>>p1.first>>p1.second>>p2.first>>p2.second;
        switches[p1.first][p1.second].push_back(p2);
    }
}

void    push_switch(int row,int col,queue<Pos>& q)
{
    vector<Pos>&    s = switches[row][col];

    for(int i=0;i<s.size();i++)
    {
        q.push(s[i]);
    }
}

void    turn_light_on(queue<Pos>& q)
{
    for(;!q.empty();q.pop())
    {
        int&    row = q.front().first;
        int&    col = q.front().second;

        light_on[row][col] = true;
    }
}

void    simulate(void)
{
    vector<Pos> path;
    queue<Pos>  required_to_turn_switch_on;

    path.push_back(make_pair(1,1));
    visited[1][1] = light_on[1][1] = true;
    push_switch(1,1,required_to_turn_switch_on);

    for(;;)
    {
        bool    updated = false;

        turn_light_on(required_to_turn_switch_on);

        for(int i=0;i<path.size();i++)
        {
            int&    current_row = path[i].first;
            int&    current_col = path[i].second;

            for(int d=0;d<MAX_DIR;d++)
            {
                int adj_row = current_row+adj[d].d_row;
                int adj_col = current_col+adj[d].d_col;

                if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
                {
                    continue;
                }

                if( light_on[adj_row][adj_col] == true 
                        && visited[adj_row][adj_col] == false )
                {
                    updated = visited[adj_row][adj_col] = true;
                    path.push_back(make_pair(adj_row,adj_col));
                    push_switch(adj_row,adj_col,required_to_turn_switch_on);
                }
            }
        }

        if( updated == false )
        {
            break;
        }
    }
}

int     count_light_on_rooms(void)
{
    int ret = 0;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            if( light_on[row][col] == true )
            {
                ret++;
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();simulate();
    cout<<count_light_on_rooms()<<'\n';

    return  0;
}