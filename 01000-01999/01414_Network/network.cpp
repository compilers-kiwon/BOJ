#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE            (50+1)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define GET_LENGTH(c)       (IN_RANGE('a',(c),'z')?(int)((c)-'a')+1:(int)((c)-'A')+27)

#define EMPTY   '0'

typedef pair<int,pair<int,int>> Cable;  // first:-length,<first:pos1,second:pos2>

int     N,parent[MAX_SIZE];
char    grid[MAX_SIZE][MAX_SIZE];

priority_queue<Cable>   pq;

int     find_parent(int me)
{
    int&    ret = parent[me];

    if( ret != me )
    {
        ret = find_parent(ret);
    }

    return  ret;
}

int     input(void)
{
    int ret = 0;

    cin>>N;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
        parent[row] = row;

        for(int col=1;col<=N;col++)
        {
            int cable_length;

            if( grid[row][col] == EMPTY )
            {
                continue;
            }

            cable_length = GET_LENGTH(grid[row][col]);
            ret += cable_length;
            pq.push(make_pair(-cable_length,make_pair(row,col)));
        }
    }

    return  ret;
}

int     build_network(void)
{
    int ret = 0;

    for(;!pq.empty();pq.pop())
    {
        int length = -pq.top().first;
        int pos1 = pq.top().second.first;
        int pos2 = pq.top().second.second;

        int p1 = find_parent(pos1);
        int p2 = find_parent(pos2);

        if( p1 == p2 )
        {
            continue;
        }

        parent[max(p1,p2)] = min(p1,p2);
        ret += length;
    }

    return  ret;
}

bool    all_connected(void)
{
    for(int i=1;i<=N;i++)
    {
        if( find_parent(i) != 1 )
        {
            return  false;
        }
    }

    return  true;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int total_length,required_length;
    
    total_length = input();
    required_length = build_network();

    if( all_connected() == true )
    {
        cout<<total_length-required_length<<'\n';
    }
    else
    {
        cout<<-1<<'\n';
    }

    return  0;
}