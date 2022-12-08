#include    <iostream>
#include    <vector>
#include    <queue>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (10000+1)
#define NONE        0

int         N,M,S,E,prev_pos[MAX_SIZE];
bool        visited[MAX_SIZE];
vector<int> connected[MAX_SIZE];

#define init_walk(s,e)  {prev_pos[(s)]=NONE;visited[(e)]=false;}
#define visit(p,q)      {(q).push((p));visited[(p)]=true;}

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int A,B;

        cin>>A>>B;

        connected[A].push_back(B);
        connected[B].push_back(A);
    }

    cin>>S>>E;

    for(int i=1;i<=N;i++)
    {
        sort(connected[i].begin(),connected[i].end());
    }
}

int     get_num_of_visited_pos(void)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        ret += ((visited[i])?1:0);
    }

    return  ret;
}

int     walk(int from,int to)
{
    queue<int>  q;

    init_walk(from,to);visit(from,q);

    for(;!q.empty();q.pop())
    {
        int current_pos = q.front();

        if( current_pos == to )
        {
            break;
        }

        for(int i=0;i<connected[current_pos].size();i++)
        {
            int&    adj_pos = connected[current_pos][i];

            if( visited[adj_pos] == false )
            {
                visit(adj_pos,q);
                prev_pos[adj_pos] = current_pos;
            }
        }
    }

    fill(&visited[1],&visited[N+1],false);

    for(int p=to;p!=NONE;p=prev_pos[p])
    {
        visited[p] = true;
    }

    return  get_num_of_visited_pos()-1;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<walk(S,E)+walk(E,S)<<'\n';

    return  0;
}