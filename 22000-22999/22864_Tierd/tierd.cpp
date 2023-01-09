#include    <iostream>

using namespace std;

#define MAX_HOUR    24
#define DUMMY_EXP() (void)0

int A,B,C,M,max_to_be_done;

void    dfs(int h,int t,int w)
{
    if( h == MAX_HOUR )
    {
        max_to_be_done = max(max_to_be_done,w);
        return;
    }

    (t+A<=M)?dfs(h+1,t+A,w+B):DUMMY_EXP();
    (t>0)?dfs(h+1,max(t-C,0),w):DUMMY_EXP();
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    cin>>A>>B>>C>>M;
    dfs(0,0,0);

    cout<<max_to_be_done<<'\n';

    return  0;
}