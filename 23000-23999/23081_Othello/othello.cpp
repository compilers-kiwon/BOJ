#include    <iostream>
#include    <queue>

using namespace std;

typedef pair<int,int>   Pos;    // first:-y,second:-x
typedef pair<int,Pos>   State;  // first:score,second:Pos

#define MAX_SIZE    500
#define MAX_DIR     8

const struct{int dy,dx;} adj[MAX_DIR] = {
    {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}
};

static int  N;
static char grid[MAX_SIZE][MAX_SIZE+1];

static priority_queue<State>    pq;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define IN_AREA(size,y,x)   (IN_RANGE(0,(y),(size))&&IN_RANGE(0,(x),(size)))

int get_score(int y,int x,int d)
{
    int ret = 0;

    for(int offset=1;;offset++,ret++)
    {
        int adj_y = y+adj[d].dy*offset;
        int adj_x = x+adj[d].dx*offset;

        if( !IN_AREA(N-1,adj_y,adj_x) || grid[adj_y][adj_x] == '.' )
        {
            return  0;
        }

        if( grid[adj_y][adj_x] == 'B' )
        {
            break;
        }
    }

    return  ret;
}

int simulate(void)
{
    for(int y=0;y<N;y++)
    {
        for(int x=0;x<N;x++)
        {
            if( grid[y][x] != '.' )
            {
                continue;
            }

            int sum = 0;

            for(int d=0;d<MAX_DIR;d++)
            {
                sum += get_score(y,x,d);
            }

            if( sum != 0 )
            {
                pq.push({sum,{-y,-x}});
            }
        }
    }

    return  0;
}

int input(void)
{
    cin>>N;

    for(int y=0;y<N;y++)
    {
        cin>>&grid[y][0];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    if( pq.empty() )
    {
        cout<<"PASS\n";
    }
    else
    {
        cout<<-pq.top().second.second<<' '<<
            -pq.top().second.first<<'\n'<<pq.top().first<<'\n';
    }

    return  0;
}