#include    <iostream>

using namespace std;

#define MAX_SIZE    100000
#define MAX_NUM     3
#define TBD         -1
#define MOD(n)      ((n)%1000000009)

static int  dp[MAX_SIZE+1][MAX_NUM+1];

int get_dp(int current_num,int prev_num)
{
    if( current_num <= 0 )
    {
        return  (current_num==0)?1:0;
    }

    int&    ret = dp[current_num][prev_num];

    if( ret != TBD )
    {
        return  ret;
    }

    ret = 0;

    for(int i=1;i<=MAX_NUM;i++)
    {
        if( i == prev_num )
        {
            continue;
        }

        ret = MOD(ret+get_dp(current_num-i,i));
    }
    
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=1;i<=MAX_SIZE;i++)
    {
        fill(&dp[i][0],&dp[i][MAX_NUM+1],TBD);
    }

    for(int i=1;i<=MAX_SIZE;i++)
    {
        get_dp(i,0);
    }

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int num;

        cin>>num;
        cout<<get_dp(num,0)<<'\n';
    }

    return  0;
}