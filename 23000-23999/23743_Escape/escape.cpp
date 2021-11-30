#include    <iostream>
#include    <queue>
#include    <vector>

using namespace std;

#define MAX_SIZE        (200000+1)
#define MAX_WARP_GATE   (100000+1)
#define EXIT            0

typedef pair<int,int>   Path;   // first:room1,second:room2
typedef pair<int,Path>  Warp;   // first:-time,second:Path

int                     N,M,total_build_time;
int                     connected[MAX_SIZE];
priority_queue<Warp>    pq;

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int a,b,c;

        cin>>a>>b>>c;
        pq.push(make_pair(-c,make_pair(a,b)));        
    }

    for(int i=1;i<=N;i++)
    {
        int t;

        cin>>t;

        connected[i] = i;
        pq.push(make_pair(-t,make_pair(EXIT,i)));
    }
}

int     find_connection(int r)
{
    int&    ret = connected[r];

    if( r != ret )
    {
        ret = find_connection(ret);
    }

    return  ret;
}

void    build_warp_gate(void)
{
    for(;!pq.empty();pq.pop())
    {
        int build_time = -pq.top().first;
        int room1 = pq.top().second.first;
        int room2 = pq.top().second.second;

        int p1 = find_connection(room1);
        int p2 = find_connection(room2);

        if( p1 == p2 )
        {
            continue;
        }

        total_build_time += build_time;
        connected[max(p1,p2)] = min(p1,p2);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    build_warp_gate();
    
    cout<<total_build_time<<'\n';

    return  0;
}