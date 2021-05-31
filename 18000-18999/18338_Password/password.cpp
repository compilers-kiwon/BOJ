#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_SIZE    3

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3
#define MAX_DIR 4

const struct{int d_row,d_col;} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

bool        visited[MAX_SIZE+1][MAX_SIZE+1];
vector<int> pattern;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define read_dir(c)         (((c)=='U')?UP:((c)=='D')?DOWN:((c)=='L')?LEFT:RIGHT)

typedef pair<int,int>   Pos;    //first:row, second:col

void    input(void)
{
    string  str;

    cin>>str;

    for(int i=0;i<str.length();i++)
    {
        pattern.push_back(read_dir(str[i]));
    }
}

int     dfs(int current_row,int current_col,int idx)
{
    vector<Pos> v;

    if( idx == pattern.size() )
    {
        return  1;
    }

    int ret = 0;

    for(int i=1;;i++)
    {
        int adj_row = current_row+adj[pattern[idx]].d_row*i;
        int adj_col = current_col+adj[pattern[idx]].d_col*i;

        if( !IN_RANGE(1,adj_row,MAX_SIZE) || !IN_RANGE(1,adj_col,MAX_SIZE) )
        {
            break;
        } 

        if( visited[adj_row][adj_col] == true )
        {
            break;
        }

        visited[adj_row][adj_col] = true;
        v.push_back(make_pair(adj_row,adj_col));
    }

    for(int i=v.size()-1;i>=0;i--)
    {
        int&    row = v[i].first;
        int&    col = v[i].second;

        ret += dfs(row,col,idx+1);
        visited[v[i].first][v[i].second] = false;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    int cnt = 0;

    for(int row=1;row<=MAX_SIZE;row++)
    {
        for(int col=1;col<=MAX_SIZE;col++)
        {
            visited[row][col] = true;
            cnt += dfs(row,col,0);
            visited[row][col] = false;
        }
    }

    cout<<cnt<<'\n';

    return  0;
}