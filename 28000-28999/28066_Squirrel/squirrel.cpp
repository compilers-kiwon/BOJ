#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000000+1)

static int  N,K,adj[MAX_SIZE];

int init(void)
{
    cin>>N>>K;

    for(int i=1;i<N;i++)
    {
        adj[i] = i+1;
    }

    adj[N] = 1;

    return  0;
}

int simulate(void)
{
    int cur_pos = 1;

    for(;N>=K;N-=(K-1))
    {
        int next_pos,i;

        for(next_pos=cur_pos,i=1;i<=K;
                i++,next_pos=adj[next_pos]);
        
        adj[cur_pos] = next_pos;
        cur_pos = next_pos;
    }

    return  cur_pos;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();
    cout<<simulate()<<'\n';

    return  0;
}