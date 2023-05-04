#include    <iostream>

using namespace std;

#define MAX_SIZE    (500+1)
#define NONE        0

typedef long long int   int64;
typedef pair<int,int>   Pos;

static int      N;
static int64    k[MAX_SIZE][MAX_SIZE];
static int64    sum_of_row[MAX_SIZE];
static int64    sum_of_col[MAX_SIZE];
static int64    sum_of_diag[2];

#define TRUE    1
#define FALSE   0

int input(Pos& zero)
{
    cin>>N;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>k[row][col];

            if( k[row][col] == NONE )
            {
                zero = {row,col};
            }
        }
    }

    return  0;
}

int get_sum(Pos s,Pos e,Pos offset,int64& sum)
{
    int s_row = s.first;
    int s_col = s.second;
    int e_row = e.first;
    int e_col = e.second;

    sum = 0;

    for(int row=s_row,col=s_col;
        row!=e_row&&col!=e_col;
        row+=offset.first,col+=offset.second)
    {
        sum += k[row][col];
    }

    return  0;
}

int get_sum_of_row(void)
{
    for(int row=1;row<=N;row++)
    {
        get_sum({row,1},{row+1,1+N},{0,1},sum_of_row[row]);
    }

    return  0;
}

int get_sum_of_col(void)
{
    for(int col=1;col<=N;col++)
    {
        get_sum({1,col},{1+N,col+1},{1,0},sum_of_col[col]);
    }

    return  0;
}

int get_sum_of_diag(void)
{
    get_sum({1,1},{1+N,1+N},{1,1},sum_of_diag[0]);
    get_sum({1,N},{1+N,0},{1,-1},sum_of_diag[1]);
    
    return  0;
}

int solve(Pos zero)
{
    int64   sum1,sum2;

    for(int row=1;row<=N;row++)
    {
        if( zero.first == row )
        {
            continue;
        }

        get_sum({row,1},{row+1,1+N},{0,1},sum1);
        break;
    }

    get_sum({zero.first,1},{zero.first+1,1+N},{0,1},sum2);
    k[zero.first][zero.second] = ((sum1-sum2)>0)?sum1-sum2:-1;
    
    return  0;
}

int compare_sum_table(int from,int to,
                int64 table[],int64& value)
{
    for(int i=from;i<=to;i++)
    {
        if( value == NONE )
        {
            value = table[i];
            continue;
        }

        if( value != table[i] )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int compare_sum(void)
{
    int64   sum = NONE;

    if( compare_sum_table(1,N,sum_of_row,sum)==FALSE 
        || compare_sum_table(1,N,sum_of_col,sum)==FALSE 
        || compare_sum_table(0,1,sum_of_diag,sum)==FALSE )
    {
        return  FALSE;
    }

    return  TRUE;
}

int64   find_stone(Pos zero)
{
    solve(zero);

    if( k[zero.first][zero.second] == -1 )
    {
        return  -1;
    }

    get_sum_of_row();
    get_sum_of_col();
    get_sum_of_diag();

    return  (compare_sum()?k[zero.first][zero.second]:-1);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Pos zero;

    input(zero);
    cout<<find_stone(zero)<<'\n';

    return  0;
}