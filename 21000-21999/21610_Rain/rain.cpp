#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    50
#define MAX_DIR     8

int N,M,A[MAX_SIZE][MAX_SIZE];

const struct{int d_row,d_col;}  adj[MAX_DIR+1] =
    {{},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};

typedef pair<int,int>   Pos;

#define row first
#define col second

#define IN_RANGE(MIN,n,MAX)     ((MIN)<=(n)&&(n)<(MAX))
#define IN_AREA(row,col,size)   (IN_RANGE(0,(row),(size))&&IN_RANGE(0,(col),(size)))

#define ALLIGN(VAL,SIZE)    ((VAL)%(SIZE))

void    move(vector<Pos>& c,int d,int s)
{
    for(int i=0;i<c.size();i++)
    {
        c[i].row = (c[i].row+(N+adj[d].d_row*s))%N;
        c[i].col = (c[i].col+(N+adj[d].d_col*s))%N;
    }
}

void    rain(vector<Pos>& c)
{
    for(int i=0;i<c.size();i++)
    {
        int&    row = c[i].row;
        int&    col = c[i].col;

        A[row][col]++;
    }
}

int     get_num_of_available_water(int row,int col)
{
    int ret = 0;

    for(int d_row=-1;d_row<=1;d_row+=2)
    {
        for(int d_col=-1;d_col<=1;d_col+=2)
        {
            int adj_row = row+d_row;
            int adj_col = col+d_col;
            
            if( IN_AREA(adj_row,adj_col,N) && A[adj_row][adj_col]!=0 )
            {
                ret++;
            }
        }
    }
    
    return  ret;
}

void    cast_spell(vector<Pos>& c)
{
    vector<int> inc;

    for(int i=0;i<c.size();i++)
    {
        inc.push_back(get_num_of_available_water(c[i].row,c[i].col));
    }

    for(int i=0;i<c.size();i++)
    {
        A[c[i].row][c[i].col] += inc[i];
    }
}

bool    is_new_pos(vector<Pos>& prev_pos,int row,int col)
{
    Pos p = {row,col};

    return  (find(prev_pos.begin(),prev_pos.end(),p)==prev_pos.end());
}

void    form(vector<Pos>& prev_cloud)
{
    vector<Pos> new_cloud;

    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            if( A[row][col]>=2 && is_new_pos(prev_cloud,row,col)==true )
            {
                A[row][col] -= 2;
                new_cloud.push_back({row,col});
            }
        }
    }

    prev_cloud.clear();
    prev_cloud = new_cloud;
}

void    input(void)
{
    cin>>N>>M;

    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            cin>>A[row][col];
        }
    }
}

int     get_sum(void)
{
    int ret = 0;

    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            ret += A[row][col];
        }
    }

    return  ret;
}

void    init(vector<Pos>& c)
{
    input();

    c.push_back({N-1,0});
    c.push_back({N-1,1});
    c.push_back({N-2,0});
    c.push_back({N-2,1});
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<Pos> cloud;

    init(cloud);

    for(int i=1;i<=M;i++)
    {
        int d,s;

        cin>>d>>s;

        move(cloud,d,ALLIGN(s,N));
        rain(cloud);
        
        cast_spell(cloud);
        form(cloud);
    }

    cout<<get_sum()<<'\n';

    return  0;
}