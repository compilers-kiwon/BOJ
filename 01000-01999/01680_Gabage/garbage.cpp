#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000+1)

typedef pair<int,int>   Garbage;  // first:pos,second:weight

int W,N;

void    input(queue<Garbage>& garbage_q)
{
    cin>>W>>N;

    for(int i=1;i<=N;i++)
    {
        Garbage g;

        cin>>g.first>>g.second;
        garbage_q.push(g);
    }
}

int     collect_garbage(queue<Garbage>& garbage_q)
{
    int ret,last_pos,current_weight;

    for(ret=last_pos=current_weight=0;!garbage_q.empty();)
    {
        int collected_pos = garbage_q.front().first;
        int collected_weight = garbage_q.front().second;

        last_pos = collected_pos;
        current_weight += collected_weight;

        if( current_weight >= W )
        {
            if( current_weight == W )
            {
                garbage_q.pop();
            }

            ret += last_pos*2;
            last_pos = current_weight = 0;
        }
        else
        {
            garbage_q.pop();
        }
    }

    if( current_weight != 0 )
    {
        ret += last_pos*2;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        queue<Garbage>  garbage_q;

        input(garbage_q);
        cout<<collect_garbage(garbage_q)<<'\n';
    }

    return  0;
}