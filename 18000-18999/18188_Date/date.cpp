#include    <iostream>
#include    <queue>
#include    <string>

using namespace std;

#define MAX_SIZE    (20+1)
#define MAX_DIR     4

typedef pair<int,int>       Pos;
typedef pair<string,Pos>    State;

int     H,W,N,start_row,start_col;
char    grid[MAX_SIZE][MAX_SIZE+1];
char    available[MAX_SIZE][2];

const struct{int d_row,d_col;}  adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    get_adj_pos(char dir,int row,int col,
                        int& adj_row,int& adj_col)
{
    const char  all_dir[MAX_DIR] = {'W','S','A','D'};

    for(int i=0;i<MAX_DIR;i++)
    {
        if( all_dir[i] == dir )
        {
            adj_row = row+adj[i].d_row;
            adj_col = col+adj[i].d_col;
            break;
        }
    }
}

void    input(void)
{
    cin>>H>>W;

    for(int row=1;row<=H;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=W;col++)
        {
            if( grid[row][col] == 'D' )
            {
                start_row = row;
                start_col = col;
            }
        }
    }

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>available[i][0]>>available[i][1];
    }
}

bool    simulate(string& path)
{
    queue<State>  q;

    q.push(make_pair("",make_pair(start_row,start_col)));

    for(int step=1;step<=N&&!q.empty();step++)
    {
        for(int i=1,size=q.size();i<=size;i++,q.pop())
        {
            string  current_path = q.front().first;
            int     current_row = q.front().second.first;
            int     current_col = q.front().second.second;

            for(int j=0;j<2;j++)
            {
                int adj_row,adj_col;

                get_adj_pos(available[step][j],current_row,
                                    current_col,adj_row,adj_col);
                
                if( !IN_RANGE(1,adj_row,H) || !IN_RANGE(1,adj_col,W) )
                {
                    continue;
                }
                
                if( grid[adj_row][adj_col] == '@' )
                {
                    continue;
                }

                path = current_path;
                path.push_back(available[step][j]);
                
                if( grid[adj_row][adj_col] == 'Z' )
                {
                    return  true;
                }

                q.push(make_pair(path,make_pair(adj_row,adj_col)));
            }
        } 
    }

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  path;

    input();
    
    if( simulate(path) == true )
    {
        cout<<"YES\n"<<path<<'\n';
    }
    else
    {
        cout<<"NO\n";
    }

    return  0;
}