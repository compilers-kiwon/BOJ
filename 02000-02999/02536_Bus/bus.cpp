#include    <iostream>
#include    <vector>
#include    <queue>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (5000+1)

#define VERT    0
#define HORI    1

#define IN_RANGE(n1,n,n2) (min((n1),(n2))<=(n)&&(n)<=max((n1),(n2)))

typedef pair<int,int>   State;  // first:current bus number, second:number of used buses
typedef struct{int x1,y1,x2,y2,attr;}   Bus;

int         m,n,k,sx,sy,dx,dy;
Bus         line[MAX_SIZE];
bool        is_end_pos[MAX_SIZE],visited[MAX_SIZE];
vector<int> start_pos,end_pos,connected[MAX_SIZE];

int     get_bus_attr(int idx)
{
    return  ((line[idx].x1==line[idx].x2)?VERT:HORI);
}

void    get_bus_for_pos(int x,int y,vector<int>& result)
{
    for(int i=1;i<=k;i++)
    {
        switch(line[i].attr)
        {
            case    VERT:
                if( x==line[i].x1 && IN_RANGE(line[i].y1,y,line[i].y2) )
                {
                    result.push_back(i);
                }
                break;
            case    HORI:
                if( y==line[i].y1 && IN_RANGE(line[i].x1,x,line[i].x2) )
                {
                    result.push_back(i);
                }
                break;
            default:
                // Should not be reachable
                // do nothing
                break;  
        }
    }
}

void    input(void)
{
    cin>>m>>n>>k;

    for(int i=1;i<=k;i++)
    {
        int b;

        cin>>b;
        cin>>line[b].x1>>line[b].y1>>line[b].x2>>line[b].y2;

        line[b].attr = get_bus_attr(b);
    }

    cin>>sx>>sy>>dx>>dy;

    get_bus_for_pos(sx,sy,start_pos);
    get_bus_for_pos(dx,dy,end_pos);
}

bool    is_connected(int a,int b)
{
    Bus&    c = line[a];
    Bus&    d = line[b];
    bool    ret = false;

    if( c.attr == VERT )
    {
        if( d.attr == VERT )
        {
            ret = ((c.x1==d.x1)&&(IN_RANGE(c.y1,d.y1,c.y2)||IN_RANGE(c.y1,d.y2,c.y2)));
        }
        else
        {
            ret = (IN_RANGE(c.y1,d.y1,c.y2)&&IN_RANGE(d.x1,c.x1,d.x2));
        }
    }
    else
    {
        if( d.attr == VERT )
        {
            ret = (IN_RANGE(d.y1,c.y1,d.y2)&&IN_RANGE(c.x1,d.x1,c.x2));
        }
        else
        {
            ret = ((c.y1==d.y1)&&(IN_RANGE(c.x1,d.x1,c.x2)||IN_RANGE(c.x1,d.x2,c.x2)));
        }
    }

    return  ret;
}

void    get_connected(void)
{
    for(int i=1;i<k;i++)
    {
        for(int j=i+1;j<=k;j++)
        {
            if( is_connected(i,j) == true )
            {
                connected[i].push_back(j);
                connected[j].push_back(i);
            }
        }
    }
}

int     move(void)
{
    int             ret = 0;
    queue<State>    q;
    
    for(int i=0;i<start_pos.size();i++)
    {
        visited[start_pos[i]] = true;
        q.push(make_pair(start_pos[i],1));
    }

    for(int i=0;i<end_pos.size();i++)
    {
        is_end_pos[end_pos[i]] = true;
    }

    for(;!q.empty();q.pop())
    {
        int current_bus = q.front().first;
        int num_of_used_buses = q.front().second;

        if( is_end_pos[current_bus] == true )
        {
            ret = num_of_used_buses;
            break;
        }

        vector<int>&    adj = connected[current_bus];

        for(int i=0;i<adj.size();i++)
        {
            if( visited[adj[i]] == false )
            {
                visited[adj[i]] = true;
                q.push(make_pair(adj[i],num_of_used_buses+1));
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_connected();

    cout<<move()<<'\n';

    return  0;
}