#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE            (5+1)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define chr2int(c)          ((int)((c)-'0'))

#define MAX_DIR 2
#define MAX_NUM 1000000000

int     N;
char    grid[MAX_SIZE][MAX_SIZE];

const struct{int d_row,d_col;} adj[2] = {{0,1},{1,0}};

int     calculate(string& exp)
{
    int ret = chr2int(exp[0]);

    for(int i=2;i<exp.length();i+=2)
    {
        int n = chr2int(exp[i]);

        switch(exp[i-1])
        {
            case    '*':
                ret *= n;
                break;
            case    '+':
                ret += n;
                break;
            case    '-':
                ret -= n;
                break;
            default:
                // do nothing
                break;
        }
    }

    return  ret;
}

void    dfs(int row,int col,string exp,
            int& max_value,int& min_value)
{
    exp.push_back(grid[row][col]);

    if( row==N && col==N )
    {
        int n = calculate(exp);
        
        max_value = max(max_value,n);
        min_value = min(min_value,n);

        return;
    }

    for(int d=0;d<MAX_DIR;d++)
    {
        int adj_row = row+adj[d].d_row;
        int adj_col = col+adj[d].d_col;

        if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) )
        {
            continue;
        }

        dfs(adj_row,adj_col,exp,max_value,min_value);
    }
}

void    input(void)
{
    cin>>N;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>grid[row][col];
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    int max_value = -MAX_NUM;
    int min_value = MAX_NUM;

    dfs(1,1,"",max_value,min_value);
    cout<<max_value<<' '<<min_value<<'\n';

    return  0;
}