#include    <iostream>
#include    <vector>
#include    <string>
#include    <map>

using namespace std;

#define MAX_SIZE    (10+1)

typedef pair<int,int>   Pos;    // first:row,second:col

int             N,M,K;
char            grid[MAX_SIZE][MAX_SIZE+1];
vector<Pos>     adj[MAX_SIZE][MAX_SIZE][26],start[26];
vector<string>  words;
map<string,int> counts;

#define GET_IDX(c)  ((int)((c)-'a'))

Pos get_adj_pos(int row,int col,int row_offset,int col_offset)
{
    int adj_row = row+row_offset;
    int adj_col = col+col_offset;

    adj_row = (adj_row==N+1)?1:(adj_row==0)?N:adj_row;
    adj_col = (adj_col==M+1)?1:(adj_col==0)?M:adj_col;

    return  make_pair(adj_row,adj_col);
}

void    input(void)
{
    cin>>N>>M>>K;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=M;col++)
        {
            start[GET_IDX(grid[row][col])].push_back(make_pair(row,col));
        }
    }

    for(int i=1;i<=K;i++)
    {
        string  w;

        cin>>w;
        words.push_back(w);
    }
}

void    get_adj_chrs(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=M;col++)
        {
            char&   c = grid[row][col];

            for(int d_row=-1;d_row<=1;d_row++)
            {
                for(int d_col=-1;d_col<=1;d_col++)
                {
                    Pos p = get_adj_pos(row,col,d_row,d_col);

                    if( row==p.first && col==p.second )
                    {
                        continue;
                    }

                    adj[row][col][GET_IDX(grid[p.first][p.second])].push_back(p);
                }
            }
        }
    }
}

int     dfs(int row,int col,string& str,int idx)
{
    if( idx == str.length() )
    {
        return  1;
    }

    int             ret = 0;
    vector<Pos>&    p = adj[row][col][GET_IDX(str[idx])];

    for(int i=0;i<p.size();i++)
    {
        ret += dfs(p[i].first,p[i].second,str,idx+1);
    }
    
    return  ret;
}

void    do_query(void)
{
    for(int i=0;i<words.size();i++)
    {
        string& s = words[i];
        map<string,int>::iterator   it;

        if( (it=counts.find(s)) != counts.end() )
        {
            cout<<it->second<<'\n';
            continue;
        }

        vector<Pos>&    p = start[GET_IDX(s.front())];

        for(int j=0;j<p.size();j++)
        {
            counts[s] += dfs(p[j].first,p[j].second,s,1);
        }

        cout<<counts[s]<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_adj_chrs();
    do_query();

    return  0;
}