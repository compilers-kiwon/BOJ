#include    <iostream>

using namespace std;

#define MAX_SIZE    (300000+1)
#define INF         0x7FFFFFFF

int D,N,p[MAX_SIZE],r[MAX_SIZE+1];

void    input(void)
{
    cin>>D>>N;

    r[0] = INF;

    for(int i=1;i<=D;i++)
    {
        cin>>r[i];
        r[i] = min(r[i],r[i-1]);
    }

    for(int i=1;i<=N;i++)
    {
        cin>>p[i];
    }
}

int     simulate(void)
{
    int ret;

    for(int p_idx=1,r_idx=D+1;p_idx<=N;p_idx++)
    {
        for(r_idx--;r_idx>=1&&r[r_idx]<p[p_idx];r_idx--);
        
        if( p_idx==N || r_idx==0 )
        {
            ret = r_idx;
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    input();
    cout<<simulate()<<'\n';

    return  0;
}