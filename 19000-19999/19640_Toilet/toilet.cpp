#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100000+1)

typedef pair<pair<int,int>,pair<int,int>>   State;

static int  N,M,K;
static queue<State> line[MAX_SIZE];
static priority_queue<State> pq;

#define workload(s) ((s).first.first)
#define desire(s)   ((s).first.second)
#define line_idx(s) (-(s).second.first)
#define order(s)    ((s).second.second)

int input(void)
{
    cin>>N>>M>>K;

    for(int i=0;i<N;i++)
    {
        int H,D,idx;

        cin>>D>>H;
        idx = i%M;

        line[idx].push({{D,H},{-idx,i}});
    }

    for(int i=0;i<M;i++)
    {
        if( !line[i].empty() )
        {
            pq.push(line[i].front());
        }
    }

    return  0;
}

int simulate(void)
{
    int ret;

    for(int i=0;;i++)
    {
        State   s = pq.top();
        
        if( order(s) == K )
        {
            ret = i;
            break;
        }

        pq.pop();
        line[line_idx(s)].pop();
        
        if( !line[line_idx(s)].empty() )
        {
            pq.push(line[line_idx(s)].front());
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}