#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (200+1)

int N,table[MAX_SIZE][MAX_SIZE],parent[MAX_SIZE];

typedef pair<int,int>   Path;   // first:station1,second:station2
typedef pair<int,Path>  Rail;   // first:-cost,second:Path

int     find_parent(int me)
{
    int&    ret = parent[me];

    if( ret != me )
    {
        ret = find_parent(ret);
    }

    return  ret;
}

void    input(void)
{
    cin>>N;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>table[row][col];
        }

        parent[row] = row;
    }
}

void    read_table(queue<Rail>& exist,
                    priority_queue<Rail>& build)
{
    for(int row=1;row<=N;row++)
    {
        for(int col=row;col<=N;col++)
        {
            int&    c = table[row][col];

            if( c == 0 )
            {
                continue;
            }

            if( c < 0 )
            {
                exist.push(make_pair(-c,make_pair(row,col)));
            }
            else
            {
                build.push(make_pair(-c,make_pair(row,col)));
            }
        }
    }
}

int     init_railway(queue<Rail>& exist)
{
    int ret;

    for(ret=0;!exist.empty();exist.pop())
    {
        int cost = exist.front().first;
        int s1 = exist.front().second.first;
        int s2 = exist.front().second.second;

        int p1 = find_parent(s1);
        int p2 = find_parent(s2);

        if( p1 != p2 )
        {
            parent[max(p1,p2)] = min(p1,p2);
        }

        ret += cost;
    }

    return  ret;
}

int     build_railway(queue<Path>& q,
                        priority_queue<Rail>& pq)
{
    int ret;

    for(ret=0;!pq.empty();pq.pop())
    {
        int cost = -pq.top().first;
        int s1 = pq.top().second.first;
        int s2 = pq.top().second.second;

        int p1 = find_parent(s1);
        int p2 = find_parent(s2);

        if( p1 != p2 )
        {
            ret += cost;
            q.push(make_pair(s1,s2));
            parent[max(p1,p2)] = min(p1,p2);
        }
    }

    return  ret;
}

void    print(int total_cost,queue<Path>& q)
{
    cout<<total_cost<<' '<<q.size()<<'\n';

    for(;!q.empty();q.pop())
    {
        int s1 = q.front().first;
        int s2 = q.front().second;

        cout<<s1<<' '<<s2<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<Path>             constructed;
    queue<Rail>             exist;
    priority_queue<Rail>    candidate;

    input();
    read_table(exist,candidate);

    int total_cost = 0;

    total_cost += init_railway(exist);
    total_cost += build_railway(constructed,candidate);

    print(total_cost,constructed);

    return  0;
}