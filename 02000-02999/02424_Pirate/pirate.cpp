#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (700+1)
#define MAX_DIR     4

typedef pair<int,int>   Pos;    // first:row,second:col

static int  N,M;
static char grid[MAX_SIZE][MAX_SIZE+1];
static Pos  V,Y,T;

#define TRUE    1
#define FALSE   0

const struct {int d_row,d_col;}
    adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define LAND        'I'
#define PIRATE      'V'
#define PLAYER      'Y'
#define TREASURE    'T'
#define EMPTY       '.'

#define _is_(n,r,c)         (grid[(r)][(c)]==(n))
#define is_land(row,col)    _is_(LAND,(row),(col))
#define is_empty(row,col)   _is_(EMPTY,(row),(col))
#define is_pirate(row,col)  _is_(PIRATE,(row),(col))
#define is_treasure(r,c)    _is_(TREASURE,(r),(c))

#define seen_by(n,row,col)  (grid[(row)][(col)]==(n))

#define move(n,row,col,q) \
        {(q).push({(row),(col)});grid[(row)][(col)]=(n);}

#define IN_AREA(row_size,col_size,row,col) \
        (IN_RANGE(1,(row),(row_size))&&IN_RANGE(1,(col),(col_size)))

#define is_safe(row_size,col_size,row,col) \
        (!IN_AREA((row_size),(col_size),(row),(col))||is_land((row),(col)))

#define player_can_visit(row,col) \
        (is_empty((row),(col))||is_treasure((row),(col)))

int input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=M;col++)
        {
            char&   c = grid[row][col];

            switch(c)
            {
                case PIRATE:V={row,col};break;
                case PLAYER:Y={row,col};break;
                case TREASURE:T={row,col};break;
                default:/*do nothing*/;break;
            }
        }
    }

    return  0;
}

int move_pirate(queue<Pos>& q)
{
    for(int i=1,size=q.size();i<=size;i++,q.pop())
    {
        if( q.front() == T )
        {
            return  TRUE;
        }

        int current_row = q.front().first;
        int current_col = q.front().second;

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_AREA(N,M,adj_row,adj_col) ) 
            {
                continue;
            }

            if( is_land(adj_row,adj_col)
                    || is_pirate(adj_row,adj_col) )
            {
                continue;
            }

            move(PIRATE,adj_row,adj_col,q);
        }
    }

    return  FALSE;
}

int out_of_pirate_view(int row,int col)
{
    for(int d=0;d<MAX_DIR;d++)
    {
        for(int offset=1;;offset++)
        {
            int adj_row = row+adj[d].d_row*offset;
            int adj_col = col+adj[d].d_col*offset;

            if( is_safe(N,M,adj_row,adj_col) )
            {
                break;
            }

            if( seen_by(PIRATE,adj_row,adj_col) )
            {
                return  FALSE;
            }
        }
    }

    return  TRUE;
}

int move_player(queue<Pos>& q)
{
    for(int i=1,size=q.size();i<=size;i++,q.pop())
    {
        if( q.front() == T )
        {
            return  TRUE;
        }

        int current_row = q.front().first;
        int current_col = q.front().second;

        for(int d=0;d<MAX_DIR;d++)
        {
            int adj_row = current_row+adj[d].d_row;
            int adj_col = current_col+adj[d].d_col;

            if( !IN_AREA(N,M,adj_row,adj_col) )
            {
                continue;
            }

            if( !player_can_visit(adj_row,adj_col) )
            {
                continue;
            }

            if( out_of_pirate_view(adj_row,adj_col) == TRUE )
            {
                move(PLAYER,adj_row,adj_col,q);
            }
        }
    }

    return  FALSE;
}

int simulate(void)
{
    queue<Pos>  yq,vq;

    yq.push(Y);vq.push(V);

    for(;!yq.empty();)
    {
        if( move_pirate(vq) == TRUE )
        {
            return  FALSE;
        }

        if( move_player(yq) == TRUE )
        {
            return  TRUE;
        }
    }

    return  FALSE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<(simulate()?"YES":"NO")<<'\n';

    return  0;
}