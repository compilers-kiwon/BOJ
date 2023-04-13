#include    <iostream>

using namespace std;

#define MAX_SIZE    (5000+1)
#define DEFAULT_LEN 2

static int  N,A[MAX_SIZE],dp[MAX_SIZE];

#define inc(a,b,c)  ((a)<=(b)&&(b)<=(c))
#define dec(a,b,c)  ((a)>=(b)&&(b)>=(c))

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    return  0;
}

int build_zigzag_numbers(void)
{
    int ret = 0;

    for(int i=3;i<=N;i++)
    {
        if( !inc(A[i-2],A[i-1],A[i])
                && !dec(A[i-2],A[i-1],A[i]) )
        {
            dp[i] = dp[i-1]+1;
        }
        else
        {
            dp[i] = 0;
        }

        ret = max(dp[i],ret);
    }

    return  ret+DEFAULT_LEN;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<build_zigzag_numbers()<<'\n';

    return  0;
}