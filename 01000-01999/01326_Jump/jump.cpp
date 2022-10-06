#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (10000+1)
#define INF         0x7FFFFFFF

int N,offset[MAX_SIZE],dp[MAX_SIZE],a,b;

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>offset[i];
        dp[i] = INF;
    }

    cin>>a>>b;
}

void    jump_to_left(int pos,queue<int>& q)
{
    for(int adj_pos=pos-offset[pos];adj_pos>=1;adj_pos-=offset[pos])
    {
        if( dp[pos]+1 < dp[adj_pos] )
        {
            q.push(adj_pos);
            dp[adj_pos] = dp[pos]+1;
        }
    }
}

void    jump_to_right(int pos,queue<int>& q)
{
    for(int adj_pos=pos+offset[pos];adj_pos<=N;adj_pos+=offset[pos])
    {
        if( dp[pos]+1 < dp[adj_pos] )
        {
            q.push(adj_pos);
            dp[adj_pos] = dp[pos]+1;
        }
    }
}

int     jump(void)
{
    queue<int>  q;

    dp[a] = 0;
    q.push(a);

    for(;!q.empty();q.pop())
    {
        int current_pos = q.front();
        
        if( current_pos == b )
        {
            break;
        }

        jump_to_left(current_pos,q);
        jump_to_right(current_pos,q);
    }

    return  ((dp[b]!=INF)?dp[b]:-1);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<jump()<<'\n';

    return  0;
}