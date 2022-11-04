#include    <iostream>
#include    <vector>
#include    <queue>
#include    <map>

using namespace std;

#define MAX_SIZE    12

vector<int> connected[MAX_SIZE+1];

bool    is_spica(map<int,int>& d)
{
    return  (d[0]==1&&d[1]==3&&d[2]==3
                &&d[3]==3&&d[4]==1&&d[5]==1);
}

void    input(void)
{
    for(int i=1;i<=MAX_SIZE;i++)
    {
        int x,y;

        cin>>x>>y;

        connected[x].push_back(y);
        connected[y].push_back(x);
    }
}

void    get_distance_table(map<int,int>& d,int from)
{
    int         visited[MAX_SIZE+1];
    queue<int>  q;

    fill(&visited[1],&visited[MAX_SIZE+1],MAX_SIZE);
    q.push(from);visited[from]=0;d[0]=1;

    for(;!q.empty();q.pop())
    {
        int current = q.front();

        for(int i=0;i<connected[current].size();i++)
        {
            int adj = connected[current][i];

            if( visited[current]+1 < visited[adj] )
            {
                q.push(adj);
                visited[adj] = visited[current]+1;
                d[visited[adj]]++;
            }
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=1;i<=MAX_SIZE;i++)
    {
        map<int,int>    dist_table;

        get_distance_table(dist_table,i);

        if( is_spica(dist_table) == true )
        {
            cout<<i<<'\n';
            break;
        }
    }

    return  0;
}