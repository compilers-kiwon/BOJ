#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_SIZE    50

#define TRUE    1
#define FALSE   0

typedef struct{int row,col,dist;}   State;

static int  N,M;
static State s[MAX_SIZE+MAX_SIZE];

#define get_distance(r1,c1,r2,c2) (abs((r1)-(r2))+abs((c1)-(c2)))

int input(void)
{
    cin>>N>>M;

    for(int row=1,col=1,i=1;i<=N+M-1;i++)
    {
        if( row < N )
        {
            s[i].row = row++;
            s[i].col = col;
            cin>>s[i].dist;
        }
        else
        {
            s[i].row = row;
            s[i].col = col++;
            cin>>s[i].dist;
        }
    }

    return  0;
}

int check_distance(int row,int col)
{
    for(int i=1;i<=N+M-1;i++)
    {
        if( get_distance(row,col,s[i].row,s[i].col) != s[i].dist )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int find_gorani_pos(int& row,int& col)
{
    for(row=1;row<=N;row++)
    {
        for(col=1;col<=M;col++)
        {
            if( check_distance(row,col) )
            {
                return  0;
            }
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int row,col;

    input();
    find_gorani_pos(row,col);

    cout<<row<<' '<<col<<'\n';

    return  0;
}