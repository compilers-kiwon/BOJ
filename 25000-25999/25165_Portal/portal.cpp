#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)
#define NEXT_DIR(d) (((d)+1)%2)

static int  N,M,A,D,S_row,S_col;
static int  grid[MAX_SIZE][MAX_SIZE];

#define TRUE    1
#define FALSE   0

#define MONSTER 1

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define reach_portal(current_row,current_col,portal_row,portal_col) \
            ((current_row)==(portal_row)&&(current_col)==(portal_col))

int simulate(void)
{
    const int offset[2] = {-1,1};

    for(int row=1,col=A,dir=D;!reach_portal(row,col,N,M);)
    {
        if( grid[row][col] == MONSTER )
        {
            return  FALSE;
        }

        int prev_col = col;

        col += offset[dir];

        if( !IN_RANGE(1,col,M) )
        {
            row++;
            col = prev_col;
            dir = NEXT_DIR(dir);
        }
    }

    return  TRUE;
}

int input(void)
{
    cin>>N>>M>>A>>D>>S_row>>S_col;
    grid[S_row][S_col] = MONSTER;

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<((simulate()==TRUE)?"YES!":"NO...")<<'\n';

    return  0;
}